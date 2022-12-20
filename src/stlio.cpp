#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include "stlio.h"

namespace stlio {

	using namespace std;

	static inline bool IsAsciiFileFormat(istream& in, bool& isAscii, string& err)
	{
		char chars[20];
		in.read(chars, 20);
		std::streamsize count = in.gcount();
		if (!in)
		{
			err = "failed to identify STL file format";
			return false;
		}

		string buffer(chars, count);
		transform(buffer.begin(), buffer.end(), buffer.begin(), ::tolower);

		//isAscii = buffer.find("solid") != string::npos
		//	&& buffer.find("facet") != string::npos
		//	&& buffer.find("normal") != string::npos;

		isAscii = buffer.find("solid") != string::npos;

		return true;
	}

	static bool HandleSolid(bool& flag, const string& line, StlIn& stlin, string& err)
	{
		if (!flag)
		{
			string name = line.size() > 6 ? line.substr(6) : "";
			if (!stlin.Initialise(name, -1))
			{
				err = "failed to initialise STL model";
				return false;
			}
			flag = true;
		}
		return true;
	}

	static bool HandleEndSolid(bool& flag, const string& line, StlIn& stlin, string& err)
	{
		if (!flag)
		{
			string name = line.size() > 9 ? line.substr(9) : "";
			if (!stlin.Finalise(name))
			{
				err = "failed to finalise STL model";
				return false;
			}
			flag = true;
		}
		return true;
	}

	template <class _Elem, class _Traits, class _Alloc>
	basic_istream<_Elem, _Traits>& getline(basic_istream<_Elem, _Traits>& _Istr,
		basic_string<_Elem, _Traits, _Alloc>& _Str,
		const _Elem _Delim1,
		const _Elem _Delim2,
		const _Elem _Delim3 = 0,
		const _Elem _Delim4 = 0)
	{
		// get characters into string, discard delimiters
		using _Myis = basic_istream<_Elem, _Traits>;

		typename _Myis::iostate _State = _Myis::goodbit;
		bool _Changed = false;
		const typename _Myis::sentry _Ok(_Istr, true);

		if (_Ok)
		{
			// state okay, extract characters
			try
			{
				_Str.erase();
				const typename _Traits::int_type _Metadelim1 = _Traits::to_int_type(_Delim1);
				const typename _Traits::int_type _Metadelim2 = _Traits::to_int_type(_Delim2);
				const typename _Traits::int_type _Metadelim3 = _Traits::to_int_type(_Delim3);
				const typename _Traits::int_type _Metadelim4 = _Traits::to_int_type(_Delim4);
				typename _Traits::int_type _Meta = _Istr.rdbuf()->sgetc();

				for (;; _Meta = _Istr.rdbuf()->snextc())
				{
					if (_Traits::eq_int_type(_Traits::eof(), _Meta))
					{
						// end of file, quit
						_State |= _Myis::eofbit;
						break;
					}
					else if (_Traits::eq_int_type(_Meta, _Metadelim1)
						|| _Traits::eq_int_type(_Meta, _Metadelim2)
						|| _Traits::eq_int_type(_Meta, _Metadelim3)
						|| _Traits::eq_int_type(_Meta, _Metadelim4))
					{
						// got a delimiter, discard it and quit
						_Changed = true;
						_Istr.rdbuf()->sbumpc();
						break;
					}
					else if (_Str.max_size() <= _Str.size())
					{
						// string too large, quit
						_State |= _Myis::failbit;
						break;
					}
					else {
						// got a character, add it to string
						_Str += _Traits::to_char_type(_Meta);
						_Changed = true;
					}
				}
			}
			catch (...)
			{
				_Istr.setstate(_Myis::badbit); /* set badbit and rethrow */
			}
		}

		if (!_Changed)
		{
			_State |= _Myis::failbit;
		}

		_Istr.setstate(_State);
		return _Istr;
	}

	static bool ReadStlFile_ASCII(istream& in, StlIn& stlin, string& err)
	{
		string buffer;
		vector<string> tokens;
		bool solid = false;
		bool endsolid = false;
		int lineCount = 1;
		int maxNumTokens = 0;
		Facet facet;
		size_t numFaceVrts = 0;

		while (!(in.eof() || in.fail()))
		{
			getline(in, buffer, in.widen('\r'), in.widen('\n'));

			istringstream line(buffer);
			int tokenCount = 0;
			while (!(line.eof() || line.fail()))
			{
				if (tokenCount >= maxNumTokens)
				{
					maxNumTokens = tokenCount + 1;
					tokens.resize(maxNumTokens);
				}
				line >> tokens[tokenCount];
				++tokenCount;
			}

			if (tokenCount > 0)
			{
				const string& tok = tokens[0];
				if (tok.compare("vertex") == 0)
				{
					if (tokenCount < 4)
					{
						stringstream s;
						s << "vertex not specified correctly in line " << lineCount;
						err = s.str();
						return false;
					}

					float* v = &facet.v[numFaceVrts].x;

					for (size_t i = 0; i < 3; ++i)
					{
						v[i] = static_cast<float>(atof(tokens[i + 1].c_str()));
					}

					++numFaceVrts;
				}
				else if (tok.compare("facet") == 0)
				{
					if (tokenCount < 5)
					{
						stringstream s;
						s << "facet not specified correctly in line " << lineCount;
						err = s.str();
						return false;
					}

					if (tokens[1].compare("normal") != 0)
					{
						stringstream s;
						s << "missing normal specifier in line " << lineCount;
						err = s.str();
						return false;
					}

					if (!HandleSolid(solid, buffer, stlin, err))
						return false;

					float* n = &facet.n.x;

					for (size_t i = 0; i < 3; ++i)
					{
						n[i] = static_cast<float>(atof(tokens[i + 2].c_str()));
					}

					numFaceVrts = 0;
				}
				else if (tok.compare("outer") == 0)
				{
					if ((tokenCount < 2) || (tokens[1].compare("loop") != 0))
					{
						stringstream s;
						s << "expecting outer loop in line " << lineCount;
						err = s.str();
						return false;
					}
				}
				else if (tok.compare("endfacet") == 0)
				{
					if (numFaceVrts != 3)
					{
						stringstream s;
						s << "bad number of vertices specified for face in line " << lineCount;
						err = s.str();
						return false;
					}

					if (!stlin.PushFacet(facet))
					{
						stringstream s;
						s << "failed to add facet on line " << lineCount;
						err = s.str();
						return false;
					}
				}
				else if (tok.compare("solid") == 0)
				{
					if (!HandleSolid(solid, buffer, stlin, err))
						return false;
				}
				else if (tok.compare("endsolid") == 0)
				{
					if (!HandleEndSolid(endsolid, buffer, stlin, err))
						return false;
				}
			}

			lineCount++;
		}

		if (!HandleEndSolid(endsolid, buffer, stlin, err))
			return false;

		return true;
	}

	static bool ReadStlFile_BINARY(istream& in, StlIn& stlin, string& err)
	{
		// Example: 6884 bytes
		//	80 header
		//	4 num facets
		//	50 bytes per facet
		// => 6800/50 = 136 facets
		char header[81];
		for (int i = 0; i < sizeof(header); ++i)
			header[i] = 0;
		in.read(header, 80);
		if (!in)
		{
			err = "error while parsing binary stl header";
			return false;
		}

		unsigned int numTris = 0;
		in.read((char*)&numTris, 4);
		if (!in)
		{
			err = "failed to determine number of triangles in binary stl file";
			return false;
		}

		if (!stlin.Initialise(header, numTris))
		{
			err = "failed to initialise STL model";
			return false;
		}

		Facet facet;

		for (unsigned int tri = 0; tri < numTris; ++tri)
		{
			in.read((char*)&facet, 50);
			if (!in)
			{
				err = "failed to read facet data in binary stl file";
				return false;
			}

			if (!stlin.PushFacet(facet))
			{
				stringstream s;
				s << "failed to add facet #" << tri;
				err = s.str();
				return false;
			}
		}

		if (!stlin.Finalise(header))
		{
			err = "failed to finalise STL model";
			return false;
		}

		return true;
	}

	bool ReadStlFile(istream& in, StlIn& stlin, string& err)
	{
		bool isAscii;
		if (!IsAsciiFileFormat(in, isAscii, err))
			return false;

		in.seekg(0, ios_base::beg);
		if (!in)
		{
			err = "failed to seek to beginning of stream";
			return false;
		}

		if (isAscii)
			return ReadStlFile_ASCII(in, stlin, err);
		else
			return ReadStlFile_BINARY(in, stlin, err);
	}

	std::ostream& operator<<(std::ostream& stream, const Vec3& v)
	{
		return stream << v.x << " " << v.y << " " << v.z;
	}

	bool WriteAsciiStlFile(ostream& out, StlOut& stlout, string& err)
	{
		string name;
		int count;
		if (!stlout.Initialise(name, count))
		{
			err = "failed to initialise output to STL";
			return false;
		}

		out << std::scientific;
		out << "solid " << name << endl;

		Facet facet;
		for (int index = 0; index < count; ++index)
		{
			if (!stlout.GetFacet(index, facet))
			{
				err = "failed to retrieve facet from model";
				return false;
			}

			out << "facet normal " << facet.n << endl;
			out << "outer loop" << endl;
			out << "vertex " << facet.v[0] << endl;
			out << "vertex " << facet.v[1] << endl;
			out << "vertex " << facet.v[2] << endl;
			out << "endloop" << endl;
			out << "endfacet" << endl;
		}

		out << "endsolid " << name << endl;

		return true;
	}

	bool WriteBinaryStlFile(ostream& out, StlOut& stlout, string& err)
	{
		string name;
		int count;
		if (!stlout.Initialise(name, count))
		{
			err = "failed to initialise output to STL";
			return false;
		}

		char header[80];
		for (int i = 0; i < sizeof(header); ++i)
			header[i] = 0;
		name.copy(header, sizeof(header));

		out.write(header, sizeof(header));
		if (!out)
		{
			err = "failed to write header to STL";
			return false;
		}

		out.write((char*)&count, 4);
		if (!out)
		{
			err = "failed to write number of triangles to binary stl file";
			return false;
		}

		Facet facet;
		for (int index = 0; index < count; ++index)
		{
			if (!stlout.GetFacet(index, facet))
			{
				err = "failed to retrieve facet from model";
				return false;
			}

			out.write((char*)&facet, 50);
			if (!out)
			{
				err = "failed to write facet data to binary stl file";
				return false;
			}
		}

		return true;
	}

}

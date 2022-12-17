#pragma once

#include <istream>
#include <ostream>

namespace stlio {

	struct Vec3
	{
		float	x;
		float	y;
		float	z;
	};

	struct Facet
	{
		Vec3	n;
		Vec3	v[3];
		char	extra[2];
	};

	class StlIn
	{
	public:
		virtual ~StlIn() {}

		virtual bool Initialise(const std::string& name, int triangleCount) { return true; }

		virtual bool PushFacet(const Facet& facet) = 0;

		virtual bool Finalise(const std::string& name) { return true; }
	};

	class StlOut
	{
	public:
		virtual ~StlOut() {}

		virtual bool Initialise(std::string& name, int& triangleCount) = 0;

		virtual bool GetFacet(int index, Facet& facet) = 0;
	};

	bool ReadStlFile(std::istream& in, StlIn& stlin, std::string& err);

	bool WriteAsciiStlFile(std::ostream& out, StlOut& stlout, std::string& err);

	bool WriteBinaryStlFile(std::ostream& out, StlOut& stlout, std::string& err);

}

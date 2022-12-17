#pragma once

#include <string>

#include "stlio.h"

#if defined(WIN32) || defined(_WIN32)
#define PATH_SEPARATOR R"(\)"
#else
#define PATH_SEPARATOR R"(/)"
#endif

inline std::string data_path(const std::string& path)
{
	auto result = TEST_DATA_DIR PATH_SEPARATOR + path;
	return result;
}

inline stlio::Facet _facet(const stlio::Vec3& n,
	const stlio::Vec3& v0,
	const stlio::Vec3& v1,
	const stlio::Vec3& v2)
{
	stlio::Facet f;
	f.n = n;
	f.v[0] = v0;
	f.v[1] = v1;
	f.v[2] = v2;

	return f;
}

inline stlio::Facet _facet(const stlio::Vec3& v0,
	const stlio::Vec3& v1,
	const stlio::Vec3& v2)
{
	stlio::Vec3 n, u, v;

	u.x = v1.x - v0.x;
	u.y = v1.y - v0.y;
	u.z = v1.z - v0.z;

	v.x = v2.x - v0.x;
	v.y = v2.y - v0.y;
	v.z = v2.z - v0.z;

	n.x = u.y * v.z - u.z * v.y;
	n.y = u.z * v.x - u.x * v.z;
	n.z = u.x * v.y - u.y * v.x;

	return _facet(n, v0, v1, v2);
}

inline stlio::Vec3 _v(float x, float y, float z)
{
	stlio::Vec3 v;
	v.x = x;
	v.y = y;
	v.z = z;
	return v;
}

void ReadDataStl(stlio::StlIn& stlin, const std::string& path);

void ReadStl(stlio::StlIn& stlin, const std::string& path);

void WriteStl(stlio::StlOut& stlout, std::string& path, bool ascii);

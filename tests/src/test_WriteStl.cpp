#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#include "utils.h"
#include "StlInMock.h"
#include "StlOutMock.h"
#include "asserts.h"
#include "geometry.h"

namespace {

    TEST_CASE("WriteAsciiStl", "[STL]")
    {
        SECTION("ascii 20mmbox")
        {
            StlOutMock stlout;
            Geometry::box20mm(stlout.Facets);

            std::string path;
            WriteStl(stlout, path, true);

            StlInMock stlin;
            ReadStl(stlin, path);

            std::remove(path.c_str());

            Assert::is20mmbox(stlin);
        }
    }

    TEST_CASE("WriteBinaryStl", "[STL]")
    {
        SECTION("binary 20mmbox")
        {
            StlOutMock stlout;
            Geometry::box20mm(stlout.Facets);

            std::string path;
            WriteStl(stlout, path, false);

            StlInMock stlin;
            ReadStl(stlin, path);

            std::remove(path.c_str());

            Assert::is20mmbox(stlin);
        }
    }
}

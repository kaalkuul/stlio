#include <catch2/catch_test_macros.hpp>

#include "utils.h"
#include "StlInMock.h"
#include "asserts.h"

namespace {

    TEST_CASE("ReadDataStlFile", "[STL]")
    {
        SECTION("stl/ascii/20mmbox-CR.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/ascii/20mmbox-CR.stl");

            Assert::is20mmbox(stlin);
        }

        SECTION("stl/ascii/20mmbox-CRLF.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/ascii/20mmbox-CRLF.stl");

            Assert::is20mmbox(stlin);
        }

        SECTION("stl/ascii/20mmbox-LF.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/ascii/20mmbox-LF.stl");

            Assert::is20mmbox(stlin);
        }

        SECTION("stl/ascii/20mmbox-nonstandard.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/ascii/20mmbox-nonstandard.stl");

            stlin.Facets[8].n.x = -1.000000e+00f;
            stlin.Facets[8].n.y = 0.000000e+00f;
            stlin.Facets[8].n.z = 0.000000e+00f;

            Assert::is20mmbox(stlin);
        }

        SECTION("stl/binary/20mmbox.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/binary/20mmbox.stl");

            Assert::is20mmbox(stlin);
        }

        SECTION("stl/binary/shape.stl")
        {
            StlInMock stlin;
            ReadDataStl(stlin, "stl/binary/shape.stl");

            Assert::isShape(stlin);
        }
    }
}

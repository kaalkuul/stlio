#pragma once

#include <catch2/catch_test_macros.hpp>

#include "asserts.h"

namespace Assert
{
    void equals(float value, float expected, float tolerance)
    {
        REQUIRE(fabs(value - expected) <= tolerance);
    }

    void is20mmbox(const StlInMock& stlin)
    {
        REQUIRE(stlin.Facets.size() == 12);
        Assert::equals(stlin.Facets[0].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].n.y, -0.000000e+00f);
        Assert::equals(stlin.Facets[0].n.z, -1.000000e+00f);
        Assert::equals(stlin.Facets[0].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[0].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[0].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].v[1].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[0].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].v[1].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[0].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[1].n.x, -0.000000e+00f);
        Assert::equals(stlin.Facets[1].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].n.z, -1.000000e+00f);
        Assert::equals(stlin.Facets[1].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[1].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[1].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].v[1].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[1].v[2].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[1].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[2].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[2].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[2].n.z, 1.000000e+00f);
        Assert::equals(stlin.Facets[2].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[2].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[2].v[0].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[2].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[2].v[1].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[2].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[2].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[2].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[2].v[2].z, 2.000000e+01f);

        Assert::equals(stlin.Facets[3].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[3].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[3].n.z, 1.000000e+00f);
        Assert::equals(stlin.Facets[3].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[3].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[3].v[0].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[3].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[3].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[3].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[3].v[2].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[3].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[3].v[2].z, 2.000000e+01f);

        Assert::equals(stlin.Facets[4].n.x, 1.000000e+00f);
        Assert::equals(stlin.Facets[4].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[4].n.z, -0.000000e+00f);
        Assert::equals(stlin.Facets[4].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[4].v[1].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[1].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[2].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[4].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[4].v[2].z, 2.000000e+01f);

        Assert::equals(stlin.Facets[5].n.x, 1.000000e+00f);
        Assert::equals(stlin.Facets[5].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[5].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[5].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[5].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[5].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[5].v[1].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[5].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[5].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[5].v[2].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[5].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[5].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[6].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].n.y, -1.000000e+00f);
        Assert::equals(stlin.Facets[6].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[6].v[0].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[1].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[6].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[6].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[6].v[2].z, 2.000000e+01f);

        Assert::equals(stlin.Facets[7].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].n.y, -1.000000e+00f);
        Assert::equals(stlin.Facets[7].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[7].v[0].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[7].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[2].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[7].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[8].n.x, -1.000000e+00f);
        Assert::equals(stlin.Facets[8].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[0].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[0].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[1].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[8].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[8].v[2].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[8].v[2].z, 2.000000e+01f);

        Assert::equals(stlin.Facets[9].n.x, -1.000000e+00f);
        Assert::equals(stlin.Facets[9].n.y, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[0].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[0].y, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[0].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[1].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[9].v[1].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[9].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[9].v[2].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[9].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[10].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[10].n.y, 1.000000e+00f);
        Assert::equals(stlin.Facets[10].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[10].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[0].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[1].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[1].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[1].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[10].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[10].v[2].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[10].v[2].z, 0.000000e+00f);

        Assert::equals(stlin.Facets[11].n.x, 0.000000e+00f);
        Assert::equals(stlin.Facets[11].n.y, 1.000000e+00f);
        Assert::equals(stlin.Facets[11].n.z, 0.000000e+00f);
        Assert::equals(stlin.Facets[11].v[0].x, 2.000000e+01f);
        Assert::equals(stlin.Facets[11].v[0].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[11].v[0].z, 2.000000e+01f);
        Assert::equals(stlin.Facets[11].v[1].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[11].v[1].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[11].v[1].z, 0.000000e+00f);
        Assert::equals(stlin.Facets[11].v[2].x, 0.000000e+00f);
        Assert::equals(stlin.Facets[11].v[2].y, 2.000000e+01f);
        Assert::equals(stlin.Facets[11].v[2].z, 2.000000e+01f);
    }

    void isShape(const StlInMock& stlin)
    {
        REQUIRE(stlin.Facets.size() == 136);
    }
}

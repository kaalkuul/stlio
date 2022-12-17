#pragma once

#include "StlInMock.h"

namespace Assert
{
    void equals(float value, float expected, float tolerance = 1e-6f);

    void is20mmbox(const StlInMock& stlin);

    void isShape(const StlInMock& stlin);
}

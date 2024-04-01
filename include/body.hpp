#pragma once

#include <array>
#include <string>

struct Body
{
    std::string name{"mass"};
    double mass{1.0};
    std::array<double, 3> position{0.0, 0.0, 0.0};
    std::array<double, 3> velocity{0.0, 0.0, 0.0};
};
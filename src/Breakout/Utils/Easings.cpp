#include "pch.h"

namespace Tweening
{
    
    float easeInSine(float x)
    {
        return static_cast<float>(1 - std::cos((x * std::numbers::pi) / 2));
    }

    float easeInOutSine(float x)
    {
        return  static_cast<float>(-(std::cos(std::numbers::pi * x) - 1) / 2);
    }
    
}


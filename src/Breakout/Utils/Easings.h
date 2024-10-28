#pragma once

namespace Tweening
{
    
    enum Easings
    {
        EaseInSine,
        EaseInOutSine
    };

    float easeInSine(float x);
    float easeInOutSine(float x);
    
}


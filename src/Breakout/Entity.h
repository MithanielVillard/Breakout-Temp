#pragma once
#include "Utils/Easings.h"

class Entity : public sf::Transformable
{
public:
    Entity(sf::Vector2f pos);
    
    virtual void Update(float dt) = 0;

    void TweenPosition(sf::Vector2f target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenPosition(sf::Vector2f target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);

    void TweenScale(sf::Vector2f target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenScale(sf::Vector2f target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);

    void TweenRotation(float target, float duration, Tweening::Easings easing = Tweening::EaseInSine);
    void TweenRotation(float target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);
};

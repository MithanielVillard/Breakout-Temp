#include "pch.h"

#include "Utils/Tweeners/RotationTweener.h"

Entity::Entity(sf::Vector2f pos)
{
    setPosition(pos);
}

void Entity::TweenPosition(sf::Vector2f target, float duration, Tweening::Easings easing)
{
    new PositionTweener(this, target, duration, easing);
}

void Entity::TweenPosition(sf::Vector2f target, float duration, void(*onComplete)(), Tweening::Easings easing)
{
    new PositionTweener(this, target, duration, onComplete, easing);
}

void Entity::TweenScale(sf::Vector2f target, float duration, Tweening::Easings easing)
{
    new ScaleTweener(this, target, duration, easing);
}

void Entity::TweenScale(sf::Vector2f target, float duration,  void(*onComplete)(), Tweening::Easings easing)
{
    new ScaleTweener(this, target, duration, onComplete, easing);
}

void Entity::TweenRotation(float target, float duration, Tweening::Easings easing)
{
    new RotationTweener(this, target, duration, easing);
}

void Entity::TweenRotation(float target, float duration, void (*onComplete)(), Tweening::Easings easing)
{
    new RotationTweener(this, target, duration, onComplete, easing);
}





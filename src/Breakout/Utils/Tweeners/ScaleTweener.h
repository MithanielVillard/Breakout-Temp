#pragma once
#include "Tweener.h"

class ScaleTweener : Tweener
{
public:
    ScaleTweener(Entity* entity, const sf::Vector2f& target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    ScaleTweener(Entity* entity, const sf::Vector2f& target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);

    void Update(float dt) override;

private:
    sf::Vector2f m_startScale;
    sf::Vector2f m_targetScale;
};

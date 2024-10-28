#pragma once
#include "Tweener.h"

class PositionTweener : Tweener
{
public:
    PositionTweener(Entity* entity, const sf::Vector2f& target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    PositionTweener(Entity* entity, const sf::Vector2f& target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);

    void Update(float dt) override;

private:
    sf::Vector2f m_startPosition;
    sf::Vector2f m_targetPosition;
};

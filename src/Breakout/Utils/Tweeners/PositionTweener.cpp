#include "pch.h"
#include "PositionTweener.h"

PositionTweener::PositionTweener(Entity* entity, const sf::Vector2f& target, float duration, Tweening::Easings easing) :
    Tweener(entity, easing, duration),
    m_startPosition(entity->getPosition()),
    m_targetPosition(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

PositionTweener::PositionTweener(Entity* entity, const sf::Vector2f& target, float duration, void(*onComplete)(), Tweening::Easings easing) :
    Tweener(entity, easing, duration, onComplete),
    m_startPosition(entity->getPosition()),
    m_targetPosition(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

void PositionTweener::Update(const float dt)
{
    m_entity->setPosition( m_startPosition + ( m_easingFunction(m_elapsedTime / m_duration) * (m_targetPosition - m_startPosition)));
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        Game::getTweeningSystem().RemoveTweener(this);
        delete this;
    }
}

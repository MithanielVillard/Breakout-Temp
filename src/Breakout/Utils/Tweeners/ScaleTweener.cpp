#include "pch.h"
#include "ScaleTweener.h"

ScaleTweener::ScaleTweener(Entity* entity, const sf::Vector2f& target, float duration, Tweening::Easings easing) :
    Tweener(entity, easing, duration),
    m_startScale(entity->getScale()),
    m_targetScale(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

ScaleTweener::ScaleTweener(Entity* entity, const sf::Vector2f& target, float duration, void(*onComplete)(), Tweening::Easings easing) :
    Tweener(entity, easing, duration, onComplete),
    m_startScale(entity->getScale()),
    m_targetScale(target)
{
    Game::getTweeningSystem().AddTweener(this);
}

void ScaleTweener::Update(const float dt)
{
    m_entity->setScale( m_startScale + ( m_easingFunction(m_elapsedTime / m_duration) * (m_targetScale - m_startScale)));
    m_elapsedTime += dt;
    if (m_elapsedTime >= m_duration)
    {
        if (m_onComplete != nullptr) (*m_onComplete)();
        Game::getTweeningSystem().RemoveTweener(this);
        delete this;
    }
}
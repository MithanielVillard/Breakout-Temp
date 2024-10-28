#pragma once
#include "../Easings.h"

class Entity;

class Tweener
{
public:
    Tweener(Entity* entity, Tweening::Easings easing, float duration, void(*m_onComplete)() = nullptr);
    virtual ~Tweener() = default;
    
    virtual void Update(float dt) = 0;

protected:
    Entity* m_entity;
    float (*m_easingFunction)(float);
    float m_duration;
    float m_elapsedTime = 0;

    void(*m_onComplete)();
};

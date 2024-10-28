#include "pch.h"
#include "Tweener.h"

Tweener::Tweener(Entity* entity, Tweening::Easings easing, float duration, void(*m_onComplete)()) :
    m_entity(entity),
    m_duration(duration),
    m_onComplete(m_onComplete)
{
    switch (easing)
    {
    case Tweening::EaseInSine:
        m_easingFunction = Tweening::easeInSine;
    case Tweening::EaseInOutSine:
        m_easingFunction = Tweening::easeInOutSine;
    }
}


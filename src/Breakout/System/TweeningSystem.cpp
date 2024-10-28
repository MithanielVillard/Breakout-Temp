#include "pch.h"
#include "TweeningSystem.h"

void TweeningSystem::Tween(const float dt) const
{
    for(Tweener* tweener : m_tweeners)
    {
        tweener->Update(dt);
    }
}

void TweeningSystem::AddTweener(Tweener* tween)
{
    m_tweeners.push_back(tween);
}

void TweeningSystem::RemoveTweener(const Tweener* tween)
{
    auto it = std::find(m_tweeners.begin(), m_tweeners.end(), tween);
    if (*it != nullptr) m_tweeners.erase(it);
}



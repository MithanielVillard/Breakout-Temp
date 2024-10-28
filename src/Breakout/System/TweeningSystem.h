#pragma once

class Tweener;

class TweeningSystem
{
public:
    TweeningSystem() = default;
    ~TweeningSystem() = default;

    void Tween(float dt) const;

    void AddTweener(Tweener* tween);
    void RemoveTweener(const Tweener* tween);
private:
    std::vector<Tweener*> m_tweeners;
};

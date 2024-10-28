#pragma once

class RotationTweener : Tweener
{
public:
    RotationTweener(Entity* entity, float target, float duration,Tweening::Easings easing = Tweening::EaseInSine);
    RotationTweener(Entity* entity, float target, float duration, void(*onComplete)(), Tweening::Easings easing = Tweening::EaseInSine);

    void Update(float dt) override;

private:
    float m_startRotation;
    float m_targetRotation;
    
};

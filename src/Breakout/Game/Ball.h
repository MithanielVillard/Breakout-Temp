#pragma once

namespace Breakout
{
    
    class Ball : public Entity, public Renderable
    {
    public:
        Ball();

        void Update(float dt) override;
    };
    
}

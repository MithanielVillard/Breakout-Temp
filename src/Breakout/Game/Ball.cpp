#include "pch.h"
#include "Ball.h"

namespace Breakout
{
    Ball::Ball() : Entity(sf::Vector2f(0, 0)), Renderable( "Ball.png", "Shaders/Bloom.frag",this) {}

    void Ball::Update(float dt)
    {
        
    }
    

}

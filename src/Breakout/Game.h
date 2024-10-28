#pragma once

#include "System/RenderSystem.h"
#include "System/TweeningSystem.h"

//Window Property---------------
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720
#define WINDOW_TITLE "Breakout"
//-------------------------------

class Game
{
public:
    static sf::RenderWindow& getWindow();

    //systems
    static RenderSystem& getRenderSystem();
    static TweeningSystem& getTweeningSystem();

private:
    Game();
    ~Game() = default;
    
    //singleton instance
    static Game& instance()
    {
        static Game instance;
        return instance;
    }

private:
    sf::RenderWindow m_window;
    RenderSystem m_renderSystem;
    TweeningSystem m_tweeningSystem;
};

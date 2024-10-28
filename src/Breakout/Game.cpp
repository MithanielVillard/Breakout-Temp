#include "pch.h"
#include "Game.h"

Game::Game() :
m_window(sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_TITLE, sf::Style::Titlebar, sf::ContextSettings(0, 0, 8)))
{
}

sf::RenderWindow& Game::getWindow()
{
    return instance().m_window;
}

RenderSystem& Game::getRenderSystem()
{
    return instance().m_renderSystem;
}

TweeningSystem& Game::getTweeningSystem()
{
    return instance().m_tweeningSystem;
}





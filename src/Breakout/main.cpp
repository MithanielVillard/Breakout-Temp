#include "pch.h"
#include "main.h"

#include "Game/Ball.h"

int main()
{
	sf::RenderWindow& window = Game::getWindow();
	RenderSystem& renderer = Game::getRenderSystem();
	TweeningSystem& tweenSystem = Game::getTweeningSystem();

	sf::Clock clock;
	
	Breakout::Ball ball;
	ball.setScale(0.05f, 0.05f);
	ball.setPosition(150, 100);
	
	ball.TweenPosition(sf::Vector2f(200, 300), 3.0f, [](){ std::cout << "finished"; }, Tweening::EaseInOutSine);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear(sf::Color(72,72,72,255));

		//systems update
		renderer.Render();
		tweenSystem.Tween(clock.restart().asSeconds());
			
		window.display();
	}
}

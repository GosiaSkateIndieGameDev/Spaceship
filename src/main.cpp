#include <SFML/Graphics.hpp>
#include "../include/Level.hpp"
#include "../include/Player.hpp"

int main()
{
	//Screen dimensions
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 800;

	//Create game window
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Spaceship");

	Level level;
	std::unique_ptr<Player> player = std::make_unique<Player>();

	level.Load("BgTex.png");

	sf::Clock clock;

	bool isGameOver = false;
	while (window.isOpen())
	{
		float dt = clock.restart().asSeconds();
		
		sf::Event ev;
		while (window.pollEvent(ev))
		{
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		//Update everything
		level.Update(dt);
		player->Update(dt);
		player->UpdateWindowCollision(window);

		window.clear();

		level.Draw(window);
		player->Draw(window);
		
		window.display();
	}

	return 0;
}
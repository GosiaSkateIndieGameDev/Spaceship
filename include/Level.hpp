#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Level
{
public:
	Level();

	void Load(std::string filePath);
	void Update(float dt);
	void Draw(sf::RenderWindow &win);

private:
	sf::Texture m_bgTex;
	sf::Sprite m_bgSprite;
};
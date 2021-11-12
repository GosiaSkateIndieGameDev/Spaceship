#pragma once
#include <string>
#include <SFML/Graphics.hpp>

class Player
{
public:
	Player();

	void Load(std::string filePath);
	void Update(float dt);
	void UpdateWindowCollision(sf::RenderWindow& win);
	void Draw(sf::RenderWindow &win);

private:
	sf::RectangleShape m_rectShape;
	sf::Vector2f m_size;

	float m_speed;
};
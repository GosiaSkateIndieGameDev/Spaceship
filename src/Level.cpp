#include "../include/Level.hpp"

Level::Level()
{

}

void Level::Load(std::string filePath)
{
	m_bgTex.loadFromFile("Data/Texture/" + filePath);
	m_bgSprite.setTexture(m_bgTex);
}

void Level::Update(float dt)
{}

void Level::Draw(sf::RenderWindow& win)
{
	win.draw(m_bgSprite);
}
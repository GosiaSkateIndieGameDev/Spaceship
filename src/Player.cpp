#include "../include/Player.hpp"

Player::Player()
{
	m_size = sf::Vector2f(25.0f, 25.0f);
	m_speed = 100.0f;
	m_rectShape.setSize(m_size);
	m_rectShape.setFillColor(sf::Color(0, 255, 0));
}

void Player::Load(std::string filePath)
{}

void Player::Update(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_rectShape.move(0.0f, -m_speed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_rectShape.move(0.0f, m_speed * dt);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		m_rectShape.move(-m_speed * dt, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_rectShape.move(m_speed * dt, 0.0f);
	}
}

void Player::UpdateWindowCollision(sf::RenderWindow& win)
{
	if (m_rectShape.getSize().x < 0)
	{
		m_rectShape.setPosition(0.0f, m_rectShape.getPosition().y);
	}
	if (m_rectShape.getPosition().x + m_rectShape.getSize().x > win.getSize().x)
	{
		m_rectShape.setPosition(win.getSize().x - m_rectShape.getSize().x, m_rectShape.getSize().y);
	}

	if (m_rectShape.getSize().y < 0)
	{
		m_rectShape.setPosition(m_rectShape.getSize().x, 0.0f);
	}
	if (m_rectShape.getPosition().y + m_rectShape.getSize().y > win.getSize().y)
	{
		m_rectShape.setPosition(m_rectShape.getPosition().x, win.getSize().y - m_rectShape.getSize().y);
	}
}

void Player::Draw(sf::RenderWindow& win)
{
	win.draw(m_rectShape);
}
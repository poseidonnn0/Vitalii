#include "Rectangle.hpp"
#include <iostream>

namespace VK
{
	Rectangle::Rectangle(int x, int y, int size_X, int size_Y, float velocity)
	{
		m_x = x;
		m_y = y;
		sizeX = size_X;
		sizeY = size_Y;
		m_velocity = velocity;
		m_shape = new sf::RectangleShape(sf::Vector2f(sizeX, sizeY));
		m_shape->setFillColor(sf::Color::Green);
		m_shape->setOrigin(0, 0);
		m_shape->setPosition(m_x, m_y);
	}
	
	Rectangle::~Rectangle()
	{
		delete m_shape;
	}

	sf::RectangleShape* Rectangle::Get() { return m_shape; }

	void Rectangle::Move()
	{
		if (m_y > 0)
		{
			m_y -= m_velocity;
			m_shape->setPosition(m_x, m_y);
		}
		else
		{
			m_y = 0;
			m_shape->setPosition(m_x, m_y);
		}
	}


	int Rectangle::GetY() { return m_y; }

	void Rectangle::SetVelocity(int velocity)
	{
		m_velocity = velocity;
	}
}

#include <iostream>
#include <SFML\Graphics.hpp>
#include <Functions.hpp>


namespace VK
{
	Circle::Circle(int x0, int y0, float r, float angle, float v0)
	{
		m_x0 = x0;
		m_y0 = y0;
		m_r = r;
		m_angle = (2 * acos(-1) - angle);
		m_v0 = v0;
	}

	bool Circle::Setup()
	{
		if (!m_texture.loadFromFile("ball.png"))
		{
			std::cout << "ERROR when loading Circle.png" << std::endl;
			return false;
		}
		m_Circle = new sf::Sprite();
		m_Circle->setTexture(m_texture);
		m_Circle->setOrigin(m_r, m_r);
		m_Circle->setPosition(m_x, m_y);

		return true;
	}

	Circle::~Circle()
	{
		if (m_Circle != nullptr)
			delete m_Circle;
	}

	void Circle::Move(float t)
	{
		m_x = m_x0 + m_v0 * cos(m_angle) * t;
		m_y = m_y0 + m_v0 * sin(m_angle) * t + g * t * t / 2;
		m_Circle->setPosition(m_x, m_y);
	}

	sf::Sprite* Circle::Get() { return m_Circle; }

	int Circle::GetX() { return m_x; }
	int Circle::GetY() { return m_y; }
	void Circle::Set(int x, int y) {
		m_x = x;
		m_y = y;
		m_Circle->setPosition(m_x, m_y);
	}
	float Circle::GetR() { return m_r; }

}

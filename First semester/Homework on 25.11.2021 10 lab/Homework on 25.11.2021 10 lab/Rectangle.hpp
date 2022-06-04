#pragma once
#include <SFML/Graphics.hpp>

namespace VK
{
	class Rectangle
	{
	public:
		Rectangle(int x, int y, int size_X, int size_Y, float velocity);

		~Rectangle();

		sf::RectangleShape* Get();

		void Move();

		int GetY();

		void SetVelocity(int velocity);

	private:
		int m_x, m_y, sizeX, sizeY;
		float m_velocity;
		sf::RectangleShape* m_shape;
	};

}

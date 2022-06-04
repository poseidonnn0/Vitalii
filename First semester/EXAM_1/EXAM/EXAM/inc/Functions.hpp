#pragma once
#include <SFML\Graphics.hpp>

namespace VK
{
	const float g = 9.8; // /c^2

	class Circle
	{
		int m_x, m_y, m_x0, m_y0;
		float m_r;
		float m_angle;
		float m_v0;
		sf::Texture m_texture;
		sf::Sprite* m_Circle = nullptr;
	public:
		Circle(int x0, int y0, float r, float angle, float v0);
		~Circle();

		bool Setup();
		void Move(float t);

		sf::Sprite* Get();
		int GetX();
		int GetY();
		void Set(int x, int y);
		float GetR();
	
	};

}

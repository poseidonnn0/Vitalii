#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
namespace myGame
{
	enum class ButtonType
	{
		NONE,
		NEWGAME,
		CONTINUE,
		EXIT
	};

	class Button
	{
	public:
		Button(int x, int y, ButtonType buttonType)
		{
			m_x = x;
			m_y = y;
			m_buttonType = buttonType;
		}

		bool Setup()
		{
			switch (m_buttonType)
			{
			case ButtonType::NEWGAME:
				if (!m_textureBasic.loadFromFile("images\\New_Game.png"))
				{
					std::cerr << "Loading button new game error." << std::endl;
					return false;
				}
				break;
			case ButtonType::CONTINUE:
				if (!m_textureBasic.loadFromFile("images\\Continue.png"))
				{
					std::cerr << "Loading button continue error." << std::endl;
					return false;
				}
				break;
			case ButtonType::EXIT:
				if (!m_textureBasic.loadFromFile("images\\Exit.png"))
				{
					std::cerr << "Loading button exit error." << std::endl;
					return false;
				}
				break;
			}

			m_spriteButton.setTexture(m_textureBasic);
			m_spriteButton.setPosition(m_x, m_y);

			return true;
		}

		sf::Sprite Get()
		{
			return m_spriteButton;
		}

		bool isPressed(sf::Vector2i mousePos)
		{
			int x1 = m_x;
			int y1 = m_y;
			int x2 = m_x + 300;
			int y2 = m_y + 100;
			int x = mousePos.x;
			int y = mousePos.y;

			if (x1 <= x && x <= x2 && y1 <= y && y <= y2)
				return true;
			return false;
		}

		ButtonType Type() { return m_buttonType; }
	private:
		int m_x, m_y;
		sf::Sprite m_spriteButton;
		sf::Texture m_textureBasic;
		ButtonType m_buttonType;
	};
}

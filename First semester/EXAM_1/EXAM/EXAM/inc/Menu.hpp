#pragma once
#include <Button.hpp>

namespace myGame
{
	class Menu
	{
	public:
		Menu(std::shared_ptr<sf::RenderWindow> window)
		{
			m_window = window;
			if (!m_background.loadFromFile("images\\background.png"))
			{
				std::cerr << "Loading background error." << std::endl;
			}
			m_backgroundSprite.setTexture(m_background);

			std::shared_ptr<Button> newGameBut = std::make_shared<Button>(485, 225, ButtonType::NEWGAME);
			m_buttons.push_back(newGameBut);
			std::shared_ptr<Button> continueBut = std::make_shared<Button>(500, 360, ButtonType::CONTINUE);
			m_buttons.push_back(continueBut);
			std::shared_ptr<Button> exitBut = std::make_shared<Button>(555, 500, ButtonType::EXIT);
			m_buttons.push_back(exitBut);
		}

		bool Setup()
		{
			for (const auto& button : m_buttons)
				if (!button->Setup())
					return false;
			return true;
		}
		~Menu()
		{

		}

		void Display()
		{
			m_window->clear();
			m_window->draw(m_backgroundSprite);
			for (const auto& button : m_buttons)
				m_window->draw(button->Get());
			m_window->display();
		}

		ButtonType PressedButton()
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				sf::Vector2i mousePos = sf::Mouse::getPosition(*m_window);

				for (const auto& button : m_buttons)
					if (button->isPressed(mousePos))
						return button->Type();
			}
			return ButtonType::NONE;
		}
	private:
		std::shared_ptr<sf::RenderWindow> m_window;
		std::vector<std::shared_ptr<Button>> m_buttons;
		sf::Texture m_background;
		sf::Sprite m_backgroundSprite;
	};
}

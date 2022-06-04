#include <Game.hpp>

using namespace std::chrono_literals;

namespace myGame
{
	Game::Game(std::shared_ptr<sf::RenderWindow> window)
	{
		randomMapGenerate(chest, torch, goldChest);
		m_window = window;// std::make_shared<sf::RenderWindow>(sf::VideoMode(m_width, m_height), "Destroyeer!");
		m_width = m_window->getSize().x;
		m_height = m_window->getSize().y;
	}
	Game::~Game()
	{
	}
	bool Game::Setup()
	{
		if (!setInfo())
			return false;
		if (!setMap())
			return false;
		return true;
	}

	void Game::LifeCycle()
	{
		while (m_window->isOpen())
		{
			sf::Event event;
			while (m_window->pollEvent(event))
			{
				// ��������� �������
				// ���� ����� �������, ��
				if (event.type == sf::Event::Closed)
					// ���� �����������
					//m_window->close();
					return;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// ������� ���������
				sf::Vector2i mp = sf::Mouse::getPosition(*m_window);

				float d = sqrt((mp.x - s_x) * (mp.x - s_x) + (mp.y - s_y) * (mp.y - s_y));
				float dy = (s_y - mp.y);
				float dx = (mp.x - s_x);
				float angle = atan(dy / dx);

				if (circle != nullptr)
					delete circle;

				circle = new VK::Circle(s_x, s_y, 12, angle, d / 3);

				if (!circle->Setup())
				{
					delete circle;
					m_window->close();
				}
				t = 0;
				attempts--;
				if (attempts < 0)
				{
					loss = true;
					std::cout << " < You lost :( > " << std::endl; // ���� ������� �����������
				};
			}

			// ����� //
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); // ���� ��������� ������ ������, �� ������ 1� ��������� (32*32).
					if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32)); // ������ ������ (������������� ����(+1))
					if (TileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(64, 0, 32, 32)); // ������ �����(���. ����)
					if (TileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(224, 0, 32, 32)); // ������ ������� ������
					if (TileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(96, 0, 32, 32)); // ������ ��� 
					if (TileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(128, 0, 32, 32)); // ������ ���
					if (TileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(160, 0, 32, 32)); // ������ ����� ��� ������
					if (TileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(192, 0, 32, 32)); // ������ ������(������)
					if (TileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(192, 32, 32, 32)); // ������ ������(����)

					s_map.setPosition(j * 32, i * 32); // ����������� ������ ����� �� �� ������� (������� ������ ������ ������(��������))
					m_window->draw(s_map); // ������ ���������� �� ����� (�����)
				}
			// �������� ����
			if (circle != nullptr)
			{
				circle->Move(t);
				//�������� �� ���������� ���� � ������� � ������
				int X = circle->GetX();
				int Y = circle->GetY();
				int R = circle->GetR();
				for (int i = Y / 32; i < (Y + 3 * R) / 32; i++)
					for (int j = X / 32; j < (X + 3 * R) / 32; j++)
					{
						if ((TileMap[i][j] == '0') || (TileMap[i][j] == '1') || (TileMap[i][j] == '3') || (TileMap[i][j] == '4')) // ���� ���������� � ���������(���� �����) ��� ����� ����������(�����)
						{
							circle = nullptr; // ������� ���
						}
						if (TileMap[i][j] == 's') {
							point++; //���� ���������� � �������� - ��������� ���� � ������� ������
							TileMap[i][j] = ' ';
							if (point >= 15) // ������� ������
							{
								std::cout << "Win!!!" << std::endl;
								win = true;

							}
						}
						if (TileMap[i][j] == 'g') {
							point = point + 2; //���� ���������� � �������� - ��������� ���� � ������� ������
							TileMap[i][j] = ' ';
							if (point >= 15) // ������� ������
							{
								std::cout << "Win!!!" << std::endl;
								win = true;
							}
						}
						else if (TileMap[i][j] == 'd')
						{
							point--; //���� ���������� � ������� - �������� ���� � ������� �������
							TileMap[i][j] = ' ';
						}
					}
			}
			text.setString(std::string("Points: ") + std::to_string(point) + std::string("\nRemaining attempts: ") + std::to_string(attempts));
			m_window->draw(text);
			if (circle != nullptr)
			{
				m_window->draw(*circle->Get());
			}
			m_window->display();

			std::this_thread::sleep_for(std::chrono::milliseconds(25)); 
			//std::this_thread::sleep_for(40ms);
			t += 0.07;
		}
		if (circle != nullptr)
		{
			delete circle;
		}
	}
}

/*
namespace myGame
{
	{
		int attempts; // �������
		int chest, torch, goldChest; // �������, ������
		int difficulty = 0;
		
		//�������� ����� � �������: (�������/������)
		//"˸����" 50/25 ---> 0
		//"�������" 35/30 ---> 1
		//"�������" 25 / 35 ----> 2
		//������ - 15 �����! (point)
		
		if (difficulty == 0)
		{
			chest = 50; torch = 25; goldChest = 5; attempts = 20;
		}
		else if (difficulty == 1)
		{
			chest = 35; torch = 30; goldChest = 4; attempts = 20;
		}
		else if (difficulty == 2)
		{
			chest = 25; torch = 35; goldChest = 3; attempts = 20;
		}
		randomMapGenerate(chest, torch, goldChest);
		float s_x = 48; // ��������� ��������� ����
		float s_y = 736;
		float t = 0;
		int point = 0; // ��������� ���������� �����

		sf::RenderWindow window(sf::VideoMode(1280, 800), "EXAM");
		sf::Image map_image;
		map_image.loadFromFile("images//map.png");
		sf::Texture map;
		map.loadFromImage(map_image); // ��������� �������� ���������
		sf::Sprite s_map;
		s_map.setTexture(map);

		VK::Circle* circle = nullptr; // ����� ������� �������� ����

		// ��������� ������ � �������� ����������� �����
		sf::Font font;
		if (!font.loadFromFile("fonts/Marck.ttf"))
		{
			std::cout << "ERROR: font was not loaded." << std::endl;
			return -1;
		}
		sf::Text text; // ����� �����
		text.setFont(font);
		text.setPosition(30, 25); // ��� ��������� ������������
		text.setCharacterSize(30); // ��� ������
		text.setStyle(sf::Text::Bold); // ��������
		text.setFillColor(sf::Color::White); // ����
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// ��������� �������
				// ���� ����� �������, ��
				if (event.type == sf::Event::Closed)
					// ���� �����������
					window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// ������� ���������
				sf::Vector2i mp = sf::Mouse::getPosition(window);

				float d = sqrt((mp.x - s_x) * (mp.x - s_x) + (mp.y - s_y) * (mp.y - s_y));
				float dy = (s_y - mp.y);
				float dx = (mp.x - s_x);
				float angle = atan(dy / dx);

				if (circle != nullptr)
					delete circle;

				circle = new VK::Circle(s_x, s_y, 12, angle, d / 3);

				if (!circle->Setup())
				{
					delete circle;
					window.close();
					return -1;
				}
				t = 0;
				attempts--;
				if (attempts <= 0)
				{
					std::cout << " < You lost :( > " << std::endl; // ���� ������� �����������
				};
			}

			// ����� //
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); // ���� ��������� ������ ������, �� ������ 1� ��������� (32*32).
					if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32)); // ������ ������ (������������� ����(+1))
					if (TileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(64, 0, 32, 32)); // ������ �����(���. ����)
					if (TileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(224, 0, 32, 32)); // ������ ������� ������
					if (TileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(96, 0, 32, 32)); // ������ ��� 
					if (TileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(128, 0, 32, 32)); // ������ ���
					if (TileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(160, 0, 32, 32)); // ������ ����� ��� ������
					if (TileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(192, 0, 32, 32)); // ������ ������(������)
					if (TileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(192, 32, 32, 32)); // ������ ������(����)

					s_map.setPosition(j * 32, i * 32); // ����������� ������ ����� �� �� ������� (������� ������ ������ ������(��������))
					window.draw(s_map); // ������ ���������� �� ����� (�����)
				}
			// �������� ����
			if (circle != nullptr)
			{
				circle->Move(t);
				//�������� �� ���������� ���� � ������� � ������
				int X = circle->GetX();
				int Y = circle->GetY();
				int R = circle->GetR();
				for (int i = Y / 32; i < (Y + 3 * R) / 32; i++)
					for (int j = X / 32; j < (X + 3 * R) / 32; j++)
					{
						if ((TileMap[i][j] == '0') || (TileMap[i][j] == '1') || (TileMap[i][j] == '3') || (TileMap[i][j] == '4')) // ���� ���������� � ���������(���� �����) ��� ����� ����������(�����)
						{
							circle = nullptr; // ������� ���
						}
						if (TileMap[i][j] == 's') {
							point++; //���� ���������� � �������� - ��������� ���� � ������� ������
							TileMap[i][j] = ' ';
							if (point >= 15) // ������� ������
							{
								std::cout << "Win!!!" << std::endl;
							}
						}
						if (TileMap[i][j] == 'g') {
							point = point + 2; //���� ���������� � �������� - ��������� ���� � ������� ������
							TileMap[i][j] = ' ';
							if (point >= 15) // ������� ������
							{
								std::cout << "Win!!!" << std::endl;
							}
						}
						else if (TileMap[i][j] == 'd')
						{
							point--; //���� ���������� � ������� - �������� ���� � ������� �������
							TileMap[i][j] = ' ';
						}
					}
			}
			text.setString(std::string("Points: ") + std::to_string(point) + std::string("\nRemaining attempts: ") + std::to_string(attempts));
			window.draw(text);
			if (circle != nullptr)
			{
				window.draw(*circle->Get());
			}

			window.display();

			std::this_thread::sleep_for(40ms);
			t += 0.07;
			//void Menu();
		}
		if (circle != nullptr)
		{
			delete circle;
		}

		std::cout << "Points: " << point;
	}
}
*/
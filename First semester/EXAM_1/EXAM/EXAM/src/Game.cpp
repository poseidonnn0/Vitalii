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
				// Обработка событий
				// Если нажат крестик, то
				if (event.type == sf::Event::Closed)
					// окно закрывается
					//m_window->close();
					return;
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// Дребезг контактов
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
					std::cout << " < You lost :( > " << std::endl; // Если попытки закончились
				};
			}

			// Карта //
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); // если встретили символ пробел, то рисуем 1й квадратик (32*32).
					if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32)); // Рисуем сундук (Положительное очко(+1))
					if (TileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(64, 0, 32, 32)); // Рисуем факел(отр. очко)
					if (TileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(224, 0, 32, 32)); // Рисуем золотой сундук
					if (TileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(96, 0, 32, 32)); // Рисуем Ель 
					if (TileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(128, 0, 32, 32)); // Рисуем Дуб
					if (TileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(160, 0, 32, 32)); // Рисуем Землю для игрока
					if (TileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(192, 0, 32, 32)); // Рисуем Игрока(голова)
					if (TileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(192, 32, 32, 32)); // Рисуем Игрока(ноги)

					s_map.setPosition(j * 32, i * 32); // Раскидываем массив карты по их ячейкам (задавая размер каждой ячейке(элементы))
					m_window->draw(s_map); // рисуем квадратики на экран (карту)
				}
			// Движение мяча
			if (circle != nullptr)
			{
				circle->Move(t);
				//Проверка на соударение мяча и сундука и факела
				int X = circle->GetX();
				int Y = circle->GetY();
				int R = circle->GetR();
				for (int i = Y / 32; i < (Y + 3 * R) / 32; i++)
					for (int j = X / 32; j < (X + 3 * R) / 32; j++)
					{
						if ((TileMap[i][j] == '0') || (TileMap[i][j] == '1') || (TileMap[i][j] == '3') || (TileMap[i][j] == '4')) // Если соударение с деревьями(край карты) или самим человечком(мобом)
						{
							circle = nullptr; // Удаляем мяч
						}
						if (TileMap[i][j] == 's') {
							point++; //Если соударение с сундуком - добавляем очко и удаляем сундук
							TileMap[i][j] = ' ';
							if (point >= 15) // Условие победы
							{
								std::cout << "Win!!!" << std::endl;
								win = true;

							}
						}
						if (TileMap[i][j] == 'g') {
							point = point + 2; //Если соударение с сундуком - добавляем очко и удаляем сундук
							TileMap[i][j] = ' ';
							if (point >= 15) // Условие победы
							{
								std::cout << "Win!!!" << std::endl;
								win = true;
							}
						}
						else if (TileMap[i][j] == 'd')
						{
							point--; //Если соударение с факелом - убавляем очко и удаляем факелом
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
		int attempts; // попытки
		int chest, torch, goldChest; // сундуки, факела
		int difficulty = 0;
		
		//Выберите режим в менюшке: (сундуки/факела)
		//"Лёгкий" 50/25 ---> 0
		//"Средний" 35/30 ---> 1
		//"Сложный" 25 / 35 ----> 2
		//Победа - 15 очков! (point)
		
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
		float s_x = 48; // начальное положение мяча
		float s_y = 736;
		float t = 0;
		int point = 0; // Начальное количество очков

		sf::RenderWindow window(sf::VideoMode(1280, 800), "EXAM");
		sf::Image map_image;
		map_image.loadFromFile("images//map.png");
		sf::Texture map;
		map.loadFromImage(map_image); // Заполняем текстуру картинкой
		sf::Sprite s_map;
		s_map.setTexture(map);

		VK::Circle* circle = nullptr; // Задаём нулевое значение шара

		// Подгрузка шрифта и создание отображения счета
		sf::Font font;
		if (!font.loadFromFile("fonts/Marck.ttf"))
		{
			std::cout << "ERROR: font was not loaded." << std::endl;
			return -1;
		}
		sf::Text text; // Задаём текст
		text.setFont(font);
		text.setPosition(30, 25); // его начальное расположение
		text.setCharacterSize(30); // его размер
		text.setStyle(sf::Text::Bold); // Жирность
		text.setFillColor(sf::Color::White); // Цвет
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				// Обработка событий
				// Если нажат крестик, то
				if (event.type == sf::Event::Closed)
					// окно закрывается
					window.close();
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				// Дребезг контактов
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
					std::cout << " < You lost :( > " << std::endl; // Если попытки закончились
				};
			}

			// Карта //
			for (int i = 0; i < HEIGHT_MAP; i++)
				for (int j = 0; j < WIDTH_MAP; j++)
				{
					if (TileMap[i][j] == ' ')  s_map.setTextureRect(sf::IntRect(0, 0, 32, 32)); // если встретили символ пробел, то рисуем 1й квадратик (32*32).
					if (TileMap[i][j] == 's')  s_map.setTextureRect(sf::IntRect(32, 0, 32, 32)); // Рисуем сундук (Положительное очко(+1))
					if (TileMap[i][j] == 'd')  s_map.setTextureRect(sf::IntRect(64, 0, 32, 32)); // Рисуем факел(отр. очко)
					if (TileMap[i][j] == 'g')  s_map.setTextureRect(sf::IntRect(224, 0, 32, 32)); // Рисуем золотой сундук
					if (TileMap[i][j] == '0')  s_map.setTextureRect(sf::IntRect(96, 0, 32, 32)); // Рисуем Ель 
					if (TileMap[i][j] == '1')  s_map.setTextureRect(sf::IntRect(128, 0, 32, 32)); // Рисуем Дуб
					if (TileMap[i][j] == '2')  s_map.setTextureRect(sf::IntRect(160, 0, 32, 32)); // Рисуем Землю для игрока
					if (TileMap[i][j] == '3')  s_map.setTextureRect(sf::IntRect(192, 0, 32, 32)); // Рисуем Игрока(голова)
					if (TileMap[i][j] == '4')  s_map.setTextureRect(sf::IntRect(192, 32, 32, 32)); // Рисуем Игрока(ноги)

					s_map.setPosition(j * 32, i * 32); // Раскидываем массив карты по их ячейкам (задавая размер каждой ячейке(элементы))
					window.draw(s_map); // рисуем квадратики на экран (карту)
				}
			// Движение мяча
			if (circle != nullptr)
			{
				circle->Move(t);
				//Проверка на соударение мяча и сундука и факела
				int X = circle->GetX();
				int Y = circle->GetY();
				int R = circle->GetR();
				for (int i = Y / 32; i < (Y + 3 * R) / 32; i++)
					for (int j = X / 32; j < (X + 3 * R) / 32; j++)
					{
						if ((TileMap[i][j] == '0') || (TileMap[i][j] == '1') || (TileMap[i][j] == '3') || (TileMap[i][j] == '4')) // Если соударение с деревьями(край карты) или самим человечком(мобом)
						{
							circle = nullptr; // Удаляем мяч
						}
						if (TileMap[i][j] == 's') {
							point++; //Если соударение с сундуком - добавляем очко и удаляем сундук
							TileMap[i][j] = ' ';
							if (point >= 15) // Условие победы
							{
								std::cout << "Win!!!" << std::endl;
							}
						}
						if (TileMap[i][j] == 'g') {
							point = point + 2; //Если соударение с сундуком - добавляем очко и удаляем сундук
							TileMap[i][j] = ' ';
							if (point >= 15) // Условие победы
							{
								std::cout << "Win!!!" << std::endl;
							}
						}
						else if (TileMap[i][j] == 'd')
						{
							point--; //Если соударение с факелом - убавляем очко и удаляем факелом
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
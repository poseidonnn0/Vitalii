#include <iostream>
#include <Functions.hpp>
#include <SFML\Graphics.hpp>
#include <string>
#include <thread>
#include <chrono>
#include <string>
#include <Map.hpp>
namespace myGame
{
	class Game
	{
	public:
		Game(std::shared_ptr<sf::RenderWindow> window);
		~Game();

        void LifeCycle();
        bool setInfo()
        {
            if (!font.loadFromFile("fonts/Marck.ttf"))
            {
                std::cout << "ERROR: font was not loaded." << std::endl;
                return false;
            }
            text.setFont(font);
            text.setPosition(30, 25); // его начальное расположение
            text.setCharacterSize(30); // его размер
            text.setStyle(sf::Text::Bold); // Жирность
            text.setFillColor(sf::Color::White); // Цвет
            return true;
        }
        bool setMap()
        {
            if (!map_image.loadFromFile("images//map.png"))
            {
                std::cout << "ERROR: images for MAP was not loaded." << std::endl;
                return false;
            }
            map.loadFromImage(map_image); // Заполняем текстуру картинкой
            s_map.setTexture(map);
            return true;
        }

        bool Setup();
        bool Resume()
        {
            return true;
        }

    private:
        int m_width, m_height;
        sf::Font font;
        std::shared_ptr<sf::RenderWindow> m_window;
        sf::Text text; // Задаём текст
        sf::Image map_image;
        sf::Texture map;
        sf::Sprite s_map;
        VK::Circle* circle = nullptr; // Задаём нулевое значение шара
        float s_x = 48; // начальное положение мяча
        float s_y = 736;
        float t = 0;
        int point = 0; // Начальное количество очков
        int attempts = 20; // попытки
        int difficulty = 0;
        int chest = 50, torch = 25, goldChest = 5; // сундуки, факела
        bool win = false, loss = false;
	};
		


    /*
//	Выберите режим в менюшке: (сундуки/факела)
//	"Лёгкий" 50/25 ---> 0
//	"Средний" 35/30 ---> 1
//	"Сложный" 25 / 35 ----> 2
//	Победа - 15 очков! (point)
//	*/
//
//	if (difficulty == 0) 
//	{
//		chest = 50; torch = 25; goldChest = 5; attempts = 20;
//	}
//	else if (difficulty == 1)
//	{
//		chest = 35; torch = 30; goldChest = 4; attempts = 20;
//	}
//	else if (difficulty == 2)
//	{
//		chest = 25; torch = 35; goldChest = 3; attempts = 20;
//	}
//	randomMapGenerate(chest,torch,goldChest);
}

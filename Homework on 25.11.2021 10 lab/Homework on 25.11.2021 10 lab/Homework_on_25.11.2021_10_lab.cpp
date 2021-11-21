// Подключение графической библиотеки
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <fstream>
#include "Rectangle.hpp"
#include <vector>

using namespace std::chrono_literals;

int main()
{
    // Инициализация
    srand(time(0));

    sf::Texture texture;
   if (!texture.loadFromFile("images\\back.jpg"))
   {
        std::cout << "ERROR: not found back.jpg" << std::endl;
        return -1;
   }
  /** sf::Texture textureRectangle;

    if (!textureRectangle.loadFromFile("images\\GoldBars.png"))
    {
        std::cout << "ERROR: not found GoldBars.png" << std::endl;
        return -1;
    }*/
   sf::Sprite background(texture);
    const int width = 1227;
    const int height = 823;
    const int N = 50;

    // Создание окна с известными размерами и названием
    sf::RenderWindow window(sf::VideoMode(width, height), L"Первая программа!");

    // 1 
    std::vector<VK::Rectangle*> rectangles;

    for (int i = 0; i <= width; i += width / N)
    {
        rectangles.push_back(new VK::Rectangle(i, height, 10, 5, rand() % 8 + 1)); // a = rand() дает от 0 до 32767, a % 5 + 1 // size_X, size_Y отвечают за размеры прямоугольника
    }


    // Цикл работает до тех пор, пока окно открыто
    while (window.isOpen())
    {
        // Переменная для хранения события
        sf::Event event;
        // Цикл по всем событиям
        while (window.pollEvent(event))
        {
            // Обработка событий
            // Если нажат крестик, то
            if (event.type == sf::Event::Closed)
                // окно закрывается
                window.close();
        }

        // 2 Обработка
        for (const auto& rectangle : rectangles)
        {
            rectangle->Move();
            if (rectangle->GetY() > height)
            {
                rectangle->SetVelocity(rand() % 5 + 1);
            }
        }

        // Очистить окно от всего
        window.clear();

        // 3
        // Фон
        window.draw(background);
        // Перемещение фигуры в буфер
        for (const auto& rectangle : rectangles)
            window.draw(*rectangle->Get());

        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(40ms);
    }

    for (const auto& rectangle : rectangles)
        delete rectangle;
    rectangles.clear();

    return 0;
}

// Подключение графической библиотеки
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), L"9 Лабораторная работа");
    //Круг
    sf::CircleShape shape(125.0);   // 100.0 - double, 100.f - float
    shape.setOrigin(125, 125);
    sf::Texture texture;
    sf::Texture texture2;
    sf::Texture texture3;
    // Если изображение в Build → texture.loadFromFile("Tor.jpeg");
    texture.loadFromFile("C:\\Users\\Vitaliy\\OneDrive\\Documents\\Git\\Repositories\\sfml-sample-1-work\\sfml-sample-1\\ext\\image\\Tor.jpeg");
    texture2.loadFromFile("C:\\Users\\Vitaliy\\OneDrive\\Documents\\Git\\Repositories\\sfml-sample-1-work\\sfml-sample-1\\ext\\image\\Pivo.png");
    texture3.loadFromFile("C:\\Users\\Vitaliy\\OneDrive\\Documents\\Git\\Repositories\\sfml-sample-1-work\\sfml-sample-1\\ext\\image\\Besk.jpg");
    shape.setTexture(&texture);
    texture.setSmooth(true);
    shape.setTextureRect(sf::IntRect(27, 27, 125, 125));
    int shape_x = 150, shape_y = 675;
    shape.setPosition(shape_x, shape_y);
    int Gradus = 0;
    // Прямоугольник
    sf::RectangleShape shape2(sf::Vector2f(144, 170));
    shape2.setTexture(&texture2);
    shape2.setTextureRect(sf::IntRect(0, 0, 72, 85));
    shape2.setOrigin(72, 85);
    float shape2_x = 400, shape2_y = 715;
    shape2.setPosition(shape2_x, shape2_y);


    // Октагон
    sf::CircleShape shape3(80, 8);
    shape3.setTexture(&texture3);
    shape3.setOrigin(0, 0);
    int shape3_x = 580, shape3_y = 640;
    shape3.setPosition(shape3_x, shape3_y);
    //shape3.setRotation(45.f);
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
    
        shape_y--;
        if (shape_y < 125)
        {
            shape_y = 125;
        }


        shape2_y = shape2_y - 2;
        if (shape2_y < 85)
        {
            shape2_y = 85;
        }
        else if ((shape2_y > 90) && (shape2_y < 200))
        {
            shape2_y = shape2_y + 1.65;
        }
          
        /*else
        {
            shape2.move(0, -2);
        }*/

        shape3_y = shape3_y - 3;
        if (shape3_y < 0)
        {
            shape3_y = 0;
        }

        //Gradus++;
        //shape3.setRotation(Gradus);

        shape.setPosition(shape_x, shape_y);
        shape2.setPosition(shape2_x, shape2_y);
        shape3.setPosition(shape3_x, shape3_y);
        // Очистить окно от всего
        window.clear();

        // Перемещение фигуры в буфер
        window.draw(shape);
        window.draw(shape2);
        window.draw(shape3);
        // Отобразить на окне все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(4ms);
    }

    return 0;
}
#include <Game.hpp>
#include <Menu.hpp>

using myGame::ButtonType;


int main()
{
	std::shared_ptr<sf::RenderWindow> window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1280, 800), "Destroyeer!");

    myGame::Menu menu(window);
    if (!menu.Setup())
        return 1;


	std::shared_ptr<myGame::Game> game = nullptr;

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        
        ButtonType button = menu.PressedButton();

        switch (button)
        {
        case ButtonType::NEWGAME:
            game = std::make_shared<myGame::Game>(window);

            if (!game->Setup())
                return 1;

            game->LifeCycle();

            break;

        case ButtonType::CONTINUE:
            if (game != nullptr)
            {
                game->Resume();
                game->LifeCycle();
            }
            break;

        case ButtonType::EXIT:
            window->close();
        }

        // Вывод меню на экран
        menu.Display();

        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }

	return 0;
}
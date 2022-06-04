#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 25; // размер карты высота,где после мы 25*32 = 800 - получаем высоту экарана
const int WIDTH_MAP = 40; // размер карты ширина , где 40*32 = 1280 - ширина экрана
extern sf::String TileMap[HEIGHT_MAP];
void randomMapGenerate(const int& countChests, const int& countTorchs, const int& countGoldChests);

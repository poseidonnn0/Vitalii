#pragma once
#include <SFML\Graphics.hpp>
const int HEIGHT_MAP = 25; // ������ ����� ������,��� ����� �� 25*32 = 800 - �������� ������ �������
const int WIDTH_MAP = 40; // ������ ����� ������ , ��� 40*32 = 1280 - ������ ������
extern sf::String TileMap[HEIGHT_MAP];
void randomMapGenerate(const int& countChests, const int& countTorchs, const int& countGoldChests);

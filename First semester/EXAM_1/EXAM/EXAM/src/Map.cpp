#pragma once
#include <Map.hpp>

sf::String TileMap[HEIGHT_MAP]
{
	"0101010101010101010101010101010101010101",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"0                                      1",
	"1                                      0",
	"32                                     1",
	"42                                     0",
	"0101010101010101010101010101010101010101",
};

int f = 0; // ��������� ����, ����� ������ �� ������� �������� ������ ������ ��� ������� "New Game", ����� �� ���� ����� � �������� � �������

void randomMapGenerate(const int& countChests, const int& countTorchs, const int& countGoldChests) { // �������� ����������� �����

	if (f == 0)
	{
		int randomElementX = 0; // ��������� ������� �� �����������
		int randomElementY = 0; // ��������� ������� �� ���������
		srand(time(0)); // ������
		int countChest = countChests; // ���-�� ��������
		int countGoldChest = countGoldChests; // ���-�� ������� ��������
		int countTorch = countTorchs; // ���-�� �������
		while (countChest > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (�� ������� ���� �����)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //���� ��������� ������ ������,
				TileMap[randomElementY][randomElementX] = 's'; // �� ������ ���� ������.
				countChest--;
			}
		}
		while (countGoldChest > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (�� ������� ���� �����)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //���� ��������� ������ ������,
				TileMap[randomElementY][randomElementX] = 'g'; // �� ������ ���� ������.
				countGoldChest--;
			}
		}
		while (countTorch > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (�� ������� ���� �����)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //���� ��������� ������ ������,
				TileMap[randomElementY][randomElementX] = 'd'; // �� ������ ���� �����.
				countTorch--;
			}
		}
	}
	f = 1; 
}
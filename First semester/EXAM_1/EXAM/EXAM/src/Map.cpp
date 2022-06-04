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

int f = 0; // Добавляем флаг, чтобы рандом не заменял повторно пустые клетки при нажатии "New Game", иначе всё поле будет в сундуках и факелах

void randomMapGenerate(const int& countChests, const int& countTorchs, const int& countGoldChests) { // рандомно расставляем камни

	if (f == 0)
	{
		int randomElementX = 0; // случайный элемент по горизонтали
		int randomElementY = 0; // случайный элемент по вертикали
		srand(time(0)); // рандом
		int countChest = countChests; // Кол-во сундуков
		int countGoldChest = countGoldChests; // Кол-во золотых сундуков
		int countTorch = countTorchs; // Кол-во факелов
		while (countChest > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (не включая край карты)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //если встретили символ пробел,
				TileMap[randomElementY][randomElementX] = 's'; // то ставим туда сундук.
				countChest--;
			}
		}
		while (countGoldChest > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (не включая край карты)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //если встретили символ пробел,
				TileMap[randomElementY][randomElementX] = 'g'; // то ставим туда сундук.
				countGoldChest--;
			}
		}
		while (countTorch > 0) {
			randomElementX = 1 + rand() % (WIDTH_MAP - 1); // X (не включая край карты)
			randomElementY = 1 + rand() % (HEIGHT_MAP - 1); // Y

			if (TileMap[randomElementY][randomElementX] == ' ') { //если встретили символ пробел,
				TileMap[randomElementY][randomElementX] = 'd'; // то ставим туда факел.
				countTorch--;
			}
		}
	}
	f = 1; 
}
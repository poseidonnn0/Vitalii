﻿#include <iostream>
#include <HashFunc.h>
#include <cstdlib>
int main()
{
	int hashtable[N][N]; // const int N = 50;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			hashtable[i][j] = -1; // заполняем все значения -1 матрицы значений
		}
	}
	int mas[n]; // const int n = 15;

	srand(time(0)); // рандом, зависящий от текущего времени

	for (int i = 0; i < n; i++)
	{
		mas[i] = i * rand() % 50; // заполняем рандомными элементами матрицу
	}

	for (int i = 0; i < n; i++)
	{
		hash::HashTable(hashtable, mas[i]); // Хэшируем все элементы матрицы
	}

	hash::out(hashtable);// выводим лишь те элементы, которые прошли хеширование, т.е. какие ключи были заняты

	return 0;
}

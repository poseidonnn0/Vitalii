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
			hashtable[i][j] = -1;
		}
	}
	int mas[n]; // const int n = 15;

	srand(time(0));

	for (int i = 0; i < n; i++)
	{
		mas[i] = i * rand() % 50;
	}

	for (int i = 0; i < n; i++)
	{
		hash::HashTable(hashtable, mas[i]);
	}

	hash::out(hashtable);

	return 0;
}

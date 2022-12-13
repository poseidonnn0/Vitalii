/*
* HashFunc.cpp
*
* @created 12.12.2022 Vitaliy Kondratev
*
*/
#include "HashFunc.h"
int i_1 = 0;
namespace hash
{
	int Hashfunc(int a) 
	{
		int b = a % N + i_1;
		return b;
	}

	void HashTable(int mas[N][N], int a) 
	{
		while (true) 
		{
			int b = Hashfunc(a);

			if (mas[b][0] == -1) 
			{
				mas[b][0] = a;
				i_1 = 0;
				break;
			}
			else 
			{
				i_1++;
			}
		}
	}

	void out(int mas[N][N]) 
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				if (mas[i][j] != -1) 
				{
					std::cout << mas[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	void foundNubmers(int mas[N][N], int k) 
	{
		for (int i = 0; i < N; i++) 
		{
			if (mas[k][i] != -1) 
			{
				std::cout << "foundNumbers: " << mas[k][i] << " ";
			}
			else 
			{
				break;
			}
		}
	}
}
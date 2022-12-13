/*
* HashFunc.cpp
*
* @created 12.12.2022 Vitaliy Kondratev
*
*/
#include "HashFunc.h"
namespace hash
{
	int Hashfunc(int a) 
	{
		int b = a % N;
		return b;
	}

	void HashTable(int mas[N][N], int a) 
	{
		int b = Hashfunc(a);
		if (mas[b][0] == 0) 
		{
			mas[b][0] = a;
		}
		else 
		{
			for (int i = 1; i < N; i++) 
			{
				if (mas[b][i] == 0) 
				{
					mas[b][i] = a;
					break;
				}
			}
		}
	}

	void out(int mas[N][N]) 
	{
		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++) 
			{
				if (mas[i][j] != 0) 
				{
					std::cout << mas[i][j] << " ";
				}
			}
			std::cout << std::endl;
		}
	}

	int foundN(int y) 
	{
		int a = Hashfunc(y);
		return a;
	}

	void foundNubmers(int mas[N][N], int k) 
	{
		for (int i = 0; i < N; i++) 
		{
			if (mas[k][i] != 0) 
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
#include "Function.hpp"

namespace VK
{
	void Read(int& n, int& m, int mas[100][100])
	{
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cin >> mas[i][j];
			}
		}
	}
	void Write(int n, int m, int mas[100][100])
	{
		std::cout << n << " " << m << std::endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				std::cout << mas[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	int MinNumber(int n, int m, int mas[100][100]) 
	{
		int MinN = INT_MAX;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mas[i][j] <= MinN)
				{
					MinN = mas[i][j];
				}
			}
		}
		return MinN;
	}

	bool EqualMin(int n, int m, int mas[100][100])
	{
		int check = MinNumber(n, m, mas);
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (mas[i][j] == check)
				{
					count++;
				}
			}
		}
		if (count >= 2)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PrimeNumber(int n, int m, int mas[100][100])
	{
		int k = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				int x = abs(mas[i][j]);
				bool f = true; // простое
				if (x < 2)
				{
					f = true;
				}
				for (int d = 2; d <= sqrt(x); d++)
				{
					if (x % d == 0)
					{
						f = false;
						break;
					}
				}
				if (f)
				{
					k++;
				}
			}
		}
		if (k > 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void SWAP(int& a, int& b)
	{
		int tmp = a;
		a = b;
		b = tmp;
	}

	void SortMas(int& n, int& m, int mas[100][100])
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m - 1; j++)
			{
				for (int k = j + 1; k < m; k++)
				{
					if (mas[i][j] < mas[i][k])
					{
						SWAP(mas[i][j], mas[i][k]);
					}
				}
			}
		}
	}
}
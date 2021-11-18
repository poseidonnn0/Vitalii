#include <iostream>
#include <SomeFunctions.hpp>

namespace VK
{
	void Read(int& n, long int* mas)
	{
		for (int i = 0; i < n*2; i++)
		{
			mas[i] = (i < n) ? i + 1 : 0;
		}
	}

	int ProductDigits(int n)
	{
		int product = 1;
		int x = n;
		while (x != 0)
		{
			product *= x % 10;
			x /= 10;
		}
		return product;
	}

	bool PresenceDig8(int n) // Проверка на наличие цифры 8 в числе
	{
		int dig = 0;
		int x = n;
		while (x != 0)
		{
			dig = x % 10;
			if (dig == 8)
			{
				return true;
			}
			x = x / 10;
		}
		return false;
	}

	void Write(int& n, long int* mas)
	{
		for (int i = 0; i < n*2; i++)
		{
			if (mas[i] == 0)
			{
				std::cout << "";
			}
			else
			{
				std::cout << mas[i] << " ";
			}
		}
	}
}
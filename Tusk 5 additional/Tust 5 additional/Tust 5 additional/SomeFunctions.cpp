#include <iostream>
#include "SomeFunctions.hpp"

namespace VK
{


	void Read(int& n, int* mas)
	{
		for (int i = 0; i < n; i++)
		{
			mas[i] = i + 1;
		}
	}


	void Write1(int& n)
	{
		std::cout << n << " ";
	}


	bool ProductDigits(int n)
	{
		int product = 1;
		while (n != 0)
		{
			product *= n % 10;
			n /= 10;
		}

		if (product == 144)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool PresenceDig8(int n) // Проверка на наличие цифры 8 в числе
	{
		int dig = 0;
		while (n != 0)
		{
			dig = n % 10;
			if (dig == 8)
			{
				return true;
			}
			n = n / 10;
		}
	}

}
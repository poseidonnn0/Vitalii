#include <iostream>
#include "SomeFunctions.hpp"

namespace VK
{

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
		while (n != 0)
		{
			dig = n % 10;
			if (dig == 8)
			{
				return true;
			}
			n /= 10;
		}
		return false;
	}

}
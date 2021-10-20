#include <iostream>
#include "Functions.hpp"

namespace VK
{
	
	void Read(int& n)
	{
		std::cin >> n;
	}
	void Write(int n)
	{
		std::cout << n;
	}

	int MaxDigit(int n)
	{
		int x = n;
		int Digit = 0;
		int MaxDigi = INT_MIN;
		while (x > 9)
		{
			Digit = x % 10;
			if (Digit > MaxDigi)
			{
				MaxDigi = Digit;
			}
			x /= 10;
		}
		return MaxDigi;
	}
	
	void Repeat(int n)
	{
		int mas[10];
		std::fill(mas,mas+10, 0);
		int maxdig = INT_MIN;
		int maxdig1 = INT_MIN;
		int number = abs(n);
		do
		{
			int d = number % 10;
			mas[d] += 1;
			number /= 10;
		} while (number);
		std::cout << std::endl;
		for (int i = 0; i < 10; i++)
		{
			if (maxdig <= mas[i])
			{
				maxdig = mas[i];
				if (maxdig1 < i)
				{
					maxdig1 = i;
				}
			}
			//std::cout << i << " => " << mas[i] << std::endl;
		}
		std::cout << "Цифра = " << maxdig1 << " Макс. повторений = " << maxdig << std::endl;
	}
	
	int sumDigit(int n)
	{
		int sum = 0;
		while (n > 9)
		{
			sum += n % 10;
			n /= 10;
		}
		return sum;
	}

}

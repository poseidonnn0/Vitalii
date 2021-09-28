#include <iostream>
#include <fstream>

#define N 1000

using std::cout;
using std::endl;
using std::cin;

/* 
2.	Ввести последовательность натуральных чисел{Aj}, j = 1...n (n <= 1000).
(1 часть)Упорядочить последовательность по неубыванию первой цифры числа, 
(2 часть)числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа, 
(3 часть)числа с одинаковыми первыми цифрами и  одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.
*/

int FirstDig(int n) // решение через функцию, чтобы не загромаждать цикл
{
	while (n > 9)
	{
		n /= 10;
	}
	return n;
}

int SumDigits(int n) // Сумма цифр числа
{
	int sum = 0;
	while (n > 9)
	{
		sum += (n / 10);
		n /= 10;
	}
	return sum;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №3" << endl;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		int n;
		int mas[N];
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> mas[i];
		}
		for (int i = 0; i < n; i++)
		{
			out << mas[i] << " ";
		}

		out << endl << endl;

		for (int i = 0; i < n - 1; i++) // sort
		{
			for (int j = i + 1; j < n; j++)
			{
				if (FirstDig(mas[i]) != FirstDig(mas[j]))
				{
					if (FirstDig(mas[i]) >= FirstDig(mas[j]))
					{
						std::swap(mas[i],mas[j]);
					}
				else if (SumDigits(mas[i]) != SumDigits(mas[j]))
					{
						if (SumDigits(mas[i]) >= SumDigits(mas[j]))
						{
							std::swap(mas[i], mas[j]);
						}
					}
				else if (mas[i] >= mas[j])
					{
						std::swap(mas[i], mas[j]);
					}
				}
			}
		}


		for (int i = 0; i < n; i++)
		{
			out << mas[i] << " ";
		}
	}
	else
	{
		cout << "File not found" << endl;
	}
}

/*
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №3" << endl;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		int n, OneMasI , OneMasJ , OneMasImin = INT_MAX, OneMasJmin = INT_MAX; // OneMasImin - минимальная цифра во всём числе, OneMasJmin - минимальная цифра во всём следующем числе (j)
		int OstatI , OstatJ ;
		int mas[N];
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> mas[i];
		}
		for (int i = 0; i < n-1; i++) // первая сортировка
			{
				OneMasI = mas[i];
				out << OneMasI << endl;
				while (OneMasI > 9)
				{
					OneMasI = OneMasI / 10;
				}
				for (int j = i+1; j < n; j++)
				{
					OneMasJ = mas[j];
					while (OneMasJ > 9)
					{
						OneMasJ /= 10;
					}
					if (OneMasI != OneMasJ)
					{
						if (OneMasI > OneMasJ)
						{
							std::swap(mas[i], mas[j]);
						}
					}
				}
			}
		for (int i = 0; i < n; i++)
		{
			out << mas[i] << " ";
		}
	}
	else
	{
		cout << "File not found" << endl;
	}
}
*/
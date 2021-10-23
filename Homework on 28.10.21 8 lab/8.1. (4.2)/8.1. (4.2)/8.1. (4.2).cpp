#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;

/*
2.	Ввести последовательность натуральных чисел{Aj}, j = 1...n (n <= 1000).
(1 часть)Упорядочить последовательность по неубыванию первой цифры числа,
(2 часть)числа с одинаковыми первыми цифрами дополнительно упорядочить по неубыванию наименьшей цифры числа,
(3 часть)числа с одинаковыми первыми цифрами и  одинаковыми наименьшими цифрами дополнительно упорядочить по неубыванию самого числа.
*/


int FirstDig(int n) // Поиск первой цифры в числе
{
	while ((n / 10) > 0)
	{
		n /= 10;
	}
	return n;
}

int MinDigit(int n) // Поиск минимальной цифры в числе
{
	int Min = 10;
	int Ostat;
	while ((n / 10) > 0)
	{
		Ostat = n % 10;
		if (Min > Ostat)
		{
			Min = Ostat;
		}
		n /= 10;
	}
	return Min;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа(8.1) на 28.10.2021. Кондратьев Виталий, 4 вариант." << endl;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		int n;
		// int mas[N];
		in >> n;
		int* mas = new int[n];
		for (int i = 0; i < n; i++)
		{
			in >> mas[i];
		}

		for (int i = 0; i < n - 1; i++) // sort1
		{
			for (int j = i + 1; j < n; j++)
			{
				if (FirstDig(mas[i]) > FirstDig(mas[j]))
				{
					std::swap(mas[i], mas[j]);
				}
			}
		}

		for (int i = 0; i < n - 1; i++) //sort2
		{
			for (int j = i + 1; j < n; j++)
			{
				if (FirstDig(mas[i]) == FirstDig(mas[j]))
				{
					if (MinDigit(mas[i]) > MinDigit(mas[j]))
					{
						std::swap(mas[i], mas[j]);
					}
				}
			}
		}


		for (int i = 0; i < n - 1; i++) //sort3
		{
			for (int j = i + 1; j < n; j++)
			{
				if ((FirstDig(mas[i]) == FirstDig(mas[j])) && (MinDigit(mas[i]) == MinDigit(mas[j])))
				{
					if (mas[i] > mas[j])
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
		delete[] mas;
	}
	else
	{
		cout << "File not found" << endl;
	}
}

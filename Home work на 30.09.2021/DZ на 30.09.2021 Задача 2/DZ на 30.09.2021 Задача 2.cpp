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


int FirstDig(int n) // Поиск первой цифры в числе
{
	while ((n/10) > 0)
	{
		n /= 10;
	}
	return n;
}

int MinDigit(int n) // Поиск минимальной цифры в числе
{
	int Min = 10;
	int Ostat;
		while ((n/10) > 0)
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
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №2" << endl;
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
	}
	else
	{
		cout << "File not found" << endl;
	}
}

/* Без Функции - доработать 
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №2" << endl;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		int n, OneMasI, OneMasJ, Imin, Jmin, OstatI, OstatJ; 
		int mas[N];
		in >> n;
		for (int i = 0; i < n; i++)
		{
			in >> mas[i];
		}

		for (int i = 0; i < n-1; i++) // первая сортировка
		{
			OneMasI = mas[i];
			while ((OneMasI/10) > 0)
			{
				OneMasI = OneMasI / 10;
			}
			for (int j = i+1; j < n; j++)
			{
				OneMasJ = mas[j];
				while ((OneMasJ/10) > 0)
				{
					OneMasJ = OneMasJ / 10;
				}
				if (OneMasI > OneMasJ) // sort1
					{
						std::swap(mas[i], mas[j]);
					}
				}
		}

		for (int i = 0; i < n - 1; i++) // вторая сортировка
		{
			Imin = 10;
			OneMasI = mas[i];
			while ((OneMasI / 10) > 0)
			{
				OstatI = OneMasI % 10; // Ищем цифры числа I
				if (Imin > OstatI) // Минимальная цифра числа I
				{
					Imin = OstatI;
				}
				OneMasI = OneMasI / 10;
			}
			for (int j = i + 1; j < n; j++)
			{
				OneMasJ = mas[j];
				Jmin = 10;
				while ((OneMasJ / 10) > 0)
				{
					OstatJ = OneMasJ % 10; // Ищем цифры числа J
					if (Jmin > OstatJ) // Минимальная цифра числа J
					{
						Jmin = OstatJ;
					}
					OneMasJ = OneMasJ / 10;
				}
				if (OneMasI == OneMasJ) // sort2
				{
					if (Imin > Jmin)
					{
						std::swap(mas[i], mas[j]);
					}
				}
			}
		}

		for (int i = 0; i < n - 1; i++) // третья сортировка
		{
			Imin = 10;
			OneMasI = mas[i];
			while ((OneMasI / 10) > 0)
			{
				OstatI = OneMasI % 10; // Ищем цифры числа I
				if (Imin > OstatI) // Минимальная цифра числа I
				{
					Imin = OstatI;
				}
				OneMasI = OneMasI / 10;
			}
			for (int j = i + 1; j < n; j++)
			{
				OneMasJ = mas[j];
				Jmin = 10;
				while ((OneMasJ / 10) > 0)
				{
					OstatJ = OneMasJ % 10; // Ищем цифры числа J
					if (Jmin > OstatJ) // Минимальная цифра числа J
					{
						Jmin = OstatJ;
					}
					OneMasJ = OneMasJ / 10;
				}
				if ((OneMasI == OneMasJ) && (Imin == Jmin)) // sort3
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
	}
	else
	{
		cout << "File not found" << endl;
	}
}
*/

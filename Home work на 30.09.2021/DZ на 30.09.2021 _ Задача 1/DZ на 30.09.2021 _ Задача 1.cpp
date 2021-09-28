#include <iostream>
#include <fstream>
#include <math.h>

#define N 10000

using std::cout;
using std::endl;
using std::cin;
 // 1.	Дана последовательность натуральных чисел {aj}, j=1...n (n<=10000).
 // Если в последовательности нет ни одного простого числа, упорядочить последовательность по невозрастанию.
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №1" << endl;
	
	std::ifstream in("input.txt"); // Заданы рандомные числа другим проектом по таймеру на сервере (10000 чисел) - можно исправить для проверки без простых чисел
	std::ofstream out("output.txt"); 
	if (in)
	{
		bool f = false;
		int n,x;
		int mas[N];

		in >> n; // Кол-во чисел в последовательности считываем из первого числа файла

		for (int i = 0; i < n; i++)
		{
			in >> mas[i];
		}
		for (int i = 0; i < n; i++)
		{
			x = mas[i];
			for (int d = 2; d <= sqrt(x); d++)
			{
				if (x % d == 0)
				{
					f = true;
				}
				else
				{
					f = false;
					break;
				}
			}
		}
		if (!f)
		{
			out << "Среди последовательности было обнаружено простое число. Последовательность НЕ была отсортирована по невозрастанию: " << endl;
			for (int i = 0; i < n; i++)
			{
				out << mas[i] << " ";
			}
		}
		else
		{
			for (int i = 0; i < n - 1; i++)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (mas[i] <= mas[j])
					{
						std::swap(mas[i], mas[j]);
					}
				}
			}

			out << "Простых чисел обнаружено не было. Последовательность была отсортирована по невозрастанию: " << endl;

			for (int i = 0; i < n; i++)
			{
				out << mas[i] << " ";
			}
		}
		return 0;
	}
	else
	{
		cout << "File not found" << endl;
	}
}

#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::cin;

// 3.	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 28.10.2021(8.2). Кондратьев Виталий, 4 вариант." << endl;
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		int n, m, summin = INT_MAX, sum = 0, stringmin = 0;
		in >> n >> m; // кол-во строк и столбцов в матрице считываем из файла

		// Создаём динамический массив
		int** matrix = new int*[n]; // задаём двумерерный массив с n-строк, подразумевая, что в каждой строчке есть ещё строки(столбцы)
		for (int i = 0; i < n; i++)
		{
			matrix[i] = new int[m]; // задаём к каждой строке ещё строки(столбцы)
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				in >> matrix[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				sum = sum + matrix[i][j];
			}
			if (summin > sum)
			{
				stringmin = i;
				summin = sum;
			}
			sum = 0;
		}

		for (int i = stringmin; i <= stringmin; i++)
		{
			for (int j = 0; j < m; j++)
			{
				matrix[i][j] = summin;
			}
		}

		out << "Минимальная сумма в строке = " << summin << endl;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				out << matrix[i][j] << " ";
			}
			out << endl;
		}

		// Очищаем память от динамического массива
		for (int i = 0; i < n; i++)
		{
			delete[] matrix[i]; // удаляем столбцы
		}
		delete[] matrix; // удаляем строки

	}
	else
	{
		cout << "File not found" << endl;
	}
}
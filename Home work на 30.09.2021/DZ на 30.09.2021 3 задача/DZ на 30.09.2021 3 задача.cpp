#include <iostream>
#include <fstream>

#define N 100
#define M 100

using std::cout;
using std::endl;
using std::cin;

// 3.	Дана целочисленная матрица {Aij}i=1..n,j=1..m (n,m<=100). Найти строку с наименьшей суммой элементов и заменнить все элементы этой строки этой суммой.
int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Лабораторная работа на 30.09.2021. Кондратьев Виталий, 4 вариант. Задача №3" << endl;
	std::ifstream in("input.txt"); 
	std::ofstream out("output.txt");
	if (in)
	{
		int n, m, summin = INT_MAX, sum = 0, stringmin = 0;
		in >> n >> m; // кол-во строк и столбцов в матрице считываем из файла
		int matrix[N][M];
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
	}
	else
	{
		cout << "File not found" << endl;
	}
}
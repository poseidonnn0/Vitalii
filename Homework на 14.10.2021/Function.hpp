#pragma once
#include <math.h>
#include <iostream>

namespace VK
{ 

	void Read(int& n, int& m, int mas[100][100]); // Процедура(функция) ввода элементов в матрицу

	void Write(int n, int m, int mas[100][100]); // Функция вывода элементов матрицы

	int MinNumber(int n, int m, int mas[100][100]); // Поиск минимального элемента в матрице

	bool EqualMin(int n, int m, int mas[100][100]); // Поиск элементов равных минимальному элементу

	bool PrimeNumber(int n, int m, int mas[100][100]); // Поиск двух элементов, абсолютные величины которых - простые числа

	void SWAP(int& a, int& b); // Функция перестановки элементов в матрице

	void SortMas(int& n, int& m, int mas[100][100]); // Функция сортировки элементов в строках матрицы
}




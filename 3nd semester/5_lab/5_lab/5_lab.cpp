#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №5 Вставками */

void insertionSort(std::vector <int>& array)
{
	int key, j;
	for (int i = 1; i < array.size(); i++)
	{
		key = array[i];
		j = i - 1;

		while (j >= 0 && array[j] > key)
		{
			array[j + 1] = array[j];
			j = j - 1;
		}
		array[j + 1] = key;
	}
}
//Асимптотика в среднем и худшем случае – O(n2), в лучшем – O(n).
int main()
{
	srand(static_cast <unsigned int> (time(0))); // Время сис. часов(где компилируют)
	setlocale(LC_ALL, "RUS");
	int N;
	std::vector <int> mas;
	std::cout << "Введите число рандомных чисел в массиве = ";
	std::cin >> N;
	for (int i = 0; i < N; i++)
	{
		mas.push_back(rand());
	}
	std::cout << "\nМассив чисел без сортировки:\n";
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "\nМассив чисел после сортировки:\n";
	insertionSort(mas);
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
}

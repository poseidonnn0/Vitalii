#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №6 Сортировка выбором */

void SelectionSort(std::vector <int>& array)
{
	for (int i = 0; i < array.size()-1; i++)
	{
		int jMin = i;
		for (int j = i + 1; j < array.size(); j++)
		{
			if (array[j] < array[jMin])
			{
				jMin = j;
			}
		}
		if (jMin != i)
		{
			std::swap(array[i], array[jMin]);
		}
	}
}

//Асимптотика: O(n2) в лучшем, среднем и худшем случае.
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
	SelectionSort(mas);
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
}

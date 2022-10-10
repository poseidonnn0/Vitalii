#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №7 Сортировка Шелла */
// Мой случай Худшее время - O(n^2), лучшее - O(n*log^2(n), среднее время зависит от шага gap (случаи ниже).
void shellSort(std::vector <int>& array)
{
    for (int gap = array.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < array.size(); i += 1)
        { 
            int temp = array[i];

            int j;
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
			{
				array[j] = array[j - gap];
			}

            array[j] = temp;
        }
    }
}

/*Асимптотика в худшем случае – O(n^2). Последовательность Хиббарда – 2n — 1, асимптотика в худшем случае – O(n^(1,5)), 
последовательность Седжвика (формула нетривиальна, можете ее посмотреть по ссылке ниже) — O(n^(4/3)), 
Пратта (все произведения степеней двойки и тройки) — O(n*log^2(n)). */
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
	shellSort(mas);
	for (int i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
}

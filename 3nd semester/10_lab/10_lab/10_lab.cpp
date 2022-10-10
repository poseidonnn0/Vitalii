#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №10 Cортировка слиянием*/

/*
Сортировка слиянием.
Худшее время O = n*log(n);
Среднее время работы O = n*log(n);
Лучшее время работы O = n*log(n); тетта(n*log(n))

Емкостная в любом случае O(n)
*/
void Merge(int end, int start, std::vector<int>& mas, int middle)
{
	int count_mas = end + 1;
	int final = middle + 1;
	int k = start;
	int* buf = new int[count_mas];
	for (int i = start, j = final; i <= middle || j <= end; /*итераторы внутри тела цикла*/)
	{

		if (j > end || (i <= middle && mas[i] < mas[j]))
		{
			buf[k] = mas[i];
			i++;
		}
		else {
			buf[k] = mas[j];
			j++;
		}
		k++;
	}

	for (int j = start; j <= end; j++)
	{
		mas[j] = buf[j];
	}
	delete[] buf;
}


void Merge_Sort(int end, int start, std::vector<int>& mas)
{
	if (start < end)
	{
		int m = (start + end) / 2;
		Merge_Sort(m, start, mas);
		Merge_Sort(end, m + 1, mas);
		Merge(end, start, mas, m);
	}
}

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
	Merge_Sort(N-1, 0, mas);
    for (int i = 0; i < mas.size(); i++)
    {
        std::cout << mas[i] << " ";
    }
}

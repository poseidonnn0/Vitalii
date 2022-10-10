#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №11 Быстрая сортировка */

//Быстрая сортировка 
/*
Лучший случай - О(n*log2(n)) - обычное разделение(мой случай)
Средний случай - O(n*log2(n))
Худший случай - О(n^2)
*/
int Medium(int a, int b, std::vector<int>& mas)
{
	return ((rand() * rand()) % (b - a + 1) + a);
}
void q_sort(int a, int b, std::vector<int>& mas)
{
	if (a >= b)
	{
		return;
	}
	int m = Medium(a, b, mas);
	int k = mas[m];
	int l = a - 1;
	int r = b + 1;
	while (1) // while(true)
	{
		do
		{
			l++;
		} while (mas[l] < k);
		do
		{
			r--;
		} while (mas[r] > k);
		if (l >= r)
		{
			break;
		}

		std::swap(mas[l], mas[r]);

	}
	r = l;
	l--;
	q_sort(a, l, mas);
	q_sort(r, b, mas);
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
	q_sort(0, N-1, mas);
    for (int i = 0; i < mas.size(); i++)
    {
        std::cout << mas[i] << " ";
    }
}

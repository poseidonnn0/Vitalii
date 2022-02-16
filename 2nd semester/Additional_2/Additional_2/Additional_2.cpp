#include <iostream>
#include <chrono>

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
	std::chrono::time_point<clock_t> m_beg;
public:
	Timer() : m_beg(clock_t::now())
	{
	}
	void reset()
	{
		m_beg = clock_t::now();
	}
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};
/*
Сортировка слиянием.
Худшее время O = n*log(n);
Среднее время работы O = n*log(n);
Лучшее время работы O = n*log(n); тетта(n*log(n))
*/
void Merge(int end, int start, int* mas, int middle)
{
	int count_mas = end + 1;
	int final = middle + 1;
	int k = start;
	int* buf = new int[count_mas];
	for (int i = start, j = final; i <= middle || j <= end; /*итераторы внутри тела цикла*/)
	{

		if (j>end || (i<=middle && mas[i]<mas[j]))
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


void Merge_Sort(int end, int start, int* mas)
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
	int n;

	setlocale(LC_ALL, "Rus");


	std::cout << "Введите количество переменных для обследования данных: ";
	std::cin >> n;
	int* mas = new int[n]; // Создаём динамический массив данных типа int 
	for (int i = 0; i < n; i++)
	{
		mas[i] = rand() % 1000 + 1;
	}

	std::cout << "Массив до сортировки: ";
	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "\n\n";
	Timer merge_sort_timer;
	Merge_Sort(n-1, 0, mas);
	std::cout << "Количество времени затраченного на сортировкой слиянием = " << merge_sort_timer.elapsed() << " секунд." << "\n\nМассив после сортировки :";
	for (int i = 0; i < n; i++)
	{
		std::cout << mas[i] << " ";
	}
	delete[] mas;
	return 0;
}


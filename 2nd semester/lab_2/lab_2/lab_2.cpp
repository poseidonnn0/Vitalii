#include <iostream>
#include <chrono>

int mas[10000000];

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

// Сортировка пузырьком

/*
Лучший случай - O(n)
Худший случай - O(n^2)
*/
void bubble_sort(int* mas, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if (mas[j] > mas[j + 1])
			{
				std::swap(mas[j], mas[j + 1]);
			}
		}
	}
}

int Medium(int end, int start, int* mas)
{
	return (rand() % (start - end + 1) + end);
}


//Быстрая сортировка 
/*
Лучший случай - О(n*log2(n)) - обычное разделение(мой случай)
Средний случай - O(n*log2(n))
Худший случай - О(n^2)
*/
void q_sort(int end, int start, int* mas)
{
	if (end >= start)
	{
		return;
	}
	int m = Medium(end, start, mas);
	int k = mas[m];
	int l = end - 1;
	int r = start + 1;
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
	q_sort(end, l, mas);
	q_sort(r, start, mas);
}


int main()
{
	int N;

	setlocale(LC_ALL, "Russia");

	std::cout << "Введите количество переменных для обследования данных: ";
	std::cin >> N;
	int* mas = new int[N]; // Создаём динамический массив данных типа int 

	for (int i = 0; i < N; i++)
	{
		mas[i] = rand() % 1000+1;
	}

	int* mas_bubble = mas; // mas for bubble_sort
	int* mas_q = mas; // mas for q_sort

	Timer bubble_sort_timer;
	bubble_sort(mas_bubble, N);
	std::cout << "Затрачено времени при вызове bubble_sort: " << bubble_sort_timer.elapsed() << " секунд, при вызове кол-ва переменных = " << N << '\n' << '\n';
	Timer q_sort_timer;
	q_sort(0, N - 1, mas_q);
	std::cout << "Затрачено времени при вызове q_sort: " << q_sort_timer.elapsed() << " секунд, при вызове кол-ва переменных = " << N << '\n'; // быстрее!

	delete[] mas;
	return 0;
}

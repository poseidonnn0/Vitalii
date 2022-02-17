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

// Сортировка пузырьком

/*
Лучший случай - O(n)
Худший случай - O(n^2)
*/
void bubble_sort(int* mas, int N)
{
	for (int i = 1; i < N; i++)
	{
		if (mas[i] >= mas[i - 1])
		{
			continue;
		}
		int j = i - 1;
		while ((j >= 0) && (mas[j] > mas[j + 1]))
		{
			std::swap(mas[j], mas[j + 1]);
			j--;
		}
	}

}

int Medium(int a, int b, int* mas)
{
	return ((rand() * rand()) % (b-a+1) + a);
}


//Быстрая сортировка 
/*
Лучший случай - О(n*log2(n)) - обычное разделение(мой случай)
Средний случай - O(n*log2(n))
Худший случай - О(n^2)
*/
void q_sort(int a, int b, int* mas)
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
	int N;

	setlocale(LC_ALL, "Rus");

	std::cout << "Введите количество переменных для обследования данных: ";
	std::cin >> N;
	int* mas_bubble = new int[N]; // Создаём динамический массив данных типа int 
	int* mas_q = new int[N]; // Создаём динамический массив данных типа int 

	for (int i = 0; i < N; i++)
	{
		mas_bubble[i] = rand() % 1000+1;
	}
	for (int i = 0; i < N; i++)
	{
		mas_q[i] = rand() % 1000 + 1;
	}


	Timer bubble_sort_timer;
	bubble_sort(mas_bubble, N);
	std::cout << "Затрачено времени при вызове bubble_sort: " << bubble_sort_timer.elapsed() << " секунд, при вызове кол-ва переменных = " << N << '\n' << '\n';
	for (int i = 0; i < N; i++)
	{
		std::cout << mas_bubble[i] << " ";
	}
	std::cout << "\n\n";
	Timer q_sort_timer;
	q_sort(0,N-1, mas_q);
	std::cout << "Затрачено времени при вызове q_sort: " << q_sort_timer.elapsed() << " секунд, при вызове кол-ва переменных = " << N << "\n\n"; // быстрее!


	for (int i = 0; i < N; i++)
	{
		std::cout << mas_q[i] << " ";
 	}

	delete[] mas_bubble;
	delete[] mas_q;
	return 0;
}

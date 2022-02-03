#include <iostream>
#include <cstdlib>
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

int A[100000000];

int main()
{
	int N;
	setlocale(LC_ALL, "Rus");
	std::cout << "Последовательность состоит из чисел N = ";
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 31;
	}

	////Худший случай
	/*for (int i = 0; i < N; i++)
	{
		if (i < 9999998)
		{
			A[i] = 2;
		}
		else
		{
			A[i] = 1;
		}
	}*/

	/* Проверка на то, какие числа задаются в последовательности
	for (int i = 0; i < N; i++)
	{
		std::cout << A[i] << " ";
	}
	std::cout << '\n';
	*/

	Timer test;
	//std::cout << '\n' << "Время до поиска: " << test.elapsed() << '\n';
	//Поиск номера первого нечётного числа
	
	for (int i = 0; i < N; i++)
	{
		if (A[i] % 2 != 0) // Перебор в худшем случае по тетта от N. Т.к. вложенных циклов или проверок - нет. Простая проверка по "прогоняемому" циклу.
		{
			std::cout << "Номер первого нечётного числа = " << i + 1;
			break;
		}
	}

	std::cout << '\n' << "Время после поиска нечётного числа: " << test.elapsed() << '\n';

	return 0;
}


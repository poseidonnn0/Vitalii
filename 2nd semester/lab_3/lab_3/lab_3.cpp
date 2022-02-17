#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>
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

int Search_enumeration(std::vector<int>&vec, int key)
{
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == key)
		{
			return 1;
		}
	}
	return -1;
}

int Search_binary(std::vector<int>& vec, int key)
{
	int left = 0;
	int right = vec.size();
	int middle;
	while (left<=right)
	{
		middle = (left + right) / 2;
		if (key < vec[middle])
		{
			right = middle - 1;
		}
		else if (key > vec[middle])
		{
			left = middle + 1;
		}
		else /*if (key == vec[middle])*/
		{
			return 1;
		}
	}
	return -1;
}

double f(double x)
{
	return (x - 3) * (x - 3) * (x - 3);
}
double Bisection(double start, double end, double ex)
{
	if (f(start) == 0)
	{
		return start;
	}
	if (f(end) == 0)
	{
		return end;
	}
	while (end - start > ex) // Точность результата
	{
		if (f(start) * f((end + start) / 2) == 0)
			break;
		else if (f(start) * f((end + start) / 2) > 0)
			start = (end + start) / 2;
		else
			end = (end + start) / 2;
	}
	return (end + start) / 2;
}


int main()
{
	setlocale(LC_ALL, "Rus");

	std::vector<int> vec;
	std::vector<int> vec_M;
	const int N = 99999;
	const int M = 9999;

	for (int i = 0; i < N; i++)
	{
		vec.push_back(rand()% N - N / 10);
		//vec.push_back(i);
	}

	for (int i = 0; i < M; i++)
	{
		vec_M.push_back(rand() % M + M/10);
		// vec_M.push_back(rand()%N + N/100 - 1000);
		// vec_M.push_back(i);
	}
	std::sort(vec.begin(), vec.end());
	//std::sort(vec_M.begin(), vec_M.end());
	for (int i = 0; i < vec.size(); i++)
	{
		//std::cout << vec[i] << " ";
	}
	//std::cout << "\n\n";
	for (int i = 0; i < vec_M.size(); i++)
	{
		//std::cout << vec_M[i] << " ";
	}
	//std::cout << '\n';
	Timer search_binary_timer;
	for (int i = 0; i < vec_M[i]; i++)
	{
		if (Search_binary(vec, vec_M[i]) == 1)
		{
			//std::cout << "Элемент vec_M[i] = " << vec_M[i] << " под индексом i = " << i <<'\n';
		}
	}
	std::cout << "Время затраченное на бинарный поиск(Search_Binary): " << search_binary_timer.elapsed() << " секунд.\n";
	Timer search_enumeration_timer;
	for (int i = 0; i < vec_M[i]; i++)
	{
		if (Search_enumeration(vec, vec_M[i]) == 1)
		{
			//std::cout << "Элемент vec_M[i] = " << vec_M[i] << " под индексом i = " << i << '\n';
		}
	}
	std::cout << "Время затраченное на поиск перебором(Search_enumeration): " << search_enumeration_timer.elapsed() << " секунд.\n";

	std::cout << "----------" << '\n';
	std::cout << "Бисекция для (x-3)^3 = 0 ---> " << Bisection(-10, 10, 0.0001); // ответ 2.9999 ----> 3
	std::cout << "\n----------" << '\n';

	return 0;
}

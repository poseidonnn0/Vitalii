#include <iostream>
#include <chrono>
#include "func.hpp"
#include <vector>
// Лаб. работа №4
//Вариант 4.
//Создайте односвязный список из 10000 целых чисел и реализуйте в нем операцию вставки элемента k в конец списка. Выполните M = 1000 таких запросов.
//Реализуйте такую же операцию для массива.Сравните производительность.
using namespace func;

int main()
{
	T_List* head = new T_List;
	head->next = nullptr;

	const int N = 10000;
	const int M = 1000;
	int j = 0;
	for (int i = 0; i <= N; i++)
	{
		j += 1;
		ADD(head, j);
	}
	//PRINT(head);
	//std::cout << "-------" << '\n';
	Timer t1;
	for (int i = 0; i < M; i++)
	{
		ADD_LAST(head, 777);
	}
	std::cout << "List_ADD_Last_time = " << t1.elapsed() << '\n';
	//PRINT(head);
	//CLEAR(head);

	std::vector<int> mas;
	Timer t2;
	for (int i = 0; i < M; i++)
	{
		mas.push_back(777); // Вектор изначально добавляет элементы с конца
	}
	std::cout << "mas_time = " << t2.elapsed(); // Быстрее!
	delete head;
	return 0;

}

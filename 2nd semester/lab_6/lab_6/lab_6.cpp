#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <list>

//Лаб. работа №6 / Кондратьев Виталий

/* Вариант 4.
Подобрать структуру для хранения данных, если известно, что операции поиска, удаления и дублирования будут осуществляться примерно в равных количествах.
*/

// Задача(своя). Дана последовательность неповторяющихся натуральных чисел, получаемых из файла. (Работать уже с полученным массивом из файла).
// (1). Найти первый элемент в массиве данных, кратный 3. 
// (2). Продублировать элемент из условия (1) в начало.
// (3). Вывести массив, удалить элемент, который был продублирован и вывести снова.


// Не используется бинарное дерево, т.к. имеется дублирование, а это нарушает "уникальность" элемента, т.е. ключа. 


bool fn(int n)
{
	if (n % 3 == 0)
	{
		return true;
	}
	return false;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	std::ifstream in("input.txt");
		
	std::list<int> list;
	int d;
	while (!in.eof())
	{
		in >> d;
		list.push_back(d);
	}
	// поиск
	//std::cout << *std::find_if(list.begin(), list.end(), fn); // O(n)
	for (auto& i : list)
	{
		std::cout << i << " ";
	}
	std::cout << "\n-----";
	if (*std::find_if(list.begin(), list.end(), fn))
	{
		list.insert(list.begin(), 1, *std::find_if(list.begin(), list.end(), fn)); // Поиск + дублирование (O(1) + O(n))
	}
	std::cout << '\n';
	for (auto& i : list)
	{
		std::cout << i << " ";
	}
	std::cout << "\n-----";
	list.erase(list.begin()); // O(1)
	std::cout << '\n';
	for (auto& i : list)
	{
		std::cout << i << " ";
	}


	return 0;
}

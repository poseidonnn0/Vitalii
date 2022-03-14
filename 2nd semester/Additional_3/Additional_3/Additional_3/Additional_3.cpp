#include <iostream>

#include "List.hpp"

int main()
{
	setlocale(LC_ALL, "Rus");
	List head;
	int N = 20;
	for (int i = 0; i < N; i++)
	{
		head.AddEnd(i);
	}
	int pos;
	std::cout << "Введите позицию задаваемого значения в списке из " << N << " элементов: ";
	std::cin >> pos;
	std::cout << std::endl;
	head.Insert(pos);


	head.ShowList();

	head.COUNT();
	
	std::cout << "\nВведите позицию удаляемоего значения в списке из " << N << " элементов: ";
	int del;
	std::cin >> del;
	head.Del(del);

	std::cout << std::endl;
	head.ShowList();

	head.COUNT();

	head.CLEAR(); // Удаление всех элементов списка. 

	//head.ShowList(); 

	//delete head прописан в деструкторе класса

	return 0;
}
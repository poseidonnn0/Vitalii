#include <iostream>
#include <string>
#include "SomeFunctions.hpp"

#define N 10000

//Строкой
//Динамический массив?

int main()
{
	// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
	// Удалить из последовательности числа, произведение цифр которых равно 144, а среди оставшихся продублировать числа, содержащие цифру 8.

	setlocale(LC_ALL, "Rus");
	int n;
	std::cout << "Введите количество чисел в последовательности натуральных чисел = ";
	std::cin >> n;
	int mas[N];
	VK::Read(n, mas);
	for (int i = 0; i < n; i++)
	{
		if (!VK::ProductDigits(mas[i]))
		{
			VK::Write1(mas[i]);
			//std::delete(mas[i]); ???
		}
		if ((VK::PresenceDig8(mas[i])) && (!VK::ProductDigits(mas[i])))
		{
			VK::Write1(mas[i]);
		}
	}
	
	return 0;
}
    //std::string s;
	//std::copy(mas, mas + 2, mas + 1);
	//std::cout << s;
	// delete[] mas;
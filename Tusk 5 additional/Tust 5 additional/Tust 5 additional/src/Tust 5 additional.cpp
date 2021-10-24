#include <iostream>
#include <string>
#include <SomeFunctions.hpp>


//Строкой
//Динамический массив?


void Read(int& n, int* mas)
{
	for (int i = 0; i < n; i++)
	{
		mas[i] = i + 1;
	}
}


void Write1(int& n)
{
	std::cout << n << " ";
}


bool ProductDigits(int n)
{
	int product = 1;
	while (n != 0)
	{
		product *= n % 10;
		n /= 10;
	}

	if (product == 144)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool PresenceDig8 (int n) // Проверка на наличие цифры 8 в числе
{
	int dig = 0;
	while (n != 0)
	{
		dig = n % 10;
		if (dig == 8)
		{
			return true;
		}
		n = n / 10;
	}
}


int main()
{
	// Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). 
	// Удалить из последовательности числа, произведение цифр которых равно 144, а среди оставшихся продублировать числа, содержащие цифру 8.

	setlocale(LC_ALL, "Rus");
	int n;
	std::cout << "Введите количество чисел в последовательности натуральных чисел = ";
	std::cin >> n;
	int mas[N];
	Read(n, mas);
	//Write(n, mas);   
	for (int i = 0; i < n; i++)
	{
		if (!ProductDigits(mas[i]))
		{
			Write1(mas[i]);
			//std::delete(mas[i]);
		}
		if ((PresenceDig8(mas[i])) && (!ProductDigits(mas[i])))
		{
			Write1(mas[i]);
		}
	}
	
	return 0;
}
    //std::string s;
	//std::copy(mas, mas + 2, mas + 1);
	//std::cout << s;
	// delete[] mas;
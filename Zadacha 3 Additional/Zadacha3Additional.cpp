#include <iostream>
#include <math.h>
#include "Functions.hpp"



int main()
{
	int n;
	setlocale(LC_ALL, "Rus");
	VK::Read(n); 
	std::cout << "Максимальная цифра числа = " << VK::MaxDigit(n) << std::endl;
	VK::Repeat(n);
	std::cout << std::endl; 
	std::cout << "Sum = " << VK::sumDigit(n);
}


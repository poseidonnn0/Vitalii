#pragma once
#include <iostream>


namespace VK 
{
	void Read(int& n, long int* mas); // Ввод элементов (нат. последовательности)
	void Write(int& n, long int* mas); // Вывод элементов 
	int ProductDigits(int n); // Проверка на наличие произведение = 144
	bool PresenceDig8(int n); // Проверка на наличие цифры 8 в числе
}


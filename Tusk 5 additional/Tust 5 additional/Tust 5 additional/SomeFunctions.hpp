#pragma once
#include <iostream>


namespace VK 
{
	void Read(int& n, int* mas); // Ввод элементов (нат. последовательности)
	void Write1(int& n); // Вывод одного элемента массива
	bool ProductDigits(int n); // Проверка на наличие произведение = 144
	bool PresenceDig8(int n); // Проверка на наличие цифры 8 в числе
}


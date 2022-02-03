#include <iostream>
#include <fstream>

const int countNumbers = 1000;

int MaxNumber(int *mas, int start, int countNubmers) // 
{
	int NumberNext;
	if (start == countNubmers-1) // 1000 - 1 → 0-999 элементы в массиве, не включая 1000
	{
		return start;
	}
	NumberNext = MaxNumber(mas, start + 1, countNubmers);
	if (mas[NumberNext] > mas[start])
	{
		return NumberNext;
	}
	else return start;
}

int main()
{
	std::ifstream in("output.txt");
	int mas[countNumbers];
	for (int i = 0; i < countNumbers; i++)
	{
		in >> mas[i];
	}
	int max =  MaxNumber(mas, 0, countNumbers);
	std::cout << "INDEX max = " << max << "\nmas[max] = " << mas[max] << '\n';
}


#include <iostream>
#include <string>

int SumElements(int n, char mas[6])
{
	std::fill(mas, mas + 6, 0);
	int k = n;
	int count = 0;
	while (k != 0)
	{
		mas[count] = k % 10;
		k /= 10;
		count++;
	}
	if (mas[0] + mas[1] + mas[2] == mas[3] + mas[4] + mas[5])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	char s[6];
	int kol = 0;
	for (int i = 0; i <= 999999; i++)
	{
		if (SumElements(i, s))
		{
			kol++;
		}
	}
	std::cout << "Кол-во счастливых билетов = " << kol << std::endl;
}

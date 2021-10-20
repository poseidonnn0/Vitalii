#include <iostream>
#include <windows.h>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	// 1.	Дана строка длиной не более 100 символов. Удалить в ней все согласные буквы.
	std::fstream in("input.txt");
	std::ofstream out("output.txt");
	if (in)
	{
		cout << "Лабораторная работа на 07.10.2021. 4 вар. Кондратьев Виталий. Задача №1" << '\n' << '\n';
		char st[100];
		while (!in.eof())
		{
			in.getline(st, 100);
			cout << st << endl;
			
			for (int i = 0; i < strlen(st); i++)
			{
				if ((st[i] == 'а') || (st[i] == 'о') || (st[i] == 'А') || (st[i] == 'О') || (st[i] == 'Э') ||
					(st[i] == 'э') || (st[i] == 'е') || (st[i] == 'Е') || (st[i] == 'Ё') || (st[i] == 'И') ||
					(st[i] == 'и') || (st[i] == 'ы') || (st[i] == 'Ы') || (st[i] == 'Ю') || (st[i] == 'У') ||
					(st[i] == 'у') || (st[i] == 'ё') || (st[i] == 'Я') || 
					(st[i] == 'ю') || (st[i] == 'я') || (st[i] == ' ') || /*пробел между словами в строке*/
					(st[i] == 'Ь') || (st[i] == 'Ъ') || (st[i] == 'ь') || (st[i] == 'ъ')) // Ь и Ъ не являются согласными буквами, а являются звуками, поэтому тоже оставляем их
				{
					out << st[i];
				}
			}
		}
		return 0;
	}
	else
	{
		cout << "File not found" << endl;
	}
}


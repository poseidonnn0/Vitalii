#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    setlocale(LC_ALL, "Rus");
    int A, B, C;
    cout << "Лабораторная работа от 09.09.2021. Кондратьев Виталий, 4 вариант. Задание №1" << '\n';
    cout << "Введите натуральное число A = ";
    cin >> A;
    cout << "Введите натуральное число B = ";
    cin >> B;
    cout << "Введите натуральное число C = ";
    cin >> C;
    if ((A + B) % C == 0)
    {
        if (C % B == 0)
        {
            cout << "(A + B) / C - C / B = " << (A + B) / C - C / B << '\n'; // 15 3 18
        }
        else if (C % B != 0)
        {
            cout << "(A + B) / C + B * C = " << (A + B) / C + B * C << '\n'; // 10 20 30
        }
    }
    else
    {
        cout << "A - B + C = " << A - B + C << '\n';
    }
    return 0;

    /*if (((A + B) % C == 0) && (C % B == 0))
    {
        cout << "(A + B) / C - C / B = " << (A + B) / C - C / B << '\n'; // 15 3 18
    }
    else if (((A + B) % C == 0) && (C % B != 0))
    {
        cout << "(A + B) / C + B * C = " << (A + B) / C + B * C << '\n'; // 10 20 30
    }
    else
    {
        cout << "A - B + C = " << A - B + C << '\n';
    }*/
    // Если A+B кратно C и C кратно B, то вывести (A+B)/C-C/B, если A+B кратно C и C не кратно B, то вывести (A+B)/С+B*C, в остальных случаях вывести A-B+C.
}


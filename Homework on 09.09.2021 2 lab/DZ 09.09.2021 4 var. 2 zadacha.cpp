#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()

{
    setlocale(LC_ALL, "Rus");
    int N;
    cout << "Лабораторная работа от 09.09.2021, Кондратьев Виталий, 4 вариант, Задача №2" << '\n';
    cout << "Введите число N = ";
    cin >> N;
    switch (N)
    {
        case 0: cout << "Всё хорошо";
            break;
        case 1: cout << "Ошибка чтения файла" << '\n';
            break;
        case 2: cout << "Ошибка записи файла" << '\n';
            break;
        case 3: cout << "Не все поля определены" << '\n';
            break;
        default:
            cout << "Такой цифры/числа нет." << '\n';
    }
}

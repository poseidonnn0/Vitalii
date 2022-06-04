#include <iostream>
#include <string>
#include <algorithm>
#include "SomeFunctions.hpp"

#define N 20000

int main()
{
    // Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000).
    // Удалить из последовательности числа, произведение цифр которых равно 144, а среди оставшихся продублировать числа, содержащие цифру 8.

    setlocale(LC_ALL, "Rus");
    int n, j = 0;
    std::cout << "Введите количество чисел в последовательности натуральных чисел = ";
    std::cin >> n;
    int n2 = n * 2;
    long int mas[N];
    VK::Read(n, mas);
    for (int i = 0; i < n; i++)
    {
        if (VK::ProductDigits(mas[i]) == 144)
        {
            mas[i] = 0;
        }
        else
        {
            mas[j] = mas[i];
            j++;
        }
    }
    n = j;
    for (int i = n; i < n2; i++) { mas[i] = 0; }
    for (int i = 0; i < n; i++)
    {
        if (VK::PresenceDig8(mas[i]))
        {
            mas[n + i] = mas[i];
        }
    }
    std::sort(mas, mas + n2);
    VK::Write(n2, mas);
    return 0;
}
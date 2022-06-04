#include <iostream>
#include <algorithm>
#include "SomeFunctions.hpp"
#include <vector>

int main()
{
    // Дана последовательность натуральных чисел {Aj}j=1...n (n<=10000). Удалить из последовательности числа, произведение цифр которых равно 144, а среди оставшихся продублировать числа, содержащие цифру 8.
    setlocale(LC_ALL, "Rus");
    int n;
    std::cout << "Введите количество чисел в последовательности натуральных чисел = ";
    std::cin >> n;
    std::vector<int> mas;
    for (int i = 0; i < n; i++)
    {
        mas.push_back(i+1);
    }
    for (int i = 0; i < mas.size(); i++)
    {
        if (VK::ProductDigits(mas[i]) == 144)
        {
            mas.erase(mas.begin() + i);
        }
    }
    int n1 = mas.size();
    for (int i = 0; i < n1; i++)
    {
        if (VK::PresenceDig8(mas[i])) //  if (VK::PresenceDig8(mas.at(i))) // mas[i] можно заменить на mas.at(i)
        {
            mas.insert(mas.end(), mas[i]);
        }
    }
    sort(mas.begin(), mas.end()); // Сортировка вектора от его начала до конца (его размера)
    for (int i = 0; i < mas.size(); i++)
    {
        std::cout << mas[i] << " ";
    }
    return 0;
}
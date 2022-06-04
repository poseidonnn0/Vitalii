#include <iostream>
#include "Homemade_vector.hpp"


int main()
{
    int num,index; setlocale(LC_ALL, "Rus");
    std::cout << "Введите размер целочисленного вектора: ";
    std::cin >> num;
    VK::Vector vec(num);
    for (int i = 0; i < num; i++)
    {
        vec.VectorAddElement(i*2);
    }
    std::cout << '\n' << "Size Vec = " << vec.VectorSize();
    std::cout << '\n' << "Введите номер элемента вектора от 0 до " << num-1 << ", значение которого вы хотите узнать : ";
    std::cin >> index;
    std::cout << "<" << index << ">" << " элемент вектора = " << vec.VectorElementIndex(index) << std::endl;
    std::cout << "Сумма элементов вектора = " << vec.VectorSumElements() << '\n';
    int number;
    std::cout << "Введите число, которое хотите добавить в конец вектора: "; std::cin >> number;
    std::cout << "Вектор с добавленным значением выглядит следующим образом: ";
    vec.push_back(number);
    for (int i = 0; i <= num; i++)
    {
        std::cout << vec.VectorElementIndex(i) << " ";
    }
    std::cout << '\n' << "Сумма элементов обновлённого вектора = " << vec.VectorSumElements();
    std::cout << '\n' << "Size Vec = " << vec.VectorSize();
    return 0;
}

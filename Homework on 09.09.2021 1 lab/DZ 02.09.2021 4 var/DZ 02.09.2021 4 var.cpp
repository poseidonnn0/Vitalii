#include <iostream>
#include <iomanip>
int main()
{
    double S, R, PI; // # define M_PI ,  // 0 < R < 100
    setlocale(LC_ALL, "Rus");
    PI = acos(-1);
    std::cout << "Лаб. работа от 02.09.2021. Вариант 4. Кондратьев Виталий" << std::endl;
    std::cout << "Введите радиус круга: ";
    std::cin >> R; // вводим радиус круга
    S = R*R * PI; // Подсчитываем площадь круга
    std::cout << "Площадь заданного круга равна = " << std::setprecision(9) << S << std::endl; // Интепретируем запись всех выводов с точностью до 10^-9 и выводим площадь круга
    return 0;
}

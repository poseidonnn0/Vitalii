#include <cstdlib>
#include <iostream>
#include <ctime> // Для рандома по текущему серверному времени 
#include <fstream>
using std::endl;
using std::cin;
using std::cout;

int main()
{
    std::ofstream out("Random.txt");
    srand(static_cast <unsigned int> (time(0))); // Время сис. часов(где компилируют)

    setlocale(LC_ALL, "Rus");
    int n;
    cout << "Введите требуемое количество чисел для их создания в файле /Randomt.txt/" << endl;
    cin >> n;
    out << "Кол-во рандомных чисел = " << n << endl;
    for (int i = 0; i < n; i++)
    {
        out << rand() << " ";
    }
}

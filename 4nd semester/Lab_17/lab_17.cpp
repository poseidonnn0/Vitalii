#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream infile; // создание потока ifstream для чтения файла
    std::ofstream outfile; // создание потока ofstream для записи файла
    infile.open("input.txt"); // открытие файла с входными данными
    outfile.open("output.txt"); // создание файла для вывода результата

    int n; // количество предметов
    int V; // объем ящика
    infile >> n >> V; // считываем количество предметов и объем ящика
    std::vector<int> w(n); // массив для хранения объемов предметов

    for (int i = 0; i < n; i++)
    {
        infile >> w[i]; // считываем объем предметов
    }

    std::sort(w.begin(), w.end()); // сортируем предметы по объему

    int count = 0; // счетчик ящиков
    int sum = 0; // суммарный объем размещенных предметов
    for (int i = 0; i < n; i++)
    {
        if (sum + w[i] <= V)
        { // если текущий предмет помещается в ящик
            sum += w[i]; // добавляем объем предмета к общему объему
        }
        else
        { // если текущий предмет не помещается в ящик
            count++; // добавляем еще один ящик
            sum = w[i]; // начинаем собирать новый ящик
        }
    }

    if (sum > 0)
    { // если завершение нескольких ящиков неполное
        count++; // добавляем еще один ящик
    }

    outfile << "Минимальное количество ящиков необходимо: " << count << "\nУчитывая то, что всего ящиков = "
        << n << ", а объём одного ящика = " << V << std::endl; // выводим минимальное количество ящиков

    infile.close(); // закрытие потока ввода
    outfile.close(); // закрытие потока вывода
    return 0;
}

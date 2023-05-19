#include <iostream>
#include <fstream>
#include <vector>

const int MAXN = 1000; // максимальное количество вершин в графе
std::vector<int> path; // эйлеров цикл
int n; // количество вершин в графе
int a[MAXN][MAXN]; // матрица смежности

 // функция поиска эйлерова цикла
void find_euler_cycle(int v)
{
    for (int u = 0; u < n; ++u)
    {
        if (a[v][u] > 0)
        {
            a[v][u] -= 1; // удаляем это ребро из графа
            a[u][v] -= 1;
            find_euler_cycle(u); // продолжаем обход из этой вершины
        }
    }
    path.push_back(v + 1); // добавляем вершину в путь
}


int main() 
{
    std::ifstream fin("input.txt"); // открытие файла с данными на чтение
    fin >> n; // считывание количества вершин
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            fin >> a[i][j]; // считываем матрицу смежности
        }
    }
    fin.close(); // закрытие файла с данными
    int start = 0;
    for (int i = 0; i < n; ++i)
    {
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            sum += a[i][j];
        }
        if (sum % 2 == 1) 
        { // если степень вершины нечетная,
            std::cout << "No" << std::endl; // цикл невозможен
            return 0;
        }
        if (sum > 0) 
        {
            start = i; // начинаем обход из этой вершины
        }
    }

    find_euler_cycle(start); // Эйлеровов цикл(запускаем)

    std::ofstream fout("output.txt"); // открытие файла для вывода

    if (path.size() == 1)
    { // случай, когда граф состоит только из одной вершины
        fout << path[0];
    }
    else 
    { // случай, когда граф содержит несколько вершин
        for (int i = path.size() - 1; i >= 0; --i)
        {
            fout << path[i] << " "; // выводим путь в обратном порядке
        }
    }
    fout.close(); // закрытие файла для вывода

    return 0;
}
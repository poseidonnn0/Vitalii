#include <iostream>
#include <fstream>
#include <queue>
#include <vector>

const int maximum_N = 100; // максимальное количество вершин в графе

int n; // количество вершин в графе
int a[maximum_N][maximum_N]; // матрица смежности
bool used[maximum_N]; // массив для отслеживания пройденных вершин
std::vector<int> components[maximum_N]; // массив для хранения вершин в компонентах связности

void bfs(int v, int comp) // поиск в ширину
{
    std::queue<int> q;
    q.push(v);
    used[v] = true;
    components[comp].push_back(v);
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < n; i++) 
        {
            if (a[u][i] == 1 && !used[i]) 
            {
                used[i] = true;
                components[comp].push_back(i);
                q.push(i);
            }
        }
    }
}

int main() 
{
    std::ifstream fin("input.txt"); // открытие файла для чтения
    fin >> n; // считывание количества вершин
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fin >> a[i][j]; // считывание матрицы смежности
        }
    }
    fin.close(); // закрытие файла

    int comp = 0; // количество компонент связности
    for (int i = 0; i < n; i++) 
    {
        if (!used[i]) 
        {
            bfs(i, comp); // запуск поиска в ширину из не пройденной вершины
            comp++; // увеличение количества компонент связности
        }
    }
    std::ofstream fout("output.txt"); // открытие файла для записи
    fout << "Количество компонент связности: " << comp << std::endl; // запись количества компонент связности
    for (int i = 0; i < comp; i++) 
    {
        fout << "Компонента связности #" << i + 1 << ": ";
        for (int j = 0; j < components[i].size(); j++) 
        {
            fout << components[i][j] << " ";
        }
        fout << std::endl; // запись вершин в компоненте связности
    }
    fout.close(); // закрытие файла

    return 0;
}

// Задаём до разрывов. Когда относительно вершины все значения нули - то разрыв, следовательно новая компонента связности!
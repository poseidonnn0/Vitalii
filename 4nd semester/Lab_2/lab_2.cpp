// Найти в заданном графе кратчайшие пути из заданной вершины до всех остальных вершин с помощью поиска в ширину
#include <iostream>
#include <fstream>
#include <queue>

const int maximum_N = 100;
int n; // количество вершин в графе
int A[maximum_N][maximum_N]; // матрица смежности
int s; // исходная вершина
int dist[maximum_N]; // массив кратчайших расстояний до вершин
bool used[maximum_N]; // массив посещенных вершин
std::queue<int> q; // очередь для BFS

void BFS() 
{
    // инициализация массивов
    for (int i = 0; i < n; i++) 
    {
        dist[i] = -1;
        used[i] = false;
    }

    // обработка исходной вершины
    dist[s] = 0;
    used[s] = true;
    q.push(s);

    // обход в ширину
    while (!q.empty()) 
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++) 
        {
            // проверка наличия ребра
            if (A[u][v] == 1) 
            {
                // проверка, не посещали ли вершину ранее
                if (!used[v]) {
                    dist[v] = dist[u] + 1; // обновление расстояния
                    used[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

int main() {
    std::ifstream fin("input.txt"); // открытие файла с данными
    std::ofstream fout("output.txt"); // создание файла для результатов

    // чтение данных из файла
    fin >> n;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            fin >> A[i][j];
        }
    }

    BFS(); // поиск кратчайших путей из исходной вершины

    // вывод результата в файл
    for (int i = 0; i < n; i++) 
    {
        fout << dist[i] << " ";
    }
    fout << std::endl;
    fin.close(); // закрытие файла с данными
    fout.close(); // закрытие файла для результатов

    return 0;
}
 /*
 Алгоритм BFS работает следующим образом:
1. Инициализируем все вершины, кроме исходной, как не посещенные и расстояния до них как -1.
2. Помещаем исходную вершину в очередь и помечаем ее как посещенную, расстояние до нее равно 0.
3. Пока очередь не пуста, извлекаем первую вершину из очереди и для каждой ее соседней вершины делаем следующее:
- Если вершина еще не посещена, то помечаем ее как посещенную, сохраняем расстояние до нее (как расстояние до предыдущей вершины + 1) и помещаем в очередь.
4. По завершении алгоритма в массиве dist будут сохранены кратчайшие расстояния.
 */
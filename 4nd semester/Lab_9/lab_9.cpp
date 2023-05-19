#include <func.h>

int main() 
{
    std::ifstream fin("input.txt"); // открываем файл с матрицей смежности
    int n;
    fin >> n; // считываем количество вершин
    std::vector<std::vector<int>> graph(n, std::vector<int>(n)); // создаем матрицу смежности
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            fin >> graph[i][j]; // считываем веса ребер
        }
    }
    fin.close(); // закрываем файл

    std::vector<vitaliy::Edge> edges; // создаем вектор ребер
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (graph[i][j] != 0 && graph[i][j] != INF) 
            {
                edges.push_back({ i, j, graph[i][j] }); // добавляем ребро в вектор
            }
        }
    }

    std::vector<int> distances(n); // создаем вектор расстояний
    int start = 0; // выбираем начальную вершину

    vitaliy::BellmanFord(n, start, edges, distances); // вызываем функцию Беллмана-Форда

    std::ofstream fout("output.txt"); // открываем файл для вывода результата
    for (int i = 0; i < n; ++i) {
        fout << "Кратчайший путь из вершины " << start << " до вершины " << i << " : " << distances[i] << std::endl;
    }
    fout.close(); // закрываем файл

    return 0;
}

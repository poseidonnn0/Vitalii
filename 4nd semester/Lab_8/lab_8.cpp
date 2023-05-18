#include <func.h>

int main() 
{
    std::string filename = "input.txt"; // имя файла с матрицей смежности
    std::ifstream file(filename);

    int n;
    file >> n; // считываем количество вершин

    std::vector<std::vector<int>> graph(n, std::vector<int>(n)); // матрица смежности

    // считываем матрицу смежности из файла
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            file >> graph[i][j];
        }
    }

    file.close();

    int startVertex = 1; // номер стартовой вершины

    std::vector<int> distances(n, MAX_SIZE); // массив расстояний от стартовой вершины до каждой другой вершины
    vitaliy::dijkstra_algorithm(startVertex - 1, graph, distances); // запускаем алгоритм Дейкстры

    // выводим результаты в файл
    std::ofstream out("output.txt");

    for (int i = 0; i < distances.size(); i++) 
    {
        out << "Кратчайший путь из вершины " << startVertex << " до вершины " << i + 1 << ": ";
        if (distances[i] == MAX_SIZE) 
        {
            out << "no path" << std::endl;
        }
        else 
        {
            out << distances[i] << std::endl;
        }
    }

    out.close();

    return 0;
}
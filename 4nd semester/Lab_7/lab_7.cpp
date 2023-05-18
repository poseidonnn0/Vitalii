#include <func.h>

int main()
{
    std::ifstream fin("input.txt");

    int V;
    fin >> V;

    int** graph = new int* [V];
    for (int i = 0; i < V; i++)
        graph[i] = new int[V];

    // читаем матрицу смежности из файла
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            fin >> graph[i][j];
        }
    }

    vitaliy::find_mst(graph, V); // находим минимальное покрывающее дерево

    return 0;
}

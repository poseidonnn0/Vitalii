/*
* func.cpp
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/
#include "func.h"

namespace vitaliy
{
    // Функция для поиска вершины с минимальным ключом
    int find_min_key_vertex(std::vector<int> key, std::vector<bool> mst_set, int V)
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (mst_set[v] == false && key[v] < min)
                min = key[v], min_index = v;
        return min_index;
    }

    // Функция для печати результата
    void print_result(std::vector<int> parent, int** graph, int V)
    {
        int sum = 0;
        std::ofstream fout("output.txt");
        for (int i = 1; i < V; i++)
        {
            fout << parent[i] << " - " << i << "    " << graph[i][parent[i]] << std::endl;
            sum = graph[i][parent[i]] + sum;
        }
        fout << "\nМинимальный сумарный вес = " << sum;
    }

    // Функция для поиска минимального покрывающего дерева
    void find_mst(int** graph, int V)
    {
        std::vector<int> parent(V); // результат - минимальное покрывающее дерево
        std::vector<int> key(V, INT_MAX); // ключи для выбора минимального ребра
        std::vector<bool> mst_set(V, false); // множество вершин, включенных в минимальное покрывающее дерево

        key[0] = 0; // первая вершина всегда включена первой

        for (int count = 0; count < V - 1; count++)
        {
            int u = find_min_key_vertex(key, mst_set, V);

            mst_set[u] = true; // добавляем выбранную вершину в минимальное покрывающее дерево

            for (int v = 0; v < V; v++)
                if (graph[u][v] && mst_set[v] == false && graph[u][v] < key[v])
                    parent[v] = u, key[v] = graph[u][v]; // обновляем ключ и родительскую вершину
        }

        print_result(parent, graph, V);
    }

}
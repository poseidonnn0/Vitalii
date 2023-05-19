/*
* func.cpp
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/
#include "func.h"

namespace vitaliy
{
    // Сложность алгоритма O(EV),где V- кол-во вершин,а Е - кол-во ребер
    void BellmanFord(int n, int start, std::vector<Edge>& edges, std::vector<int>& distances) 
    {
        distances.assign(n, INF);
        distances[start] = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            for (int j = 0; j < edges.size(); ++j) 
            {
                int u = edges[j].from;
                int v = edges[j].to;
                int weight = edges[j].weight;
                if (distances[u] < INF) 
                {
                    distances[v] = std::min(distances[v], distances[u] + weight);
                }
            }
        }
    }


}

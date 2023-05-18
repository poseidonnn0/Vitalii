/*
* func.cpp
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/
#include "func.h"

namespace vitaliy
{

    void dijkstra_algorithm(int start, std::vector<std::vector<int>>& graph, std::vector<int>& dist)
    {
        std::vector<bool> visited(dist.size(), false); // массив для отслеживания посещения вершин
        dist[start] = 0; // расстояние до стартовой вершины равно 0

        for (int i = 0; i < dist.size() - 1; i++) 
        { // проходим по всем вершинам, кроме стартовой
            int minDist = MAX_SIZE;
            int minIndex = -1;

            for (int j = 0; j < dist.size(); j++) 
            { // ищем вершину с наименьшим расстоянием
                if (!visited[j] && dist[j] < minDist) 
                {
                    minDist = dist[j];
                    minIndex = j;
                }
            }

            if (minIndex == -1) 
            { // если нет непосещенных вершин, выходим из цикла
                break;
            }

            visited[minIndex] = true;

            for (int j = 0; j < dist.size(); j++) 
            { // обновляем расстояния до смежных вершин
                int weight = graph[minIndex][j];
                if (weight != 0 && dist[minIndex] != MAX_SIZE && dist[minIndex] + weight < dist[j]) 
                {
                    dist[j] = dist[minIndex] + weight;
                }
            }
        }
    }

}

/*
* func.cpp
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/
#include "func.h"

namespace vitaliy
{
    // Сравниваем ребра по возрастанию веса
    bool compare(const Edge& a, const Edge& b)
    {
        return a.weight < b.weight;
    }

    // Находим представителя множества для текущей вершины графа
    int find(std::vector<int>& parent, int i)
    {
        if (parent[i] == -1)
        {
            return i;
        }
        return find(parent, parent[i]);
    }
}
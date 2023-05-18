/*
* func.h
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/

#ifndef __FUNC_H__
#define __FUNC_H__
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

namespace vitaliy
{ // Структура, представляющая каждое ребро в графе

    struct Edge
    {
        int src, dest, weight;
    };

    bool compare(const Edge& a, const Edge& b);     // Сравниваем ребра по возрастанию веса
    int find(std::vector<int>& parent, int i);      // Находим представителя множества для текущей вершины графа
}
#endif
/*
* func.h
*
* @created 18.05.2023 Vitaliy Kondratev
*
*/

#ifndef __FUNC_H__
#define __FUNC_H__
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <limits.h>

namespace vitaliy
{ 
  // Функция для поиска вершины с минимальным ключом
    int find_min_key_vertex(std::vector<int> key, std::vector<bool> mst_set, int V);
    // Функция для печати результата
    void print_result(std::vector<int> parent, int** graph, int V);

    // Функция для поиска минимального покрывающего дерева
    void find_mst(int** graph, int V);

}
#endif
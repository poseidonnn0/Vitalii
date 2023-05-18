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
#include <vector>
#include <limits>

const int MAX_SIZE = 100;


namespace vitaliy
{ 
    void dijkstra_algorithm(int start, std::vector<std::vector<int>>& graph, std::vector<int>& dist);
}
#endif
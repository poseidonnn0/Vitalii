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
#include <algorithm>

const int INF = 1e9; // ���������, ������������ �������������


namespace vitaliy
{ 
    struct Edge
    {
        int from;
        int to;
        int weight;
    };

    // ��������� ��������� O(EV),��� V- ���-�� ������,� � - ���-�� �����
    void BellmanFord(int n, int start, std::vector<Edge>& edges, std::vector<int>& distances);

}
#endif
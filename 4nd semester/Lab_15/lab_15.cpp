//������ ������ � ��������� �����

//������ ���������� ������� Graph ����� �������, ����� ������� ��� �������� ������� �� ����� ���������� ����

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

// ��������� ������ ��� �������� ����� Graph
struct Edge 
{
    int src, dest;
};

class Graph
{
public:
    // ������ �������� ��� ������������� ������ ���������
    std::vector<std::vector<int>> adjList;

    // �����������
    Graph(std::vector<Edge> const& edges, int n)
    {
        // �������� ������ �������, ����� �� �������� `n` ��������� ���� `vector<int>`
        adjList.resize(n);

        // ��������� ����� � ����������������� graph
        for (Edge edge : edges)
        {
            int src = edge.src;
            int dest = edge.dest;

            adjList[src].push_back(dest);
            adjList[dest].push_back(src);
        }
    }
};

// ��������� ������ ������ ��� graphs � ������� ����������� ������
std::string color[] =
{
    "", "�����", "������", "�������", "Ƹ����", "���������", "�������",
    "׸����", "�����", "�����", "����������", "���������"
};

// ������� ��� ���������� ����� �������� Graph
void colorGraph(Graph const& graph, int n)
{
    // ����������� ����, ����������� ������ �������
    std::unordered_map<int, int> result;

    // ��������� ���� ������� ���� �� ������
    for (int u = 0; u < n; u++)
    {
        // ������������� ��� �������� ����� ������� ������ `u`
        std::set<int> assigned;

        // ��������� ����� ������� ������ `u` � ��������� �� � ������
        for (int i : graph.adjList[u])
        {
            if (result[i]) 
            {
                assigned.insert(result[i]);
            }
        }

        // ��������� ������ ��������� ����
        int color = 1;
        for (auto& c : assigned)
        {
            if (color != c) 
            {
                break;
            }
            color++;
        }

        // ��������� ������� `u` ������ ��������� ����
        result[u] = color;
    }

    for (int v = 0; v < n; v++)
    {
        std::cout << "����, ����������� ������� " << v << " = "
            << color[result[v]] << std::endl;
    }
}

// ������ ��������� Graph
int main()
{
    setlocale(LC_ALL, "Russian_Russia.1251");
    // vector ����� Graph �������� ����� ����
    std::vector<Edge> edges = 
    {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    // ����� ���������� ����� � Graph (�� 0 �� 5)
    int n = 6;

    // ������ graph �� �������� �����
    Graph graph(edges, n);

    // ������� Graph � �������������� ������� ���������
    colorGraph(graph, n);

    return 0;
}


/*
----- ������� ������ ----- 
����������, ��� ������� graph ����� ���������� ������ x �����, 
��� x ������������ ������� ����� ������� � Graph, 
�� ����������� ������ ������ � ������, ���������� ���� �������� �����, ��� ������� x+1 �����.


������ ��������� ������������� ������� Graph ��������������� � ����������� ������ ������� ���� ������ ��������� ����, 
�. �. ������� ��������������� � ������������ ������� v1, v2, � vn, � ����� vi � �������� ���������� ��������� ����, 
������� �� ������������ �� ����� �� vi ������.

������ ��������� �� ������ ���������� ���������� ��������� ���������� ������ ��� ��������� Graph. 
��� Graph ������������ ������� x, ������ ��������� ����� ������������ �� ����� x+1 ����. 
������ ��������� ����� ���� ����� ������ ������; ��������, ��������� �������� graph (������ ���������� graph), 
������� n ������� ����� ���� ������������, �� ������ ��������� �������� � n/2 �����.

*/
#include <func.h>

int main() 
{
    // Открываем файл с данными входной матрицы
    std::ifstream input("input.txt");

    int V; // Количество вершин в графе
    input >> V;

    //  Создаем матрицу смежности для хранения графа
    std::vector<std::vector<int>> graph(V, std::vector<int>(V));
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            input >> graph[i][j];
        }
    }
    input.close();

    // Создаем вектор ребер графа и заполняем его
    std::vector<vitaliy::Edge> edges;
    for (int i = 0; i < V; i++) {
        for (int j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                vitaliy::Edge e = {i, j, graph[i][j]};
                edges.push_back(e);
            }
        }
    }

    // Сортируем ребра по возрастанию веса
    sort(edges.begin(), edges.end(), vitaliy::compare);

    std::vector<int> parent(V, -1); // Вектор для хранения представителей множеств

    std::vector<vitaliy::Edge> result; // Результат - минимальное покрывающее дерево

    // Обходим все ребра и соединяем их, если они принадлежат различным множествам
    for (vitaliy::Edge e : edges)
    {
        int x = vitaliy::find(parent, e.src);
        int y = vitaliy::find(parent, e.dest);
        if (x != y) {
            result.push_back(e);
            parent[x] = y;
        }
    }

    // Сохраняем результат в файл
    std::ofstream output("output.txt");
    output << "Результат \nРебро, вес ребра: " << std::endl;
    int totalWeight = 0;
    for (vitaliy::Edge e : result)
    {
        output << e.src << " --- " << e.dest << ": " << e.weight << std::endl;
        totalWeight += e.weight;
    }
    output << "Суммарный вес: " << totalWeight << std::endl;
    output.close();

    return 0;
}

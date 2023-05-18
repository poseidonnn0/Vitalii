#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

// функция для чтения матрицы из файла
std::vector<std::vector<int>> readMatrixFromFile(std::string fileName) 
{
    std::ifstream file(fileName);
    int n;
    file >> n;
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

// функция для поиска компонент связности в графе (Функция для рекурсивного поиска в глубину)
void findConnectedComponents(std::vector<std::vector<int>>& graph, std::vector<int>& visited, int vertex, std::vector<int>& component) 
{ // DFS
    visited[vertex] = true;     // Помечаем вершину, как посещенную
    component.push_back(vertex);     // Добавляем вершину в текущую компоненту связности
    for (int i = 0; i < graph.size(); i++)      // Проходим по всем соседним вершинам
    {
        if (graph[vertex][i] == 1 && !visited[i]) 
        { // Если соседняя вершина не посещена и есть ребро между ней и текущей вершиной,
        // то выполняем поиск в глубину из этой вершины
            findConnectedComponents(graph, visited, i, component); 
        }
    }
}


int main() 
{
    std::string fileName = "input.txt";
    std::vector<std::vector<int>> graph = readMatrixFromFile(fileName);

    std::vector<int> visited(graph.size(), false); 
    std::vector<std::vector<int>> components;

    for (int i = 0; i < graph.size(); i++) 
    {
        if (!visited[i]) 
        {
            std::vector<int> component;
            findConnectedComponents(graph, visited, i, component); // DFS , поиск компонент связности
            components.push_back(component);
        }
    }

    std::ofstream outputFile("output.txt");
    outputFile << "Количество компонент связности(разрывов):  " << components.size() << std::endl;
    outputFile << "Состав компонент связности: " << std::endl;
    for (int i = 0; i < components.size(); i++) 
    {
        outputFile << "Компонента " << i + 1 << ": ";
        for (int j = 0; j < components[i].size(); j++) 
        {
            outputFile << components[i][j] << " ";
        }
        outputFile << std::endl;
    }
    outputFile.close();

    return 0;
}
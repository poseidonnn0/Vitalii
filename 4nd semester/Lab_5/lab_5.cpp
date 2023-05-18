// Код для поиска сильно связанных компонент в ориентированном графе
#include <iostream>
#include <fstream>
#include <vector>

// Функция для чтения матрицы смежности графа из файла и записи ее в двумерный вектор
std::vector<std::vector<int>> readMatrix(std::string fileName) 
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
    file.close();
    return matrix;
}

// Функция для обхода графа в глубину и добавления вершин в порядке, обратном времени закрытия
void dfs(int v, std::vector<bool>& visited, std::vector<int>& order, std::vector<std::vector<int>>& matrix) 
{
    visited[v] = true;
    for (int i = 0; i < matrix.size(); i++) 
    {
        if (matrix[v][i] && !visited[i]) 
        {
            dfs(i, visited, order, matrix);
        }
    }
    order.push_back(v);
}

// Функция для обхода транспонированного графа в глубину и добавления вершин в компоненту сильной связности
void dfsTranspose(int v, std::vector<bool>& visited, std::vector<int>& component, std::vector<std::vector<int>>& transposeMatrix) 
{
    visited[v] = true;
    component.push_back(v);
    for (int i = 0; i < transposeMatrix.size(); i++) 
    {
        if (transposeMatrix[v][i] && !visited[i]) 
        {
            dfsTranspose(i, visited, component, transposeMatrix);
        }
    }
}

// Функция для поиска всех сильно связанных компонентов в графе
std::vector<std::vector<int>> findStronglyConnectedComponents(std::vector<std::vector<int>>& matrix) 
{
    int n = matrix.size();
    std::vector<bool> visited(n);
    std::vector<int> order;
    // Обход графа в глубину и получение порядка вершин в порядке, обратном времени закрытия
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            dfs(i, visited, order, matrix);
        }
    }
    // Получение транспонированной матрицы смежности графа
    std::vector<std::vector<int>> transposeMatrix(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            transposeMatrix[i][j] = matrix[j][i];
        }
    }
    visited.assign(n, false);
    std::vector<std::vector<int>> result;
    // Обход вершин в порядке, обратном времени закрытия, и получение компонент сильной связности
    for (int i = n - 1; i >= 0; i--) 
    {
        int v = order[i];
        if (!visited[v]) 
        {
            std::vector<int> component;
            dfsTranspose(v, visited, component, transposeMatrix);
            result.push_back(component);
        }
    }
    return result;
}

// Функция для записи результатов поиска компонент сильной связности в файл
void writeResult(std::string fileName, std::vector<std::vector<int>>& result) 
{
    std::ofstream file(fileName);
    for (int i = 0; i < result.size(); i++) 
    {
        for (int j = 0; j < result[i].size(); j++) 
        {
            // Добавляем 1 к вершинам, чтобы матрицу смежности можно было задавать числами от 1 до n, а не от 0 до n-1
            file << result[i][j] + 1 << " ";
        }
        file << std::endl;
    }
    file.close();
}

int main() 
{
    std::string inputFileName = "input.txt";
    std::string outputFileName = "output.txt";
    // Чтение матрицы смежности из файла и поиск сильно связанных компонент
    std::vector<std::vector<int>> matrix = readMatrix(inputFileName);
    std::vector<std::vector<int>> result = findStronglyConnectedComponents(matrix);
    // Запись результатов в файл
    writeResult(outputFileName, result);
    return 0;
}
// ��� ��� ������ ������ ��������� ��������� � ��������������� �����
#include <iostream>
#include <fstream>
#include <vector>

// ������� ��� ������ ������� ��������� ����� �� ����� � ������ �� � ��������� ������
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

// ������� ��� ������ ����� � ������� � ���������� ������ � �������, �������� ������� ��������
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

// ������� ��� ������ ������������������ ����� � ������� � ���������� ������ � ���������� ������� ���������
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

// ������� ��� ������ ���� ������ ��������� ����������� � �����
std::vector<std::vector<int>> findStronglyConnectedComponents(std::vector<std::vector<int>>& matrix) 
{
    int n = matrix.size();
    std::vector<bool> visited(n);
    std::vector<int> order;
    // ����� ����� � ������� � ��������� ������� ������ � �������, �������� ������� ��������
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i]) 
        {
            dfs(i, visited, order, matrix);
        }
    }
    // ��������� ����������������� ������� ��������� �����
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
    // ����� ������ � �������, �������� ������� ��������, � ��������� ��������� ������� ���������
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

// ������� ��� ������ ����������� ������ ��������� ������� ��������� � ����
void writeResult(std::string fileName, std::vector<std::vector<int>>& result) 
{
    std::ofstream file(fileName);
    for (int i = 0; i < result.size(); i++) 
    {
        for (int j = 0; j < result[i].size(); j++) 
        {
            // ��������� 1 � ��������, ����� ������� ��������� ����� ���� �������� ������� �� 1 �� n, � �� �� 0 �� n-1
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
    // ������ ������� ��������� �� ����� � ����� ������ ��������� ���������
    std::vector<std::vector<int>> matrix = readMatrix(inputFileName);
    std::vector<std::vector<int>> result = findStronglyConnectedComponents(matrix);
    // ������ ����������� � ����
    writeResult(outputFileName, result);
    return 0;
}
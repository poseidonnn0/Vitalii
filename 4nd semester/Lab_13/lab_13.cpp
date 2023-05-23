#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// функция для создания таблицы смещений
void createOffsetTable(std::string pattern, std::vector<int>& offsetTable)
{
    int len = pattern.length();
    // инициализируем таблицу максимальным смещением
    for (int i = 0; i < 256; i++)
    {
        offsetTable[i] = len;
    }
    // находим смещения для символов образца
    for (int i = 0; i < len - 1; i++) 
    {
        offsetTable[pattern[i]] = len - i - 1;
    }
}

// функция для поиска образца в строке
void search(std::string text, std::string pattern, std::vector<int>& offsetTable, std::ofstream& outFile)
{
    int n = text.length();
    int m = pattern.length();
    int i = m - 1;
    // проходим по тексту с шагом, равным максимальному смещению
    while (i < n) 
    {
        int j = m - 1;
        // ищем совпадения с конца образца до начала
        while (text[i] == pattern[j]) 
        {
            // если образец полностью найден, выводим его позицию и выходим
            if (j == 0) 
            {
                outFile << i << std::endl; // если образец найден, выводим его позицию
                break;
            }
            i--;
            j--;
        }
        i += std::max(offsetTable[text[i]], m - j); // вычисляем новое смещение для продолжения поиска
    }
}

int main() 
{
    std::string text, pattern;
    std::vector<int> offsetTable(256);
    std::ifstream inFile("input.txt");
    std::ofstream outFile("output.txt");

    getline(inFile, pattern); // считываем образец из файла
    getline(inFile, text); // считываем строку из файла


    createOffsetTable(pattern, offsetTable); // создаем таблицу смещений
    search(text, pattern, offsetTable, outFile); // выполняем поиск образца в строке

    inFile.close();
    outFile.close();
    return 0;
}
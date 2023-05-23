#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Функция для создания префиксного массива из образца
std::vector<int> createPrefixArray(const std::string& pattern) 
{
    std::vector<int> prefixArray(pattern.size(), 0);

    for (int i = 1; i < pattern.size(); i++) 
    {

        int j = prefixArray[i - 1];

        while (j > 0 && pattern[i] != pattern[j]) 
        {
            j = prefixArray[j - 1];        
        }
        if (pattern[i] == pattern[j]) 
        {
            j++;
        }
        prefixArray[i] = j;
        std::cout << j << " ";
    }

    return prefixArray;
}


/*
Префикс-функция — это функция, которая для каждой позиции в строке, 
находит длину наибольшего собственного (включающего начальный символ, но не включающего конечный) 
суффикса, который также является префиксом этой же строки. 
Эта функция находит шаблоны в строках, а также используется в алгоритмах поиска подстроки и сжатия данных.
------------------
Где суффикс - это подстрока, которая оканчивается в данной позиции в строке и имеет длину,
меньшую или равную длине всей строки. Другими словами, если у нас есть строка S, 
то все ее суффиксы - это подстроки S, которые начинаются с произвольного символа S и идут до конца S. 
Например, суффиксы для строки "abcd" будут: "d", "cd", "bcd", "abcd". 
В префикс-функции для каждой позиции в строке мы храним значение, которое является максимальной длиной 
префикса суффикса начиная с нулевой позиции и заканчивающегося на данной позиции.
*/

// Функция для поиска подстроки (образца) в тексте с использованием префиксного массива
std::vector<int> kmpSearch(const std::string& text, const std::string& pattern, const std::vector<int>& prefixArray) 
{
    std::vector<int> results;
    int j = 0;

    for (int i = 0; i < text.size(); i++) 
    {
        while (j > 0 && text[i] != pattern[j]) 
        {
            j = prefixArray[j - 1];
        }
        if (text[i] == pattern[j]) 
        {
            j++;
        }
        if (j == pattern.size()) 
        {
            results.push_back(i - pattern.size() + 1);
            j = prefixArray[j - 1];
        }
    }

    return results;
}

int main() {
    std::ifstream inputFile("input.txt");
    if (!inputFile) 
    {
        std::cerr << "Ошибка при открытии файла input.txt" << std::endl;
        return 1;
    }

    std::string text;
    std::string pattern;
    getline(inputFile, pattern);
    getline(inputFile, text);
    inputFile.close();

    std::vector<int> prefixArray = createPrefixArray(pattern);
    std::vector<int> results = kmpSearch(text, pattern, prefixArray);


    std::ofstream outputFile("output.txt");
    if (!outputFile) 
    {
        std::cerr << "Ошибка при открытии файла output.txt" << std::endl;
        return 1;
    }

   /* for (int index : prefixArray)
    {
        std::cout << index << "  ";
    }*/

    for (int result : results) 
    {
        outputFile << result << "  ";
    }
    outputFile.close();

    return 0;
}
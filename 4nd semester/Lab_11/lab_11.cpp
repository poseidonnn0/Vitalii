#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Создать конечный автомат для образца
std::vector<std::vector<int>> create_automaton(const std::string& pattern) 
{
    int alphabet_size = 256;
    int pattern_size = pattern.size();
    std::vector<std::vector<int>> automaton(pattern_size + 1, std::vector<int>(alphabet_size, 0));

    automaton[0][pattern[0]] = 1;

    for (int X = 0, j = 1; j <= pattern_size; j++) 
    {
        for (int c = 0; c < alphabet_size; c++) 
        {
            automaton[j][c] = automaton[X][c];
        }
        automaton[j][pattern[j]] = j + 1;
        if (j < pattern_size) 
        {
            X = automaton[X][pattern[j]];
        }
    }
    return automaton;
}

// Алгоритм поиска образца в тексте с использованием конечного автомата
std::vector<int> search(const std::string& text, const std::vector<std::vector<int>>& automaton) 
{
    int state = 0;
    std::vector<int> matches;

    for (size_t i = 0; i < text.size(); i++) 
    {
        state = automaton[state][text[i]];

        if (state == automaton.size() - 1) 
        {
            matches.push_back(i - automaton.size() + 2);
        }
    }
    return matches;
}

int main() 
{
    // Считывание данных из файла input.txt
    std::ifstream input("input.txt");
    std::string pattern;
    std::string text;
    input >> pattern;
    input.ignore();
    std::getline(input, text);

    input.close();

    // Создание конечного автомата для образца
    std::vector<std::vector<int>> automaton = create_automaton(pattern);

    // Поиск образца в тексте с использованием конечного автомата
    std::vector<int> matches = search(text, automaton);

    // Вывод результатов в файл output.txt
    std::ofstream output("output.txt");
    output << "Matches found at indices: ";
    for (int index : matches) 
    {
        output << index << " ";
    }
    output.close();

    return 0;
}

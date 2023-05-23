#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#define d 256 // число символов в алфавите

void search(std::string& pattern, std::string& text, int primeNumber)
{
    int m = pattern.length(); // Длина образца
    int n = text.length(); // Длина текста
    int i, j;
    int patternHash = 0; // Хэш-значение образца
    int textHash = 0; // Хэш-значение для текущего окна в тексте
    int h = 1;

    // Рассчитываем значение h = pow(d, m-1)%primeNumber
    for (i = 0; i < m - 1; i++) 
    {
        h = (h * d) % primeNumber;
    }

    // Рассчитываем хэш-значение образца и первого окна в тексте
    for (i = 0; i < m; i++) 
    {
        patternHash = (d * patternHash + pattern[i]) % primeNumber;
        textHash = (d * textHash + text[i]) % primeNumber;
    }

    // Поиск вхождений образца
    for (i = 0; i <= n - m; i++) 
    {
        if (patternHash == textHash) 
        { // Если значения хэша совпадают, проверяем символы
            for (j = 0; j < m; j++) 
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == m)
                std::cout << "Вхождение в позиции " << i << '\n';
        }

        // Рассчитываем хэш-значение для следующего окна в тексте
        if (i < n - m) 
        {
            textHash = (d * (textHash - text[i] * h) + text[i + m]) % primeNumber;
            if (textHash < 0)
            {
                textHash = (textHash + primeNumber);
            }
        }
    }
}

int main() 
{
    setlocale(LC_ALL, "en_US.UTF8");
    std::string pattern, text;
    int primeNumber = 101; // Простое число

    // Чтение из файла
    std::ifstream fin; 
    fin.open("input.txt"); 
    getline(fin, pattern);
    getline(fin, text);
    fin.close();

    // Поиск вхождений образца в текст
    search(pattern, text, primeNumber);

    // Запись результата в файл
    std::ofstream fout; 
    fout.open("output.txt"); 
    fout << "Искомый образец: " << pattern << std::endl;
    fout << "Текст для поиска: " << text << std::endl;
    fout << "Простое число: " << primeNumber << std::endl;
    fout.close();

    return 0;
}


#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>


// Дан файл, содержащий русский текст, размер текста не превышает 10 Кбайт. 
// 
// Найти в тексте N (N ≤ 100) самых длинных слов, не содержащих ни одной буквы из заданного слова. 
// Записать найденные слова в текстовый файл в порядке не возрастания длины. 
// Все найденные слова должны быть разными. Число N вводить из файла.


int main()
{
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);

    std::string stroka, word_N, str[10000];
    int N, size = 0, count, mas[10000];
    in >> N;
    in >> word_N;
    if (in)
    {
        while (!in.eof())
        {
            in >> stroka;
            for (int i = 0; i < stroka.size(); i++)
            {
                if ((stroka[i] == ',') ||
                    (stroka[i] == '.') ||
                    (stroka[i] == '!') ||
                    (stroka[i] == ' ') ||
                    (stroka[i] == '?') ||
                    (stroka[i] == ':') ||
                    (stroka[i] == '"') ||
                    (stroka[i] == '«') ||
                    (stroka[i] == '»'))
                {
                    stroka = stroka.erase(i); // Удаляем данные элементы из строки текста 
                }

                for (int j = 0; j < word_N.size(); j++)
                {
                    if (toupper(stroka[i]) == toupper(word_N[j])) // Чтобы не делать проверку условий для общих букв, приводим сразу их к одному виду (заглавные буквы)
                    {
                        stroka.clear();
                        break;
                    }
                }
            }
            if (!stroka.empty())
            {
                    count = stroka.size(); // Считаем кол-во символов в слове
                    str[size] = stroka; // Запоминаем само слово в другой массив строк
                    mas[size] = count; // Запоминаем кол-во символов в слове
                    size += 1; // пробегаемся по всем словам в строке и сохраняем их общее кол-во
            }
            else
            {
                    count = 0; // Попросту нет слова
            }
                // Сортировка слов
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = i+1; j < size; j++)
                {
                    if (mas[i] < mas[j])
                    {
                            std::swap(mas[i], mas[j]); // sort по кол-ву символов в слове
                            std::swap(str[i], str[j]); // sort по самим словам
                    }
                }
            }
        }
        out << "Отсортированный текст по словам:" << std::endl;
        for (int i = 0; i < N; i++)
        {
            out << str[i] << std::endl;
        }
        return 0;
    }
    else
    {
        std::cout << "File not found" << std::endl;
    }
}

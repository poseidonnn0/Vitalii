#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("input.txt"); // открытие файла для чтения
    ofstream fout("output.txt"); // открытие файла для записи

    vector<int> nums; // создание вектора для хранения чисел
    int sum; // создание переменной для хранения заданной суммы

    // чтение данных из файла
    int num;
    fin >> sum;
    while (fin >> num) 
    {
        nums.push_back(num);
    }

    // сортировка вектора по убыванию
    sort(nums.begin(), nums.end(), greater<int>());

    // итерация по вектору и поиск суммы
    int cur_sum = 0;
    for (auto n : nums) 
    {
        if (n <= sum - cur_sum) 
        {
            cur_sum += n;
        }
    }
    if (cur_sum == sum) 
    {
        fout << "YES\n"; // если сумма найдена, то запись в файл "YES"
    }
    else {
        fout << "NO\n"; // иначе запись "NO"
    }

    fin.close(); // закрытие файлов
    fout.close();

    return 0;
}
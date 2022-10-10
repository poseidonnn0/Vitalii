#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
/* №9 Пирамидальная сортировка */

void heapify(std::vector<int>& arr, int& n, int i)
{
    int largest = i;
    // Инициализируем наибольший элемент как корень
    int l = 2 * i + 1; // левый = 2*i + 1
    int r = 2 * i + 2; // правый = 2*i + 2
    // Если левый дочерний элемент больше корня
    if (l < n && arr[l] > arr[largest])
        largest = l;
    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (r < n && arr[r] > arr[largest])
        largest = r;
    // Если самый большой элемент не корень
    if (largest != i)
    {
        std::swap(arr[i], arr[largest]);
        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

// Основная функция, выполняющая пирамидальную сортировку
void heapSort(std::vector<int>& arr)
{
    int n = arr.size();
    // Построение кучи (перегруппируем массив)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i >= 0; i--)
    {
        // Перемещаем текущий корень в конец
        std::swap(arr[0], arr[i]);
        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

/*Асимптотика в худшем, среднем и лучшем случаях – O(n*log(n)))*/

int main()
{
    srand(static_cast <unsigned int> (time(0))); // Время сис. часов(где компилируют)
    setlocale(LC_ALL, "RUS");
    int N;
    std::vector <int> mas;
    std::cout << "Введите число рандомных чисел в массиве = ";
    std::cin >> N;
    for (int i = 0; i < N; i++)
    {
        mas.push_back(rand());
    }
    std::cout << "\nМассив чисел без сортировки:\n";
    for (int i = 0; i < mas.size(); i++)
    {
        std::cout << mas[i] << " ";
    }
    std::cout << "\nМассив чисел после сортировки:\n";
    heapSort(mas);
    for (int i = 0; i < mas.size(); i++)
    {
        std::cout << mas[i] << " ";
    }
}

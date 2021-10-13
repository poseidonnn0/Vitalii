#include <iostream>
#include <fstream>
#include "Function.hpp"

#define N 100 
#define M 100

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, m, MinN;
    int mas[N][M];
    bool f = false;
    VK::Read(n, m, mas);
    std::cout << "MinNubmer = " << VK::MinNumber(n, m, mas) << std::endl;
    if ((VK::EqualMin(n, m, mas)) && (VK::PrimeNumber))
    {
        VK::SortMas(n, m, mas);
    }
    VK::Write(n, m, mas);
    return 0;
}

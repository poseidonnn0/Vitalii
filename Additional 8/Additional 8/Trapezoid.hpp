#pragma once
#include <iostream>

namespace VK
{
    struct Point // ������ ��������� �����(���������) ��� ��������� ����� ������
    {
        double x;
        double y;
    };
    class Trapezoid
    {
    public:
        Trapezoid(Point A, Point B, Point C, Point D); // ������ �������� � �������, �������������� � ������������ ���������

        ~Trapezoid();

        double Square();
        double Perimeter();

    private:
        double Distance(Point P1, Point P2)
        {
            return sqrt((P2.x - P1.x) * (P2.x - P1.x) + (P2.y - P1.y) * (P2.y - P1.y));
        }
        double A1;
        double B1;
        double C1;
        double D1;
    };
}
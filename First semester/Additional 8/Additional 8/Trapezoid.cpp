#include "Trapezoid.hpp"
#include <iostream>

namespace VK
{
    Trapezoid::Trapezoid(Point A, Point B, Point C, Point D)
    {
        A1 = Distance(A, B);
        B1 = Distance(B, C);
        C1 = Distance(C, D);
        D1 = Distance(D, A);
        if ((((A1 == C1) && ((D.x - A.x) / D1) == ((C.x - B.x) / B1)) ||
            ((B1 == D1) && (((C.x - D.x) / C1) == ((B.x - A.x) / A1))) ||
                ((A1 == C1) && (B1==D1))) /*Дописать условие, если точки будут совпадать*/) // Проверка на то, что это равнобедренная трапеция, с учётом того, что не будут вводить точки с одинаковыми координатами.
        {
            if (((A.x == B.x) && (A.y == B.y)) || ((B.x == C.x) && (B.y == C.y)) ||
                ((C.x == D.x) && (C.y == D.y)) || ((D.x == A.x) && (D.y == A.y)) ||
                ((A.x == C.x) && (A.y == C.y)) || ((B.x == D.x) && (B.y == D.y)))
            {
                std::cout << "Error. The trapezoid does not exist." << std::endl;
            }
            else 
                if (((A.x == B.x) && (A.y != B.y)) || ((A.y == B.y) && (A.x != B.x)) || ((B.x == C.x) && (B.y != C.y)) || ((B.y == C.y) && (B.x != C.x)) ||
                    ((C.x == D.x) && (C.y != D.y)) || ((C.y == D.y) && (C.x != D.x)) || ((D.x == A.x) && (D.y != A.y)) || ((D.y == A.y) && (D.x != A.x)) ||
                    ((A.x == C.x) && (A.y != C.y)) || ((A.y == C.y) && (A.x != C.x)) || ((B.x == D.x) && (B.y != D.y)) || ((B.y == D.y) && (B.x != D.x)))
                {
                    std::cout << "Constructor Works!" << std::endl;
                }
                else
                {
                    std::cout << "The trapezoid does not exist!!!" << std::endl;
                }
        }
        else
        {
            std::cout << "The trapezoid does not exist." << std::endl;
        }
        std::cout << '\n' << "a = " << A1 << " b = " << B1 << " c = " << C1 << " d = " << D1 << '\n' << '\n';
    }

    Trapezoid::~Trapezoid()
    {
        std::cout << "Destructor works!" << std::endl;
    }

    double Trapezoid::Square() // Если BC and AD - основания
    {
        if (A1 == C1)
        {
            return (((B1 + D1) / 2) * sqrt(abs((A1 * A1) - ((B1 - D1) * (B1 - D1)) / 4)));
        }
        else
            if (B1 == D1)
            {
                return (((A1 + C1) / 2) * sqrt(abs((B1 * B1) - ((A1 - C1) * (A1 - C1)) / 4)));
            }
    }
    double Trapezoid::Perimeter()
    {
        return A1 + B1 + C1 + D1;
    }
}

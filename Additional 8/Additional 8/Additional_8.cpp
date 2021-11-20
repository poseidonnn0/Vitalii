#include <iostream>
#include "Trapezoid.hpp"

int main()
{
    VK::Point A, B, C, D;
    std::cin >> A.x >> A.y >> B.x >> B.y >> C.x >> C.y >> D.x >> D.y;
    VK::Trapezoid Trap(A,B,C,D);    
    std::cout << "Square Trapezoid = " << Trap.Square() << std::endl;
    std::cout << "Perimeter Trapezoid = " << Trap.Perimeter() << std::endl;
    return 0;
}


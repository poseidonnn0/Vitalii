#include <iostream>
#include "Matrix.hpp"


int main()
{
	setlocale(LC_ALL, "Rus");
	const int n_2 = 2;
	const int m_2 = 2;
	const int n_3 = 3;
	const int m_3 = 3;
	math::Matrix A(n_2, m_2);

	std::cin >> A;

	std::cout << A << '\n';

	std::cout << A.Det() << '\n';

	std::cout << A.transposition() << '\n';

	std::cout << A.inv() << '\n';

	math::Matrix B(n_3, m_3);

	std::cin >> B;

	std::cout << B << '\n';

	std::cout << B.Det() << '\n';

	std::cout << B.transposition() << '\n';

	std::cout << B.inv() << '\n';

	return 0;
}
#include <iostream>
#include "Matrix.hpp"
#include <cassert>

int main()
{
	std::cout << "=== Test 1 ===" << std::endl;

	{
		math::Mat22d A({ {
			 {1,2},
			 {3,4}
		} });

		math::Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 3);
		assert(B.get(1, 0) == 7);
	}

	std::cout << "Done!" << std::endl;

	std::cout << "=== Test 2 ===" << std::endl;

	{
		math::Mat22d A({ {
			 {1,1},
			 {1,1}
		} });

		math::Vec2d X({ {
			{1},
			{1}
		} });

		auto B = A * X;

		assert(B.get(0, 0) == 2);
		assert(B.get(1, 0) == 2);
	}

	std::cout << "Done!" << std::endl;

	std::cout << "=== Test 3 / Determinant ===" << std::endl;

	{
		math::Mat22d A({ {
			 {1,2},
			 {3,10.4}
		} });

		assert(A.Det() == 4.4);
	}
	std::cout << "Done!" << std::endl;

	std::cout << "=== Test 4 / Transposition  ===" << std::endl;

	{
		math::Mat33d A({ {
			 {1,2,3},
			 {4,5,6},
			 {7,8,9}
		}});

		auto B = A.transposition();

		assert(B.get(0, 1) == 4);
		assert(B.get(1, 0) == 2);
		assert(B.get(1, 2) == 8);
		assert(B.get(2, 1) == 6);

	}

	std::cout << "Done!" << std::endl;

	std::cout << "=== Test 5 / Inverse  ===" << std::endl;
	
	{
		math::Mat22d A({ {
			 {1,2},
			 {3,5}
		} });
		auto B = A.inv();

		try
		{
			std::cout << B << std::endl;
			std::cout << "After inv in main" << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		assert(B.get(0, 0) == -5);
		assert(B.get(1, 0) == 3);
	}

	std::cout << "Done!" << std::endl;


	return 0;
}

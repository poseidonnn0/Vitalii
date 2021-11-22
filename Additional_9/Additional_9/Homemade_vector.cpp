#include <iostream>
#include "Homemade_vector.hpp"

namespace VK
{
	Vector::Vector(int &len)
	{
		count = len;
		vec = new int[count];
		size = 0;
		size_n = len;
	}

	Vector::~Vector()
	{
		delete[] vec;
	}

	int Vector::VectorSize() // 1
	{
		return size;
	}

	void Vector::push_back(int num) // 2
	{
		if (size == size_n)
		{
			int *tmp = new int[size_n+2];
			for (int i = 0; i < size_n; i++)
			{
				tmp[i] = vec[i];
			}
			delete[] vec;
			vec = tmp;
			size_n += 2;
		}
		vec[size++] = num;
	}

	void Vector::VectorAddElement(int n) //3
	{
		vec[size] = n;
		std::cout << vec[size] << " ";
		size++;
	}

	int Vector::VectorElementIndex(int i) // 4
	{
		return vec[i];
	}

	int Vector::VectorSumElements() // 5
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum += vec[i];
		}
		return sum;
	}
}
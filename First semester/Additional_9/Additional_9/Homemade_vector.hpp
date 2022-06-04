#pragma once


namespace VK
{
	class Vector
	{
	public:
		Vector(int &len);
		~Vector();
		int VectorSize();
		void VectorAddElement(int n);
		int VectorSumElements();
		int VectorElementIndex(int i);
		void push_back(int num); //const &num
	private:
		int* vec;
		int size, count;
		int size_n;
	};
}
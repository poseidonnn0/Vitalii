#pragma once
#include <iostream>

namespace VK
{
	class Device
	{
		int address;
		std::string name;
		float energy, temperature;
	public:
		Device(std::string name1, int address1);
		~Device();
		void Poll();
		void Print();
	};
}
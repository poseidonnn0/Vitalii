#include <iostream>
#include "Physics.hpp"
#include <ctime>
namespace VK
{
	Device::Device(std::string name1, int address1)
	{
		name = name1;
		address = address1;
		energy = 0;
		temperature = 0;
	}
	Device::~Device()
	{
		//work Destructor
	};

	void Device::Poll()
	{
		srand(time(0));
		switch (address) 
		{
		case 0:
			temperature = -50 + rand()  % (650 + (-50) + 1);
			energy = 0 + rand() % (1000000000 - 0 + 1);
			if (temperature == 0) energy = 0;
			break;
		case 1:
			temperature = 0 + rand() % (150 - 0 + 1) ;
			energy =  (0.13*(rand() % (2)+1)) * (rand() % (1000000000));
			if (temperature == 0) energy = 0;
			break;
		// ����������, ���� ����� ������� ����
		}
	}
	void Device::Print()
	{
		std::cout << "������������ ����������: " << name << '\n' << "����� ����������: " << address << '\n' << "����������� �������� �������: " << energy << '\n' << "�����������: " << temperature << '\n';
	}

}
#include <iostream>
#include "Device.h"

int main()
{
	Device dev;
	std::cout << dev.getSerial() << "\n";

	Computer comp;
	std::cout << "\n" << comp.GetInformation() << std::endl;

	Laptop laptop;
	std::cout << laptop.getSerial() << "\n" << laptop.getBatterySize();
}
#pragma once

#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class Device
{
protected: // ��� ����, ����� �������� ���� �������� � ������������� �������
	std::string serial;
	unsigned energyConsumption;

public:
	Device()
	{
		serial = "ABCDEF123456";
		energyConsumption = 10;
	}

	~Device() = default;

	std::string getSerial() const
	{
		return serial;
	}
};

// ��������� ����������� �� ������� �� �������������� �������, ������� ����������
// ������ ������ ��������� ���� ��������������� ������
class Computer : protected Device
{
protected:
	double clock;
	unsigned ram;
	unsigned memory;

public:
	Computer() : Device() // ���������� ����������� ������ ������
	{
		clock = 3200;
		ram = 16;
		memory = 512;
	}

	~Computer() = default;

	std::string GetInformation()
	{
		std::string str;
		str += "Energy: " + std::to_string(energyConsumption) + "\n";
		str += "Ram: " + std::to_string(ram) + "\n";
		str += "Memory: " + std::to_string(memory);
		return str;
	}
};


class Battery
{
protected:
	std::string serial;
	unsigned battery;

public:
	Battery()
	{
		serial = "09876qtij";
		battery = 10;
	}

	~Battery() = default;

	unsigned getBatterySize() const
	{
		return battery;
	}

	std::string getSerial() const
	{
		return serial;
	}
};

class Laptop : public Computer, public Battery
{
private:
	// ��� ������������� ������� � ����������� ���������� �� ������ �������
	using Battery::getSerial;
	using Device::getSerial;

public:
	Laptop() : Computer(), Battery() {}

	~Laptop() = default;

	std::string getSerial() const
	{
		return Battery::getSerial() + "\n" + Device::getSerial();
	}
};

#endif
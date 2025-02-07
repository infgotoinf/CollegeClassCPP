#pragma once

#ifndef DEVICE_H
#define DEVICE_H

#include <string>

class FLplugin
{
protected:
	std::string type;
	std::string type_type;
public:
	FLplugin() {};
};

class Effect : protected FLplugin
{
public:
	Effect()
	{
		type = "Effect";
	};
};

class Synthezator : protected FLplugin
{
public:
	Synthezator()
	{
		type = "Synthezator";
	};
};


class FruityBloodyOverdrive : protected Effect
{
	int NumberOfPeopleInCult;

public:
	FruityBloodyOverdrive() {
		NumberOfPeopleInCult = 6666666666;
		type_type = "Distortion";
	}
};

#endif
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

class PanCake : protected Effect
{
public:
	PanCake() {
		type_type = "Pan";
	}
};


class SurgeXT : protected Synthezator
{
	int Pitch;
	int Shape;
	unsigned Width1;
	unsigned Width2;
	unsigned SubMix;
	unsigned Sync;
	unsigned UnisonDetune;
	unsigned UnisonVoices;
public:
	SurgeXT() {
		Pitch = 0;
		Shape = 0;
		Width1 = 50;
		Width2 = 50;
		SubMix = 0;
		Sync = 0;
		UnisonDetune = 0;
		UnisonVoices = 0;
	}
};

#endif
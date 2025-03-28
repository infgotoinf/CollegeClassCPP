#pragma once

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>

class AbstractCharacter
{
private:
	int HP, DMG, RESIST,
		DODGE, ACCURACY; // Can't be more than 100
public:
	AbstractCharacter(int HP, int DMG, int RESIST,
		int DODGE, int ACCURACY)
		: HP	  (HP)
		, DMG	  (DMG)
		, RESIST  (RESIST)
		, DODGE   (DODGE)
		, ACCURACY(ACCURACY)
	{ }
	virtual ~AbstractCharacter() = default;

	void SetHP		(int HP)	   { this->HP = HP; }
	void SetDMG		(int DMG)	   { this->DMG = DMG; }
	void SetRESIST	(int RESIST)   { this->RESIST = RESIST; }
	void SetDODGE	(int DODGE)	   { this->DODGE = DODGE; }
	void SetACCURACY(int ACCURACY) { this->ACCURACY = ACCURACY; }

	const int GET_HP()		 const { return HP; }
	const int GET_DMG()      const { return DMG; }
	const int GET_RESIST()   const { return RESIST; }
	const int GET_DODGE()	 const { return DODGE; }
	const int GET_ACCURACY() const { return ACCURACY; }
};


class Character : protected AbstractCharacter
{
	// Actual characteristics
	int hp, dmg, resist,
		dodge, accuracy;
	std::string name;

public:
	Character(int HP, int DMG, int RESIST,
		int DODGE, int ACCURACY, std::string name)
		: AbstractCharacter(HP, DMG, RESIST,
			DODGE, ACCURACY)
		, hp	  (HP)
		, dmg	  (DMG)
		, resist  (RESIST)
		, dodge   (DODGE)
		, accuracy(ACCURACY)
		, name    (name)
	{ }
	~Character()
	{
		std::cout << name << " died a brave death!\n";
	}
	Character(Character const& other)
		: AbstractCharacter(
			other.GET_HP(),
			other.GET_DMG(),
			other.GET_RESIST(),
			other.GET_DODGE(),
			other.GET_ACCURACY())
		, hp(other.GetHp())
		, dmg(other.GetDmg())
		, resist(other.GetResist())
		, dodge(other.GetDodge())
		, accuracy(other.GetAccuracy())
		, name(other.name)
	{ }

	int GetHp()		  const { return hp; }
	int GetDmg()      const { return dmg; }
	int GetResist()   const { return resist; }
	int GetDodge()	  const { return dodge; }
	int GetAccuracy() const { return accuracy; }
	std::string GetName() const { return name; }

	void SetName(std::string name) { this->name = name; }

	int RecieveDamage(Character const& character)
	{
		std::random_device dev;
		std::mt19937 rnd(dev());
		std::uniform_int_distribution<unsigned> rand(1, 100);
		if (rand(rnd) < dodge)
			return 0;
		std::uniform_int_distribution<unsigned> inaccur(0, character.GetAccuracy());
		int damageCalc = character.GetDmg() - inaccur(rnd) - resist;
		//std::cout << character.GetDmg() << ' ' << inaccur(rnd) << ' ' << resist;
		hp -= damageCalc;
		if (hp < 1)
			return -1;
		return damageCalc;
	}
};


std::ostream& operator<<(std::ostream& str, Character const& character)
{
	str << character.GetName() << " stats:\n";
	str << " O\n";
	str << "/|\\\n";
	str << "/ \\\n";
	str << "HP: " << character.GetHp() << "\n";
	str << "DMG: " << character.GetDmg() << "\n";
	str << "Resist: " << character.GetResist() << "\n";
	str << "Dodge: " << character.GetDodge() << "\n";
	str << "Accuracy: " << character.GetAccuracy() << "\n";
	return str;
}

#endif // !GAME_H
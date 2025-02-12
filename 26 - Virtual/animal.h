#pragma once

#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

class Animal
{
protected:
	unsigned age;

public:
	Animal(unsigned age = 2) : age(age) {}
	Animal(Animal const& other) : age(other.age) {}
	virtual ~Animal() = default;

	virtual void say()
	{
		std::cout << '?';
	}
};

class Cat : virtual public Animal
{
protected:
	std::string name;

public:
	Cat(std::string const& name = "Barsik") : Animal(), name(name) {}
	Cat(Cat const& other) : Animal(), name(other.name) {}
	~Cat()
	{
		std::cout << name << " died";
	}

	std::string getName() const
	{
		return name;
	}

	void setName(std::string const& name)
	{
		this->name = name;
	}

	void say() override
	{
		std::cout << ":3\n";
	}
};

class Dog : virtual public Animal
{
protected:
	std::string type;

public:
	Dog(std::string const& type = "Terrier") : Animal(), type(type) {}
	Dog(Dog const& other) : Animal(), type(other.type) {}
	~Dog()
	{
		std::cout << type << " died\n";
	}

	std::string getType() const
	{
		return type;
	}

	void setType(std::string const& type)
	{
		this->type = type;
	}

	void say() override
	{
		std::cout << "Bark!\n";
	}
};

class Catdog : public Cat, public Dog
{
protected:
public:
	Catdog(std::string const& type = "Terier", std::string const& name = "Shashlik")
		: Cat(name)
		, Dog(type)
	{ }
	Catdog(Catdog const& other)
		: Cat(other.name)
		, Dog(other.type)
	{ }
	~Catdog()
	{
		std::cout << "Legends never diiiiieeeeee!!!1!...\n";
	}

	void say() override
	{
		std::cout << "Bark!:3\n";
	}
};

#endif
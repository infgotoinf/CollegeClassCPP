#pragma once

#include <string>

// Ќаследование

class Person
{
	std::string name;
	unsigned age;
};

// ≈сли у челика есть такие же пол€ как и у другого класса,
// то лучше просто запихнуть в этого чела этот класс
class Student : Person
{
	unsigned year;
};
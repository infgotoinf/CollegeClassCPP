#pragma once

#ifndef EXEPTION_H
#define EXEPTION_H

// #include<stdexcept>
#include<exception>
#include<stdexcept>

class my_exeption : public std::exception
{
protected:
	std::string message;
	int value;

public:
	my_exeption(std::string const& msg, int val = 0)
		: std::exception()
		, message(msg), value(val)
	{ }

	const char* what() const override
	{
		return message.c_str();
	}
};

#endif
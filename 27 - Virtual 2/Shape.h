#pragma once

#ifndef SHAPE_H
#define SHAPE_H

#include <math.h>

const double pi = 3.14159265359;

class Shape
{
protected:
public:
	Shape() {};
	virtual ~Shape() = default;
	virtual double area() = 0;
};

class Circle : public Shape
{
protected:
	double r;
public:
	Circle(double const& rad) : r(rad) {};
	~Circle() = default;
	double area() override
	{
		return pi * r * r;
	}
};

class Square : public Shape
{
protected:
	double a;
public:
	Square(double side) : a(side) {};
	~Square() = default;
	double area() override
	{
		return a * a;
	}
};

class Triangle : public Shape
{
protected:
	double a, b, c;
	double p;
public:
	Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3), p(side1+side2+side3) {};
	~Triangle() = default;
	double area() override
	{
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
};

#endif
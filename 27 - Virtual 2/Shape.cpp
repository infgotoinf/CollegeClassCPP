#include "Shape.h"
#include "Exeption.h"
#include "Tree.h"
#include <iostream>
#include <list>

double foo(int a)
{
	if (a == 0) throw ("bebebe", 0);
	return 1.0 / a;
}

int main()
{
	std::list<Shape*> shapes;

	std::string what_shape;
	while (1)
	{
		std::cout << "What do ya wanna add? (circle; square; triangle)\n";
		std::cin >> what_shape;
		if (what_shape == "circle")
		{
			double radius;
			std::cout << "Enter it's radius\n";
			std::cin >> radius;
			shapes.push_back(new Circle(radius));
		}
		else if (what_shape == "square")
		{
			double side;
			std::cout << "Enter it's side\n";
			std::cin >> side;
			shapes.push_back(new Square(side));
		}
		else if (what_shape == "triangle")
		{
			double side1, side2, side3;
			std::cout << "Enter it's sides\n";
			std::cin >> side1 >> side2 >> side3;
			shapes.push_back(new Triangle(side1, side2, side3));
		}
		else if (what_shape == "area")
		{
			double sum_area = 0;
			for (auto const &shape : shapes)
			{
				sum_area += shape->area();
			}
			std::cout << sum_area << std::endl;
		}
		else if (what_shape == "exit")
		{
			break;
		}
		else
		{
			std::cout << "Fuck you!";
		}
	}

	while (!shapes.empty())
	{
		delete shapes.front();
		shapes.pop_front();
	}

	
	/*try
	{
		int a;
		std::cin >> a;
		std::cout << foo(a);
	}
	catch (...)
	{
		my_exeption();
	}*/


	Tree<int> tree;

	tree.add(0);
	tree.add(9);
	tree.add(4);
	tree.add(13);
	tree.add(2);
	tree.add(-8);
	tree.add(-3);
	tree.add(-1);

	return 0;
}
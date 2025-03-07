#include <iostream>

class CarBuilder;

class Car
{
	int year;
	std::string name;
	std::string model;
	double maxVelocity;
	double total;

public:
	Car(int year,
		std::string name,
		std::string model,
		double maxVelocity,
		double total)
		: year(year)
		, name(name)
		, model(model)
		, maxVelocity(maxVelocity)
		, total(total)
	{ }

	Car(Car const&) = default;
	~Car() = default;

	Car(CarBuilder& builder);

	friend CarBuilder;
	friend std::ostream& operator<<(std::ostream& str, Car const& car);
};

std::ostream& operator<<(std::ostream& str, Car const& car)
{
	str << car.name << ' ' << car.model << '\n';
	str << "Year: " << car.year << '\n';
	str << "Total: " << car.total << "km\n";
	str << "Max velocity: " << car.maxVelocity;
	return str;
}

class CarBuilder
{
	Car car;

public:
	CarBuilder() : car(2025, "Lada", "Granta", 190, 0)
	{ }
	CarBuilder(CarBuilder const&) = delete;
	~CarBuilder() = default;

	CarBuilder& setYear(int year)
	{
		car.year = year;
		return *this;
	}

	CarBuilder& setName(std::string name)
	{
		car.name = name;
		return *this;
	}

	CarBuilder& setModel(std::string model)
	{
		car.model = model;
		return *this;
	}

	CarBuilder& setMaxVelocity(double maxVelocity)
	{
		car.maxVelocity = maxVelocity;
		return *this;
	}

	CarBuilder& setTotal(double total)
	{
		car.total = total;
		return *this;
	}

	Car create()
	{
		return car;
	}
};

Car::Car(CarBuilder& builder)
{
	Car car = builder.create();

	year = car.year;
	name = car.name;
	model = car.model;
	maxVelocity = car.maxVelocity;
	total = car.total;
}

int main()
{
	CarBuilder builder;
	builder.setTotal(1000000).setName("Renault").setModel("Logan");
	
	Car a = CarBuilder().setTotal(100000).create();

	//Car a = builder.create();

	Car c(builder.setYear(2002));

	std::cout << a << '\n' << std::endl;

	std::cout << c << std::endl;

	return 0;
}
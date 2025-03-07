#include <iostream>

class Singleton
{
	static Singleton* instance;

	Singleton() {}

	Singleton(Singleton const&) = delete;

public:
	std::string programName;
	const double g = 9.81;

	~Singleton()
	{
		delete instance;
	}

	static Singleton& getInstance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}

		return *instance;
	}
};

Singleton* Singleton::instance = nullptr;

int main()
{
	Singleton::getInstance().programName = "My program";

	std::cout << Singleton::getInstance().programName;

	return 0;
}
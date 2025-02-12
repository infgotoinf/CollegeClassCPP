#include "animal.h"

int main()
{
	/*Cat cat("Shahlik");
	cat.say();
	std::cout << cat.getName() << '\n';*/
	std::string option;
	std::cin >> option;

	Animal* a = nullptr;

	if (option == "dog")
	{
		a = new Dog("Sasnaya Sobachka");
	}
	else if (option == "cat")
	{
		a = new Cat("Shashlik");
	}
	else if (option == "catdog")
	{
		a = new Catdog("Shashlik", "Sasnaya Sobachka");
	}
	else {
		std::cerr << "Error! No such animal!\n";
		return 0;
	}
	
	a->say();

	delete a;

	return 0;
}
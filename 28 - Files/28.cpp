#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <filesystem>

class pacient
{
private:
	int years;
	std::string name;
	std::string desiace;

public:
	pacient(int yr, std::string nm, std::string de) : years(yr), name(nm), desiace(de) { };
	~pacient() = default;

	void add_years(int num)
	{
		years += num;
	}

	std::string return_pacient() const
	{
		std::string profile = "Years: " + std::to_string(years) + '\n';
		profile += "Name: " + name + '\n';
		profile += "Desiace: " + desiace + '\n';
		return profile;
	}

	std::string get_name() const
	{
		return name;
	}
};

class palata
{
private:
	int max_pacients;
	std::string name;
	std::list<pacient> pacients;

public:
	palata(int mp, std::string nm) : max_pacients(mp), name(nm) { };
	~palata() = default;

	void add_pacient(pacient & pacient)
	{
		if (pacients.size() < max_pacients)
		{
			pacients.push_back(pacient);
		}
		else
		{
			std::cerr << "Palata " << name << " is full!";
		}
	}

	std::string return_pacients() const
	{
		std::string pacient_list = "";
		for (pacient pacient : pacients)
		{
			pacient_list += pacient.return_pacient() + '\n';
		}
		return pacient_list;
	}

	std::string return_name() const
	{
		return name;
	}
};

class durka
{
private:
	std::string name;
	std::list<palata> palatas;

public:
	durka(std::string nam) : name(nam) {};
	~durka() = default;

	void add_palata(palata& palata)
	{
		palatas.push_back(palata);
	}

	std::string return_pacients() const
	{
		std::string durka_list = "";
		for (palata palata : palatas)
		{
			durka_list += palata.return_name() + '\n' + palata.return_pacients() + '\n';
		}
		return durka_list;
	}
};

int main()
{
	// Поток вывода в файл
	std::ofstream file;
	file.open("out.txt");

	if (!file.is_open())
	{
		std::cerr << "Error!";
		return 0;
	}

	file << "Hello world!";

	file.close();

	//// Поток ввода в файл
	//std::ifstream file1;
	//file1.open("out.txt");

	//if (!file1.is_open())
	//{
	//	std::cerr << "Error!";
	//}

	//std::string str;
	///*file1 >> str;

	//std::cout << str;*/

	//while (std::getline(file1, str))
	//{
	//	std::cout << str;
	//}

	//file1.close();

	//const std::filesystem::path dir_pacients{ "pacients" };
	//const std::filesystem::path dir_palata{ "palatas" };
	//const std::filesystem::path dir_durkas{ "durkas" };

	//do
	//{
	//	short int action = 0, action2 = 0;
	//	std::cout << "1: go to pacients; 2: go to palatas; 3: go to durka\n";
	//	std::cin >> action;
	//	switch (action)
	//	{
	//	case 1: // go to pacients
	//		std::cout << "1: create a pacient; 2: add years; 3: print pacient\n";
	//		std::cin >> action2;
	//		switch (action2)
	//		{
	//		case 1: // create a pacient
	//		{
	//			int year;
	//			std::string name, desiace;
	//			std::cout << "Enter his year, name, desiace:\n";
	//			std::cin >> year >> name >> desiace;
	//			pacient pac(year, name, desiace);

	//			std::ofstream file;
	//			file.open("pacients\\" + name + ".txt");

	//			if (!file.is_open())
	//			{
	//				std::cerr << "Error!";
	//				return 0;
	//			}

	//			file << pac.return_pacient();

	//			file.close();
	//			break;
	//		}
	//		case 2: // add years
	//		{
	//			std::string name;
	//			std::list<std::string> names;
	//			for (auto const& entry : std::filesystem::directory_iterator{ dir_pacients })
	//			{
	//				std::ifstream file1;
	//				file1.open(entry);

	//				if (!file1.is_open())
	//				{
	//					std::cerr << "Error!";
	//				}

	//				std::string str;
	//				int count = 0;
	//				while (std::getline(file1, str))
	//				{
	//					if (count++ == 1)
	//					{
	//						int i = 0;
	//						std::string stri = "";
	//						for (char s : str)
	//						{
	//							if (i++ > 5)
	//							{
	//								stri += s;
	//							}
	//						}
	//						names.push_back(stri);
	//						std::cout << str << '\n';
	//					}
	//				}
	//				file1.close();
	//			}
	//			
	//			std::cout << "Enter pacient's name:\n";
	//			std::cin >> name;
	//			for (std::string nam : names)
	//			{
	//				if (nam == name) continue;
	//				int num;
	//				std::cout << "Enter how many years to add:\n";
	//				std::cin >> num;
	//				
	//				std::ifstream file1;
	//				file1.open("pacients\\" + name + ".txt");

	//				if (!file1.is_open())
	//				{
	//					std::cerr << "Error!";
	//				}

	//				std::string str, strn;
	//				std::string stri;
	//				bool go = true;
	//				while (std::getline(file1, str))
	//				{
	//					int i = 0;
	//					if (go) {
	//						for (char s : str)
	//						{
	//							if (i++ > 6)
	//							{
	//								strn += s;
	//							}
	//						}
	//						num += std::stoi(strn);
	//						stri = "Year: " + std::to_string(num) + '\n';
	//						go = false;
	//						continue;
	//					}
	//					stri += str + '\n';
	//				}
	//				file1.close();

	//				std::ofstream file2;
	//				file2.open("pacients\\" + name + ".txt");
	//				file2 << stri;
	//				file2.close();
	//			}
	//			break;
	//		}
	//		case 3: // print pacient
	//			for (auto const& entry : std::filesystem::directory_iterator{ dir_pacients })
	//			{
	//				std::ifstream file1;
	//				file1.open(entry);

	//				if (!file1.is_open())
	//				{
	//					std::cerr << "Error!";
	//				}

	//				std::string str;

	//				while (std::getline(file1, str))
	//				{
	//					std::cout << str << '\n';
	//				}
	//				file1.close();

	//				std::cout << '\n';
	//			}
	//			break;
	//		default:
	//			std::cout << "Wrong action!\n";
	//		}
	//		break;
	//	case 2: // go to palatas
	//		std::cout << "1: add a pacient; 2: print palatas\n";
	//		std::cin >> action2;
	//		switch (action2)
	//		{
	//		case 1:
	//			std::cout << "1: create a pacient; 2: add years; 3: print pacients\n";
	//			break;
	//		case 2:
	//			std::cout << "1: add a pacient; 2: print palatas\n";
	//			break;
	//		default:
	//			std::cout << "Wrong action!\n";
	//		}
	//		break;
	//		break;
	//	case 3: // go to durkas
	//		std::cout << "1: add a palata; 2: print durka\n";
	//		std::cin >> action2;
	//		switch (action2)
	//		{
	//		case 1:
	//			std::cout << "1: create a pacient; 2: add years; 3: print pacients\n";
	//			break;
	//		case 2:
	//			std::cout << "1: add a pacient; 2: print palatas\n";
	//			break;
	//		default:
	//			std::cout << "Wrong action!\n";
	//		}
	//		break;
	//	default:
	//		std::cout << "Wrong action!\n";
	//	}
	//	action = 0, action2 = 0;
	//	std::cout << std::endl;
	//} while(1);


	return 0;
}
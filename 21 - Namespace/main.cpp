#include <iostream>
#include <filesystem>
#include <fstream>
#include <chrono>

using std::cout;

namespace UwU{
	namespace OwO{
		namespace QwQ{
			std::string TwT = "TwT";
		}
	}
} //namespace UwU


unsigned operator""KB(unsigned long long i)
{
	return i * 1024;
}

int main() {
	cout << UwU::OwO::QwQ::TwT << '\n';

	std::filesystem::path p(__FILE__); //(R"(C:\Users\studentcoll\source\repos\infgotoinf\CollegeClassCPP\README.md)");
	std::cout << p << '\n';

	std::chrono::duration<double> t;
	
	auto size = 32KB;
	std::cout << size << '\n';

	/*std::string str;
	while (std::getline(file, str));*/

	return 0;
}
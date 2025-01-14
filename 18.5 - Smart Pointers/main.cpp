#include <iostream>
//#include <memory>

//std::sharted_ptr
//std::unique_ptr
//std::weak_ptr

//int b = (int)(2.0)
//int b = (int)(&a)

//int b = static_cast <int>(2f)
//int* b = static_cast <int*>(&a) // Ошибка

//auto b = reinterpret_cast<int*>(&a)
//const_cast<const int>(a)
//dynamic_cast<>()

//volatile int

int main() {
	unsigned short a = 0xFF00;
	unsigned short* s = new unsigned short{ (unsigned short)0xFF00 };
	char* c = new char[2] { char(s), char(s)};
	//char* b = reinterpret_cast<char*>(&s);
	char* b = reinterpret_cast<char*>(&a);
	//std::cout << *c << ' ' << *(c+1) << '\n';
	std::cout << unsigned int(*b) << ' ' << (unsigned int(*(b + 1)) == 0xFF);
	delete s, c;
	return 0;
}
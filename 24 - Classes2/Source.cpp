#include <iostream>
#include "student.h"
#include "strwrp.h"
#include "GitHub.h"

int main() {
	Student stud("Akimchik", 1488);

	std::cout << stud.getName() << " " << stud.getAge() << "\n";


	// ����������� �����������
	Student stud2 = stud;
	std::cout << stud2.getName() << " " << stud2.getAge() << "\n";

	StringWrapper str("Sfsefoirskjeisfawd");

	// substr(1, 10);
	std::string subs = str[1][10];

	std::cout << subs << "\n\n";


	GitHub a;
	GitHub b("[{\"UwU\":\"OwO\"]");
	GitHub c = b;
	a = c;
	std::cout << a.get() << '\n' << b.get() << '\n' << c.get();
	return 0;
}



//#include <iostream> //
//
//class Student {
//private:
//	std::string name;
//	unsigned age;
//
//public: //��� ��������� � ��������� �������, ���������� setter � getter
//	// �����������
//	Student() {
//		name = "anonim";
//		age = 35;
//	}
//
//	// ����������� �����������
//	Student(Student const & other) { // ����������� "const &"
//		name = other.name; // ��� ���� ����� ������� ��������� ��������
//		age = other.age;
//	}
//
//	// �������� ������������ �����������
//	Student& operator=(Student const& other) {
//		age = other.age;
//		name = other.name;
//		return *this;
//	}
//
//	void setName(std::string name) {
//		this->name = name;
//	}
//
//	void setAge(unsigned age) {
//		this->age = age;
//	}
//
//	unsigned getAge() const {
//		return age;
//	}
//
//	std::string getName() {
//		return name;
//	}
//};
//
//int main() {
//	Student stud;
//	//stud.age; // ������
//	stud.setName("Akim");
//	stud.setAge(23);
//
//	std::cout << stud.getName() << " " << stud.getAge() << "\n";
//
//
//	// ����������� �����������
//	Student stud2;
//	std::cout << stud2.getName() << " " << stud2.getAge() << "\n";
//
//	// ������������
//	stud2 = stud;
//	std::cout << stud.getName() << " " << stud.getAge() << "\n";
//	
//
//	return 0;
//}
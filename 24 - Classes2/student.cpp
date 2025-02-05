#include "student.h"
#include <stdexcept>

Student::Student() : name("Anonim"), age(40), gradesList() {}

Student::Student(std::string const& n, unsigned a) : name(n), age(a), gradesList() {}

Student::Student(Student const& other) : name(other.name), age(other.age), gradesList(other.gradesList) {}

Student& Student::operator=(Student const& other) {
	age = other.age;
	name = other.name;
	return *this;
}

void Student::setName(std::string name) {
	this->name = name;
}

void Student::setAge(unsigned age) {
	this->age = age;
}

unsigned Student:: getAge() const {
	return age;
}

std::string Student::getName() const {
	return name;
}


void Student::setGrades(std::list<unsigned> const & list) {
	for (unsigned i : gradesList) {
		gradesList.push_back(i);
	}
}

void Student::setGrades(unsigned grade) {
	if (grade < 0 || grade > 12) throw std::invalid_argument("Grade is wrong");
		gradesList.push_back(grade);
}

std::list<unsigned> Student::getGrades() const {
	return gradesList;
}

double Student::averageGrade() const {
	if (gradesList.empty()) return 0.0;

	double result = 0;
	for (size_t i : gradesList) {
		result += i;
	}
	return result / gradesList.size();
}

void Student::reset() {
	gradesList.clear();
}
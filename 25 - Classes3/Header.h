#pragma once

#include <string>

// ������������

class Person
{
	std::string name;
	unsigned age;
};

// ���� � ������ ���� ����� �� ���� ��� � � ������� ������,
// �� ����� ������ ��������� � ����� ���� ���� �����
class Student : Person
{
	unsigned year;
};
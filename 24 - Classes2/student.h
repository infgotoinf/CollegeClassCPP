#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <list>

class Student {
private:
	std::string name;
	unsigned age;
	std::list<unsigned> gradesList;

	Student();
public: //��� ��������� � ��������� �������, ���������� setter � getter

	// ����������� �����������
	Student(std::string const& n, unsigned a = 18); // ��� ���������� ����������� �����

	// ����������� �����������
	Student(Student const& other);

	// �������� ������������ �����������
	Student& operator=(Student const& other);

	void setName(std::string name);
	void setAge(unsigned age);
	unsigned getAge() const;
	std::string getName() const;

	/// <summary>
	/// ���������� ������ ��������
	/// </summary>
	/// <param name="list">������ ����������� ������</param>
	void setGrades(std::list<unsigned> const& list);

	/// <summary>
	/// ��������� ���� ������
	/// </summary>
	/// <param name="grade">�������� ������</param>
	void setGrades(unsigned grade);


	/// <summary>
	/// ��������� ������ ������
	/// </summary>
	/// <returns>������ ������</returns>
	std::list<unsigned> getGrades() const; // ������������ �������� ������ �� �����, ���������� �������� � ����������

	double averageGrade() const;

	void reset();
};

#endif // STUDENT_H
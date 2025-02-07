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
public: //для обращение и изменения привата, используем setter и getter

	// Конструктор копирования
	Student(std::string const& n, unsigned a = 18); // для заполнения константной шняги

	// Конструктор копирования
	Student(Student const& other);

	// Оператор присваивания копирования
	Student& operator=(Student const& other);

	void setName(std::string name);
	void setAge(unsigned age);
	unsigned getAge() const;
	std::string getName() const;

	/// <summary>
	/// Добавление оценок студенту
	/// </summary>
	/// <param name="list">список добавляемых оценок</param>
	void setGrades(std::list<unsigned> const& list);

	/// <summary>
	/// Добавляет одну оценку
	/// </summary>
	/// <param name="grade">Величина оценки</param>
	void setGrades(unsigned grade);


	/// <summary>
	/// Получение списка оценок
	/// </summary>
	/// <returns>Список оценок</returns>
	std::list<unsigned> getGrades() const; // возаращаемое значение список из чисел, неизменяет значение в экземпляре

	double averageGrade() const;

	void reset();
};

#endif // STUDENT_H
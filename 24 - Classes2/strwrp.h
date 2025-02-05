#pragma once

#include <string>

class StringWrapper
{
	class StringWrapperImpl
	{
		std::string& strref;
		int firstIndex;

	public:
		// конструктор инициализирующий ссылку на строчку и позицией начала подстроки
		StringWrapperImpl(std::string& ref, int first) : strref(ref), firstIndex(first) {};

		std::string operator[](int i) {
			// Использует позицию начала и переменную i в качестве позиции конца
			std::string a;
			for (int j = this->firstIndex; j <= i; j++) {
				a.push_back(strref[j]);
			}
			return a;
		}
	};

	std::string str_;

public:
	StringWrapper(const char* str) : str_(str) {};

	StringWrapperImpl operator[](int i)
	{
		return StringWrapperImpl(str_, i);
	}
};


#pragma once

#include <string>

class StringWrapper
{
	class StringWrapperImpl
	{
		std::string& strref;
		int firstIndex;

	public:
		// ����������� ���������������� ������ �� ������� � �������� ������ ���������
		StringWrapperImpl(std::string& ref, int first) : strref(ref), firstIndex(first) {};

		std::string operator[](int i) {
			// ���������� ������� ������ � ���������� i � �������� ������� �����
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


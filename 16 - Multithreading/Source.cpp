#include <iostream>
#include <thread>
#include <vector>
//#include <windows.h>
//#include <future>
//#include <mutex>

//std::mutex m;

//void print(const char* str) {
	//std::this_thread::sleep_for(std::chrono::microseconds(5000));
	//Sleep(5000);
	/*for (int i = 0; i < 10; i++)
	{
		m.lock();
		std::this_thread::sleep_for(std::chrono::seconds(5));
		std::cout << str << '\n';
		m.unlock();
	}*/
	/*for (int i = 0; i < 10; i++)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		m.lock();
		std::cout << "String #" << i << '\n';
		m.unlock();
	}*/
//}

int sort(int* ahr, int* minus_ahr, int* plus_ahr)
{
	return 0;
}

int sort(int* ahr, char a) {
	int counter = 1;
	switch (a) {
	case '+':
		for (int i = 1; i < ahr[0]; i++)
		{
			if (ahr[i] >= 0) {
				counter++;
				std::cout << ahr[i] << '\n';
			}
		}
		break;
	case '-':
		for (int i = 1; i < ahr[0]; i++)
		{
			if (ahr[i] < 0) {
				counter++;
				std::cout << ahr[i] << '\n';
			}
		}
		break;
	}
	std::cout << '\n';
	return counter;
}

void sort(int*ahr, int* arr, char a)
{
	int counter = sort(ahr, a);
	int* ahr2 = ahr;
	switch (a) {
	case '+':
		for (int i = 1, i2 = 1; i2 < counter; i++)
		{
			if (ahr[i] >= 0) {
				ahr2[i2] = ahr[i];
				std::cout << ahr[i] << '\n';
				i2++;
			}
		}
		break;
	case '-':
		for (int i = 1, i2 = 1; i < counter; i++)
		{
			if (ahr[i] < 0) {
				ahr2[i2] = ahr[i];
				std::cout << ahr[i] << '\n';
				i2++;
			}
		}
		break;
	}
	std::cout << '\n';
	arr[0] = counter;
	for (int i = 0; i < counter-1; i++)
	{
		arr[i+1] = ahr2[i];
		std::cout << ahr2[i] <<'\n';
	}
	delete[] ahr2;
}

int main()
{
	/*double b;
	auto func = [&b](double a) {
		return (int)a;
	};*/

	//double length;
	/*auto func = [&length](const char* str) {
		length = print(str);
	};*/

	//std::future<int> thrf = std::async(print, "Hello, World!");

	//std::thread thr(print, "Hello, World!");
	//std::thread thr([&length](const char* str) {length = print(str);}, "Hello, World!");
	//thr.detach();
	//print("Hello, World!");
	/*for (int i = 0; i < 10; i++)
	{
		m.lock();
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "String #" << i << '\n';
		m.unlock();
	}*/
	//thr.join();
	//std::cout << "Length of \"Hello, World!\" is " << thrf.get();
	int ahr[] = {11, 15, 2, -76, 4, -2, 2, 89, 2, 17, -90};
	int* arr = ahr;
	int* minus_arr = new int[sort(ahr, '-')];
	int* plus_arr = new int[sort(ahr, '+')];
	
	sort(ahr, minus_arr, '-');
	sort(ahr, plus_arr, '+');

	for (int i = 1; i < minus_arr[0]; i++) {
		std::cout << minus_arr[i] << ' ';
	}
	std::cout << '\n';
	for (int i = 1; i < plus_arr[0]; i++) {
		std::cout << plus_arr[i] << ' ';
	}
	return 0;
}
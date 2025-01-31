#include <iostream>
#include <stdexcept>
#include <vector>
#include <random>

// Функция создангия сортированого вектора с отсутствующими элементами
void create_randomized(std::vector<int> &ILoveDihotomia, unsigned const end_num, bool randomize)
{
	std::random_device dev;
	std::mt19937 rnd(dev());
	std::uniform_int_distribution<int> dist(1, 1);
	if (randomize) dist = std::uniform_int_distribution<int> (0, 5);

	for (int i = 1; i <= end_num; i++)
	{
		if (dist(rnd)) ILoveDihotomia.push_back(i);
	}
}

// Вывод вектора с переносом строки
void print(std::vector<int> &ILoveDihotomia)
{
	int line_break = 1;
	for (int i : ILoveDihotomia)
	{
		std::cout << i << ' ';
		if (line_break++ % 33 == 0) std::cout << '\n';
	}
}

// ФУНКЦИЯ НАХОДЯЩАЯ ИНДЕКС ЧИСЛА
int DIHOTOMIA(std::vector<int>& ILoveDihotomia, int num)
{
	if (ILoveDihotomia.front() > num || ILoveDihotomia.back() < num)
	{
		throw(std::out_of_range("Out of range!"));
	}

	int i = ILoveDihotomia.size(), a = 0, b = i - 1, c = ILoveDihotomia.size()/2;
	//unsigned iter_limit = [i]() {unsigned j2 = 1; for (unsigned j = 2; j < i; j *= 2, j2++); return j2;};
	for (; (ILoveDihotomia[c] != num); i /= 2) {
		c = (a + b) / 2;
		(abs(num - ILoveDihotomia[a]) < abs(num - ILoveDihotomia[b]) ? b = c : a = c);
		if (i == 0)
		{
			throw(std::out_of_range("Out of index!"));
		}
	}
	return c;
}

int main()
{
	setlocale(0, "");
	// 1. DIHOTAMIA (binary search)
	/* А СЕЙЧАС ДАВАЙ ТЕ ОБЪЯСНЮ КАК РАБОТАЕТ ДИХОТОМИЯ...
	[1000 строк комментариев]
	И ТАК МЫ МОЖЕМ НАЙТИ ЛЮБЫЕ ЗНАЧЕНИЯ ФУНКЦИИ, ВСЕМ СПАСИБО И ПОКА-ПОКА
	*/
	std::vector<int> ILoveDihotomia;
	
	std::cout << "Creat randomized????? ";
	bool make_rand;
	std::cin >> make_rand;
	create_randomized(ILoveDihotomia, 99, make_rand);
	print(ILoveDihotomia);

	try {
		std::cout << "\nWhat number do you want???? ";
		int num;
		std::cin >> num;
		std::cout << '\n' << DIHOTOMIA(ILoveDihotomia, num) << '\n';
	}
	catch (...) {
		std::cout << char(1) << char(1) << char(1) << char(1) << char(1);
	}
	std::cin >> make_rand;
	system("cls");

	// 2. NUKE BOMBER
	const double g = 9.81; // Скорость свободного падения
	double H; // Высота
	std::cout << "Введите высоту: ";
	std::cin >> H;
	//double T = sqrt(H * 2 / g); // Время полёта
	//double v = g * T; // Горизонтальная скорость
	double v2 = 100; // Вертикальная скорость
	std::cout << "Введите скорость самолёта: ";
	std::cin >> v2;
	//double V = sqrt(v * v + v2 * v2);
	double V = sqrt(v2 * v2 + 2 * g * H);
	std::cout << V;
	return 0;
}
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <random>

std::random_device dev;
std::mt19937 gen(dev());
std::uniform_int_distribution<uint16_t> dist(1, 10000);



class Graph
{
	std::vector<std::vector<uint16_t>> matrix; // Матрица смежности

public:
	using Edge = std::pair<uint16_t, uint16_t>;
	Graph(uint16_t rows = 10, uint16_t cols = 10) : matrix(rows * rows, std::vector<uint16_t>(cols * cols, 0.0))
	{ }

	void setValue(uint16_t i, uint16_t j, uint16_t value)
	{
		matrix[i][j] = value;
	}

	std::list<Edge> buildTree()
	{
		std::list<Edge> l;

		std::list<uint16_t> q;
		for (uint16_t i = 1; i < matrix.size(); ++i)
		{
			q.push_back(i);
		}

		std::list<uint16_t> p = { 0 };
		while (!q.empty())
		{
			uint16_t min = 10001, v1, v2;
			for (uint16_t el : p)
			{
				for (uint16_t j = 0; j < matrix.size(); ++j)
				{
					if (matrix[el][j] == 0 || std::find(p.begin(), p.end(), j) != p.end()) continue;

					if (matrix[el][j] < min)
					{
						min = matrix[el][j];
						v2 = j;
						v1 = el;
					}
				}
			}
			p.push_back(v2);
			q.erase(std::find(q.begin(), q.end(), v2));
			l.push_back({ v1, v2 });
		}

		return l;
	}
};

void fill(Graph& g)
{
	// Угловые вершины
	g.setValue(0, 1, dist(gen));
	g.setValue(0, 10, dist(gen));

	g.setValue(9, 8, dist(gen));
	g.setValue(9, 19, dist(gen));

	g.setValue(90, 91, dist(gen));
	g.setValue(90, 80, dist(gen));

	g.setValue(99, 98, dist(gen));
	g.setValue(99, 89, dist(gen));

	// Создание границ
	for (uint16_t i = 1; i <= 8; ++i)
	{
		g.setValue(i, i - 1, dist(gen));
		g.setValue(i, i + 1, dist(gen));
		g.setValue(i, i + 10, dist(gen));
	}
	for (uint16_t i = 91; i <= 98; ++i)
	{
		g.setValue(i, i - 1, dist(gen));
		g.setValue(i, i + 1, dist(gen));
		g.setValue(i, i - 10, dist(gen));
	}
	for (uint16_t i = 10; i <= 80; i += 10)
	{
		g.setValue(i, i - 10, dist(gen));
		g.setValue(i, i + 10, dist(gen));
		g.setValue(i, i + 1, dist(gen));
	}
	for (uint16_t i = 19; i <= 89; i += 10)
	{
		g.setValue(i, i - 10, dist(gen));
		g.setValue(i, i + 10, dist(gen));
		g.setValue(i, i - 1, dist(gen));
	}

	// Внутренние вершины
	for (uint16_t i = 1; i <= 8; ++i)
	{
		for (uint16_t j = 1; j <= 8; ++j)
		{
			g.setValue(i * 10 + j, i * 10 + j - 1, dist(gen));
			g.setValue(i * 10 + j, i * 10 + j + 1, dist(gen));
			g.setValue(i * 10 + j, i * 10 + j - 10, dist(gen));
			g.setValue(i * 10 + j, i * 10 + j + 10, dist(gen));
		}
	}
}

std::vector<std::vector<bool>> generateField(std::list<Graph::Edge> const& g)
{
	std::vector<std::vector<bool>> field(21, std::vector<bool>(21, true));
	for (int i = 0; i < 2 * 10 + 1; ++i)
	{
		for (int j = 0; j < 2 * 10 + 1; ++j)
		{
			if (i % 2 == 1 && j % 2 == 1)
			{
				field[i][j] = false;
			}
		}
	}
	for (auto const& edge : g)
	{
		uint16_t v1 = edge.first;
		uint16_t v2 = edge.second;

		uint16_t r1 = v1 / 10, r2 = v2 / 10;
		uint16_t c1 = v1 % 10, c2 = v2 % 10;

		field[r1 + r2 + 1][c1 + c2 + 1] = false;
	}
	return field;
}

int main()
{
	Graph g(10, 10);
	
	fill(g);

	auto field = generateField(g.buildTree());

	for (auto const& i : field)
	{
		for (bool const& j : i)
		{
			std::cout << (!j ? "\033[40m  " : "\033[107m  \033[40m");
		}
		std::cout << '\n';
	}

	return 0;
}
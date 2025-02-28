#include <iostream>
#include <vector>

class Matrix;

class MatrixRow
{
private:
	std::vector<double> data;

	MatrixRow(uint16_t cols = 3) : data(cols) {}

	/*double& operator[](int i)
	{
		return data[i];
	}*/

	void SetValue(int col, double value)
	{
		data[col] = value;
	}

	friend std::ostream& operator<<(std::ostream& str, Matrix const& m);
	friend Matrix;
};

class Matrix
{
private:
	std::vector<MatrixRow> data;

public:
	Matrix(uint16_t rows = 3, uint16_t cols = 3)
	{
		data = std::vector<MatrixRow>(rows, MatrixRow(cols));
	}

	/*MatrixRow& operator[](int i)
	{
		return data[i];
	}*/

	void SetCellValue(int row, int col, double value)
	{
		data[row].SetValue(col, value);
	}

	friend std::ostream& operator<<(std::ostream& str, Matrix const& m);
	friend MatrixRow;
};

std::ostream& operator<<(std::ostream& str, Matrix const& m)
{
	str << '[';

	for (int i = 0; i < m.data.size(); ++i)
	{
		for (int j = 0; j < m.data[i].data.size(); ++j)
		{
			str << m.data[i].data[j] << ' ';
		}
		str << '\n'; //<< (i == m.data.size() - 1 ? ']' : '\n');
	}

	return str << ']';
}

int main()
{
	Matrix m;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			m.SetCellValue(i, j, i * 3 + j);
		}
	}

	std::cout << m << "\n\n";

	return 0;
}
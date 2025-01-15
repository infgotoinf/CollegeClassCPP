#include <iostream>

void foo() {
	static int a = 10;
	a++;
	std::cout << a << ' ';
}

struct Matrix {
	double** mat[3];
	static Matrix eye(int n) {
		double* ma = new double[n] { 0 };
		double** matrix = new double* [n] { ma };
		for (int i = 0; i < n; i++) {
			ma[i] = 1;
			matrix[i] = ma;
		}
		Matrix a = { .mat = matrix };
		return a;
	}
};

int main() {
	foo(); foo(); foo(); 
	Matrix a = Matrix::eye(3);
	for (int i = 0; i < 3; i++) {
		for (int i2 = 0; i2 < 3; i2++) {
			std::cout << a.mat[i][i2] << ' ';
		}
		std::cout << '\n';
	}
	return 0;
}
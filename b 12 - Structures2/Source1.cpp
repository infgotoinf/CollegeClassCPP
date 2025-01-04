#include <iostream>
#include <vector>

struct vectora {
	int* a;
	int size;
	int capacity;

	void vectr(int e, int d, int* m) {
		size = e;
		capacity = d;
		a = new int[d];
		for (int i = 0; i < size; i++) {
			a[i] = m[i];
		}
	}
	int at(int e) {
		if (e < size) {
			return a[e-1];
		}
	}
	void push_back(int e) {
		size++;
		if (size >= capacity) {
			capacity *= 2;
			int* b = new int[capacity];
			for (int i = 0; i < size - 1; i++) {
				b[i] = a[i];
			}
			b[size - 1] = e;
			vectr(size, capacity, b);
			delete[] b;
		}
		else {
			a[size - 1] = e;
		}
	}
	void insert(int e, int idx) {
		size++;
		if (size >= capacity) {
			capacity *= 2;
			int* b = new int[capacity];
			for (int i = 0; i < size; i++) {
				if (i == idx) {
					continue;
				}
				b[i] = a[i];
			}
			b[idx] = e;
			vectr(size, capacity, b);
			delete[] b;
		}
		else {
			a[size - 1] = e;
			for (int i = size - 1; idx <= i; i--) {
				a[i+1] = a[i];
			}
			a[idx] = e;
		}
	}

	~vectora() {
		delete[] a;
	}
};

int main() {
	vectora f;
	int arr[10] = { 43, 523, -9, 234, 54, 76, 1, -69, 0, 1};
	f.vectr(10, 10, arr);
	for (int i = 0; i < f.size; i++) {
		std::cout << f.a[i] << ' ';
	}
	std::cout << '\n';

	std::cout << f.at(4) << '\n';

	f.push_back(777);
	for (int i = 0; i < f.size; i++) {
		std::cout << f.a[i] << ' ';
	}
	std::cout << '\n';

	f.insert(2007, 10);
	for (int i = 0; i < f.size; i++) {
		std::cout << f.a[i] << ' ';
	}
	return 0;
}
#include <iostream>
#include <vector>

template <typename T>
T add(T a, T b) {
	return a + b;
}

template <typename T1, typename T2>
void printPair(T1 a, T2 b) {
	std::cout << a << '\t' << b << '\n';
}

template <typename T3>
struct Array {
private:
	T3* data;
	unsigned int size = 0;
	unsigned int capacity = 2;
public:
	Array(int init_capacity = 4) : capacity(init_capacity), size(0), data(new T3[init_capacity]) {}

	~Array() {
		delete[] data;
	}

	void add(T3 value) {
		if (size == capacity) {
			capacity *= 2;
			T3* old_data = data;
			data = new T3[capacity];
			for (int i = 0 ; i < size; i++){
				data[i] = old_data[i];
			}
		}
		data[size++] = value;
	}

	T3 operator[](unsigned int index) {
		if (index > size) {
			int no = - 1;
			return no;
			//throw out_of_range("Idx out of range");
		}
		return data[index];
	}

	auto GetSize() {
		return size;
	}
};

int main()
{
	//std::vector<int> vec1;
	//std::vector<double> vec2;
	//std::vector<float> vec3;
	//std::vector<char> vec4;
	//std::vector<bool> vec5; // !??!?!??

	std::cout << add(9, 14) << '\n';
	std::cout << add(9.65, 14.7) << '\n';
	std::cout << add(9e+2, 14e-1) << '\n';
	std::cout << add('F', 'D') << '\n';
	std::cout << add(true, false) << "\n\n";

	printPair(9, 14.23);
	printPair(9.65, 'G');
	printPair(true, 14e-1);
	printPair('F', 45);
	printPair(12e+4, false);
	std::cout << '\n';

	Array<int> nums;
	nums.add(10);
	nums.add(10);
	nums.add(10);
	nums.add(10);
	nums.add(10);

	for (int i = 0; i < nums.GetSize(); i++) {
		std::cout << nums[i] << ' ';
	}

	//// value = 0
	//data[size / 8] &= ~(1 << (size % 8));

	//// value = 1
	//data[size / 8] |= (1 << (size % 8));
	return 0;
}
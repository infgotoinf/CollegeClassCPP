#include <iostream>
#include <stdexcept>
#include <vector>
#include <tuple>

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
	uint16_t size = 0;
	uint16_t capacity = 2;
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
		if (index >= size) throw std::out_of_range("Out of range");

		return data[index];
	}

	uint16_t GetSize() const
	{
		return size;
	}
};



template <typename T4>
struct BoolArray {
private:
	T4* data;
	uint16_t size = 0;
public:
	BoolArray(uint16_t siz)
	{
		size = 0;
		data = new int8_t[siz / 8];
	}

	~BoolArray()
	{
		delete[] data;
	}

	/*void add(T3 value) {
		if (size == capacity) {
			capacity *= 2;
			T4* old_data = data;
			data = new T4[capacity];
			for (int i = 0; i < size; i++) {
				data[i] = old_data[i];
			}
		}
		data[size++] = value;
	}*/

	T4 operator[](unsigned int index) {
		if (index >= size) throw std::out_of_range("Out of range");

		uint16_t v = index / 8;
		uint16_t u = index % 8;

		return (data[v] >> (7 - u)) & 1;
	}

	uint16_t GetSize() const
	{
		return size;
	}
};



template <typename First>
void print2(First f)
{
	std::cout << f << "\n\n";
}

template <typename TV>
void print2(std::vector<TV> vec)
{
	for (auto i : vec) {
		std::cout << i << ' ';
	}
	std::cout << "\n\n";
}

template <typename First, typename ... TT>
void print2(First f, TT ... rest)
{
	std::cout << f << ' ';
	print2(rest...);
}

//template <typename a, typename c>
//struct IsSame
//{
//	static const bool bo = false;
//	IsSame(a b, c a) {};
//};
//template <typename a, typename a>
//struct IsSame
//{
//	static const bool bo = true;
//	IsSame(a b, a a) {};
//};



template <typename T>
struct Optional
{
	T* value;
	Optional(T* v = nullptr)
	{
		value = v;
	}

	bool booling()
	{
		if (value == nullptr) return 0;
		return (bool)value;
	}

	T* operator*()
	{
		if (value == nullptr) return "No";
		return value;
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
	std::cout << '\n' << std::endl;

	//// value = 0
	//data[size / 8] &= ~(1 << (size % 8));

	//// value = 1
	//data[size / 8] |= (1 << (size % 8));



	/*print2(10, "dfji", 98.3, 't', true, 16e+3);

	std::tuple<int, double, std::vector<bool>> a(10, 98.3, {true, true, false});
	std::get<2>(a)[1] = false;
	std::cout << std::get<2>(a)[1];

	print2(a);

	IsSame<char, int> q('a', 1);
	IsSame<char, int> q2('a', 's');
	std::cout << q.bo;
	std::cout << q2.bo;*/



	int* da = new int{ 12 };
	Optional<int*> aaa;
	Optional<int*> bbb(da);

	std::cout << aaa.booling() << ' ' << *aaa << '\n';
	std::cout << bbb.booling() << ' ' << *bbb << '\n';
	return 0;
}
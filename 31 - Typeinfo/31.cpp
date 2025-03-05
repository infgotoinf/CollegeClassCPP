#include <iostream>
#include <typeinfo>
#include <unordered_set>
#include <list>
#include <any>

class A
{
private:
	int field;

public:
	A() = default;
	virtual ~A() = default;
};

class B : public A
{
public:
	B() : A() {}
	~B() = default;
};



using typeinforef = std::reference_wrapper<std::type_info const>;

template<>
class std::hash<typeinforef>
{
public:
	size_t operator()(typeinforef val) const
	{
		return val.get().hash_code();
	}
};

template<>
class std::equal_to<typeinforef>
{
public:
	bool operator()(typeinforef val1, typeinforef val2) const
	{
		return val1.get() == val2.get();
	}
};


int main()
{
	/*A* a = new B;

	if (typeid(B) == typeid(*a))
	{
		std::cout << "Variable is " << typeid(B).name();
	}
	else
	{
		std::cout << "Variable is not " << typeid(B).name();
	}

	delete a;*/


	std::unordered_set<typeinforef> set;

	set.insert(typeid(A));
	set.insert(typeid(int));
	set.insert(typeid(void));

	for (auto & type : set)
	{
		std::cout << type.get().name() << '\n';
	}
	           

	std::any a;

	a = std::list<double>{};

	a = 10;

	a = "Hello world!";
	return 0;
}
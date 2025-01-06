#include <iostream>
//#include <windows.h>
#include <string>

#ifdef _DEBUG
std::string txt = "I'm in your walls";
#define DBG(txt) std::cout << "\033[31m" << txt << "\033[0m"
#define DBG2 std::cout << "\033[31m" << __FILE__ << ' ' << __FUNCTION__ << ' ' <<  __LINE__ << "\033[0m" << '\n'
#else
std::string txt;
#define DBG(txt)
#define DBG2
#endif

//constexpr int n = 10;

//#define RUNTIME

#define maxx(a, b) a < b ? b : a
#define strokoi(a) #a
#define stepen10(a) 10e##a
//#define STRUCT(a) struct a{ int value; double value2; a(int i, double d) {this->value = i; this->value2 = d;}}
#define STRUCT(a) struct a{ \
	int value; \
	double value2; \
	a(int i, double d) { \
		this->value = i; \
		this->value2 = d; \
	} \
}


void fun(std::string& text) {
	text = "UwU";
	//text.append("UwU");
}


#define delenie10(a) \
if constexpr (a != 0) { \
std::cout << 10 / a; \
} \
else { \
	throw std::logic_error("lol"); \
}

int main() {
	setlocale(0, "");
	//std::string txt = "I'm in your walls";
	/*int aa, bb;
	std::cin >> aa >> bb;
	std::cout << (maxx(aa,bb)) << '\n';*/
	std::cout << (strokoi(21 + 89 * 0)) << '\n';
	std::cout << std::fixed << stepen10(307) << '\n';
	STRUCT(kjdsnhafk);
	kjdsnhafk omg(12, 12.2);
	DBG2;
	DBG(txt);
	//Beep(440, 1000);


	std::string text = "OwO";
	fun(text);
	std::cout << '\n' << text << '\n';


	try {
		delenie10(0);
	}
	catch (std::logic_error& a) {
		std::cout << a.what();
	}

	return 0;
}
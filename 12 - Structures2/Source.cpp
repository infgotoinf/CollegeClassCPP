#include <iostream>

struct IPAdress {
	int a, b, c, d;
	bool isvalid() {
		return true;
	}
};

void printIP(IPAdress ip) {
	std::cout << ip.a << '.' << ip.b << '.' << ip.c << '.' << ip.d << '\n';
}
bool validation(IPAdress ip) {
	bool check = true;
	int ips[] = { ip.a, ip.b, ip.c, ip.d };
	for (int i = 0; i < 4; i++) {
		if (!(ips[i] <= 255 && ips[i] >= 0)) {
			check = false;
			break;
		}
	}
	if ((ips[1] == 0 && ips[2] == 0 && ips[3] == 0 && ips[4] == 0) || (ips[1] == 255 && ips[2] == 255 && ips[3] == 255 && ips[4] == 255)) {
		check = false;
	}
	return check;
}
bool privateip(IPAdress ip) {
	bool check = false;
	if (ip.a == 172) {
		for (int i = 16; i < 32; i++) {
			if (ip.b == i) {
				check = true;
				break;
			}
		}
	}
	else if (ip.a == 10) {
		check = true;
	}
	else if (ip.a == 192 && ip.b == 168) {
		check = true;
	}
	return check;
}
bool loopback(IPAdress ip) {
	if (ip.a == 127 && ip.b == 0 && ip.c == 0) {
		return true;
	}
	else {
		return false;
	}
}
bool apipa(IPAdress ip) {
	if (ip.a == 169 && ip.b == 254) {
		return true;
	}
	else {
		return false;
	}
}
bool publicip(IPAdress ip) {
	if (!privateip(ip) && !loopback(ip) && !apipa(ip)) {
		return true;
	}
	else {
		return false;
	}
}



struct User{
	char* login;
	char* password;
	char* name;
};

int main() {
	IPAdress one = { .a = 209, .b = 65, .c = 114, .d = 32 };
	printIP(one);
	IPAdress two = { .a = 172, .b = 16, .c = 777, .d = 32 };
	printIP(two);
	IPAdress three = { .a = 127, .b = 0, .c = 0, .d = 32 };
	printIP(three);
	IPAdress four = { .a = 169, .b = 254, .c = 345, .d = 32 };
	printIP(four);
	std::cout << '\n';

	std::cout << (validation(one) != 0 ? "Is valid" : "invalid") << '\n';
	std::cout << (validation(two) != 0 ? "Is valid" : "invalid") << '\n';
	std::cout << (validation(three) != 0 ? "Is valid" : "invalid") << '\n';
	std::cout << (validation(four) != 0 ? "Is valid" : "invalid") << "\n\n";

	std::cout << (privateip(one) != 0 ? "Is private" : "Is not private") << '\n';
	std::cout << (privateip(two) != 0 ? "Is private" : "Is not private") << '\n';
	std::cout << (privateip(three) != 0 ? "Is private" : "Is not private") << '\n';
	std::cout << (privateip(four) != 0 ? "Is private" : "Is not private") << "\n\n";

	std::cout << (loopback(one) != 0 ? "Is loopback" : "Is not loopback") << '\n';
	std::cout << (loopback(two) != 0 ? "Is loopback" : "Is not loopback") << '\n';
	std::cout << (loopback(three) != 0 ? "Is loopback" : "Is not loopback") << '\n';
	std::cout << (loopback(four) != 0 ? "Is loopback" : "Is not loopback") << "\n\n";

	std::cout << (apipa(one) != 0 ? "Is apipa" : "Is not apipa") << '\n';
	std::cout << (apipa(two) != 0 ? "Is apipa" : "Is not apipa") << '\n';
	std::cout << (apipa(three) != 0 ? "Is apipa" : "Is not apipa") << '\n';
	std::cout << (apipa(four) != 0 ? "Is apipa" : "Is not apipa") << "\n\n";

	std::cout << (publicip(one) != 0 ? "Is public" : "Is not public") << '\n';
	std::cout << (publicip(two) != 0 ? "Is public" : "Is not public") << '\n';
	std::cout << (publicip(three) != 0 ? "Is public" : "Is not public") << '\n';
	std::cout << (publicip(four) != 0 ? "Is public" : "Is not public") << "\n\n";
	
	IPAdress mask = { .a = 255, .b = 255, .c = 255, .d = 0 };
	printIP(mask);
	std::cout << mask.isvalid() << "\n\n";



	User aa;
	aa.login = new char[] {"CoolGuy228"};
	aa.password = new char[] {"qwerty123"};
	aa.name = nullptr;
	if (aa.name != nullptr) {
		std::cout << aa.name;
	}
	else {
		std::cout << "Error";
	}

	

	return 0;
}
#include <iostream>
#include <random>
#include <vector>

bool is_prime(unsigned n)
{
	for (unsigned int i = 2; i < sqrt(n); ++i)
	{
		if (n % i == 0) return false;
	}
	return true;
}

unsigned prime()
{
	std::random_device dev;
	std::mt19937 rnd(dev());
	std::uniform_int_distribution<unsigned> dist(2, 255);
	unsigned random = dist(rnd);
	do {
		++random;
	} while (!is_prime(random));
	return random;
}

unsigned not_dihotomy(int K, int e, int phi) {
	while ((K * phi + 1) % e != 0) {
		K++;
	}
	return K;
}

std::vector<int> massageeater(std::string massage) {
	std::vector<int> eater;
	int pos = 0;
	for (char i : massage) {
		eater.push_back((int)i);
		pos++;
	}
	return eater;
}

std::vector<long long int> c_formul(std::vector<int> inted_massage, int e, int n) {
	std::vector<long long int> c_formul;
	int pos = 0;
	for (int i : inted_massage) {
		long long int m = 1;
		for (int i2 = 0; i2 < e; i2++) m *= i;
		c_formul.push_back(m % n);
		pos++;
	}
	return c_formul;
}

std::vector<long long int> m_formul(std::vector<long long int> c_formul, int d, int n) {
	std::vector<long long int> m_formul;
	int pos = 0;
	for (int i : c_formul) {
		long long int c = 1;
		for (int i2 = 0; i2 < d; i2++) c *= i;
		m_formul.push_back(c % n);
		pos++;
	}
	return m_formul;
}

int main() {
	unsigned p = prime(), q = prime();
	unsigned n = p * q;
	unsigned phi = (p - 1) * (q - 1);
	unsigned e = 7;
	unsigned K = not_dihotomy(0, e, phi);
	unsigned d = (K * phi + 1) / e;
	
	std::string massage = "Hello, World!";

	std::vector<int> inted_massage = massageeater(massage);

	std::vector<long long int> c = c_formul(inted_massage, e, n);

	std::vector<long long int> m = m_formul(c, d, n);

	union Symbol {
		char a;
		int b;
	};

	for (int i = 0; i < c.size(); i++)
	{
		std::cout << n << '\t' << d << '\t' << inted_massage[i] << '\t' << c[i] << '\t' << m[i] << '\n';
	}

	return 0;
}
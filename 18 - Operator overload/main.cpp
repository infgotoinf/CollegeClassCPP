#include <iostream>

//struct String {
//	String operator+(String str) {}
//};


struct drob {
    int a;
    unsigned b;
    drob operator+(drob ba) {
        drob c;
        c.a = a * ba.b + ba.a * b;
        c.b = b * ba.b;
        std::cout << "sum\t";
        return c;
    }
    drob operator-(drob ba) {
        drob c;
        c.a = a * ba.b - ba.a * b;
        c.b = b * ba.b;
        std::cout << "diff\t";
        return c;
    }
    drob operator*(drob ba) {
        drob c;
        c.a = a * ba.a;
        c.b = b * ba.b;
        std::cout << "mult\t";
        return c;
    }
    drob operator/(drob ba) {
        drob c;
        c.a = b * ba.a;
        c.b = a * ba.b;
        std::cout << "div\t";
        return c;
    }
    bool operator==(drob ba) {
        return ((double)a / ba.a) == ((double)b / ba.b);
    }
    operator double() {
        return (double)a / b;
    }
    drob operator~() {
        int num = 1;
        for (int i = 2; i <= a && i <= (int)b; i++) {
            if (((double(a) / i) == a / i) && ((double(b) / i) == b / i)) {
                num = i;
            }
        }
        drob c = { a / num, b / num };
        return c;
    }
};

//void print(drob c) {
//    std::cout << c.a << '/' << c.b << '\n';
//}

std::ostream& operator << (std::ostream& stream, drob c) {
    stream << c.a << '/' << c.b <<'\n';
    return stream;
}

    int main() {
        /*String a;
        String b;
        String c = a + b;*/

        drob a = {.a = 2, .b = 4}, b = { .a = 7, .b = 8 };
        std::cout << a + b;
        std::cout << a - b;
        std::cout << a * b;
        std::cout << a / b;
        std::cout << (a == b) << '\n';
        std::cout << double(a) << '\n';
        std::cout << double(b) << '\n';
        std::cout << ~a;
        std::cout << ~b;
        return 0;
    }
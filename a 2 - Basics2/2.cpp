#include <iostream>

int main()
{
    /*
    std::cout << "Give a number from 0 to 10: ";
    int a;
    do {
        std::cin >> a;
    } while (a < 0 || a > 10);
    std::cout << "Pasiba \n";

    std::cout << (a % 2 == 0 ? "Even" : "Odd") << '\n';
    */

    /*
    std::cout << "Give a number from 0 to A: \n";
    char b;
    std::cin >> b;
    int c;
    switch (b) {
    case 'A':
        c = 10;
        break;
    case 'B':
        c = 11;
        break;
    case 'C':
        c = 12;
        break;
    case 'D':
        c = 13;
        break;
    case 'E':
        c = 14;
        break;
    case 'F':
        c = 15;
        break;
    default:
        c = b - '0';
    }
    std::cout << c << '\n';
    */

    /*
    std::cout << "Give a number: ";
    double d;
    std::cin >> d;
    std::cout << "Give a pow: ";
    int e;
    std::cin >> e;
    if (e > 0) {
        for (int i = 1; i < e; i++) {
            d *= d;
        }
    }
    else if (e < 0) {
        for (int i = -1; i > e; i--) {
            d *= d;
        }
        d = 1 / d;
    }
    else {
        if (d == 0) {
            std::cout << "Ошибка человечества ";
        }
    }
    std::cout << d;
    */

    /*
    std::cout << "Give a number: ";
    double f;
    std::cin >> f;
    std::cout << "Give a number 2: ";
    double g;
    std::cin >> g;
    double k = f;
    if (g >= 0) {
        double k = f - g;
        while (0 < k) {
            k -= g;
        }
        if (k != 0) {
            k += g;
        }
        std::cout << k << '\n';
    }
    else {
        double k = -(f + g);
        while (0 > k) {
            k -= g;
        }
        k += g;
        std::cout << k << '\n';
    }
    */

    std::cout << "Give a number: ";
    double x;
    std::cin >> x;
    std::cout << "Give a number how much round: ";
    unsigned int y;
    std::cin >> y;
    double z;
    int v = 10;
    int v1 = v;
    if (y > 0) {
        for (int i = 1; i < y; i++) {
            v *= 10;
        }
    }
    else {
        v = 1;
    }
    v1 = v * x;
    z = double(v1) / v;
    std::cout << z;

    return 0;
}
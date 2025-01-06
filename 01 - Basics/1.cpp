#include <iostream>
#include <cmath>

int main() {
    /*
    int x;
    std::cout << "Give a number ";
    std::cin >> x;

    double y = x/2;
    double old = y;
    for (int i = 0; i < 10; i++) {
        y = 0.5 * (old + x/old);
        old = y;
    }
    std::cout << y;
    */
    double y = 0;
    for (double i = 5; i < 1000000; i=i+4) {
        y = y + (-(1/(i - 2)) + 1/i);
    }
    std::cout << 4 * (1 + y);
}

/*
double sinusirovanie(double x) {
    return x - std::pow(x, 3) / 6 + std::pow(x, 5) / 120 - std::pow(x, 7) / 5040;
}
int main()
{
    double const pi = 3.1415925;
    double forsin = pi/2;
    double x;
    std::cout << "Give a number: ";
    std::cin >> x;
    while (x > 1) {
        x = x / (forsin * 4);
    }

    double sin;
    if (0 <= forsin) {
        sin = sinusirovanie(x);
    }
    else if (forsin <= 2 * forsin) {
        sin = -sinusirovanie(x);
    }
    else if (forsin * 2 <= 3 * forsin) {
        sin = sinusirovanie(-x);
    }
    else {
        sin = -sinusirovanie(-x);
    }
    std::cout << sin;
    
    return 0;
}
*/
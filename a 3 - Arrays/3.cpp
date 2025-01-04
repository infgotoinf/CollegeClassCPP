#include <iostream>

int main()
{
    /*
    int massa[10] = {3, 5, 78, -7, 4, 0, -2, -50, 10, -19};

    int arr[10];
    for (int i : massa) {
        arr[i] = i;
    }

    int i2;
    double b = 0;
    double a = 0;
    for (i2 = 0; i2 < sizeof(massa) / sizeof(int); i2++) {
        if (massa[i2] == 0) {
            continue;
        }
        a += massa[i2];
            b += 1.0 / massa[i2];
    }
    a = a / double(i2);
    std::cout << a << '\n';
    b = double(i2) / b;
    std::cout << b << '\n';
    */

    /*
    double r = 3.99;
    double x = 0.15;
    for (int i = 0; i < 15; i++) {
        x = r * x * (1 - x);
        std::cout << x << '\n';
    }
    */

    /*
    int g = 0;
    char stringi[] = "UwUOwOU";
    for (int i = 0; i < sizeof(stringi) - 1; i++) {
        if (stringi[i] == 'U') {
            g += 1;
        }
    }
    std::cout << g << '\n';

    for (int i = 0; i < sizeof(stringi) - 4; i++) {
        if (stringi[i] == 'O') {
            if (stringi[i+1] == 'w') {
                if (stringi[i+2] == 'O') {
                    std::cout << "TRUE" << '\n';
                }
            }
        }
    }
    */

    int x;
    std::cout << "Give a number ";
    std::cin >> x;
    double y = x / 2;
    double old = y;
    const double e = 0.00001;
    while (true) {
        y = 0.5 * (old + x / old);
        if (((y - old < e)>0)?(y - old < e):(-(y - old) < e)) {
            break;
        }
        old = y;
    }
    std::cout << y;

    return 0;
}
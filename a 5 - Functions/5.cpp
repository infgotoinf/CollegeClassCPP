#include <iostream>
#include <cmath>

int chmod(char flag) {
    std::cout << "chmod -" << flag << ' ';
    return 777;
};

void quotes(std::string a) {
    std::cout << '"' << a << '"';
};

int evklid(int a, int b) {
    int c = a;
    for (c; c > 0;) {
        c = (a < b ? b-a : a-b);
        b = a;
        a = c;
    }
    c = b;
    return c;
};

void evklid2(double c) {
    int a = 1;
    while (c != int(c)) {
        c *= 10;
        a *= 10;
    }
    int b = evklid(c, a);
    std::cout << c / b << '/' << a / b;
};

bool polindrom(int a) {
    int b = a % 2;
    int c = (a - b) / 2;
    int i = 2;
    int d = a;
    for (i; d > 0; i++) {
        d = a;
        d = a - pow(10, i);
    }
    int i2 = 10*pow(10, i);
    std::cout << i << '\n';

    for (int i3 = 1; i3 < i; i3++) {
        int g = a - a % i2;
        int h = pow(10, i3);
        int f = a % h;
        std::cout << f << ' ' << g << '\n';
    }
    return true;
};

void up(char a[]) {
    const int wow = 32;
    for (int i = 0; i < (sizeof(a)/sizeof(char)); i++){
    int b = a[i];
    char c = b;
    if (65 < b && b > 123) {
        c = char(b - wow);
    }
    std::cout << c;
    }
}

int main()
{
    /*int matrix[5][5] = {{1, 8, 0, 4, 5}, {6, 3, 1, 5, 7}, {0, 9, 8, 3, 2}, {5, 4, 6, 3, 2}, {2, 5, 6, 7, 0}};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }

    std::cout << "Choose lines to change places from [1] to [5]\n";
    int o;
    int l;
    std::cin >> o;
    std::cin >> l;
    o--;
    l--;
    for (int i = 0; i < 5; i++) {
        int u = matrix[o][i];
        matrix[o][i] = matrix[l][i];
        matrix[l][i] = u;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';


    for (int i = 0; i < 5; i++) {
        for (int j = i; j < 5; j++) {
            int u = matrix[j][i];
            matrix[j][i] = matrix[i][j];
            matrix[i][j] = u;
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            std::cout << matrix[i][j] << ' ';
        }
        std::cout << '\n';
    }*/

    std::cout << chmod('R') << " /\n";

    quotes("awawa");

    std::cout << '\n' << evklid(81, 36) << '\n';

    evklid2(0.65);
    std::cout << '\n' << '\n';

    //polindrom(1234);

    char chr[] = "gd123hhrter";
    up(chr);

    return 0;
}

#include <iostream>
#include <cmath>

char* substring(char* stra, int a, int b) {
    char* c = new char[b-a+2] {};
    int i = 0;
    for (; i <= b-a; i++) {
        c[i] = stra[a+i];
    }
    c[i] = '\0';
    return c;
}

char* stringsum(char* one, char* two) {
    int lol = strlen(one) + strlen(two);
    char* three = new char[lol + 2] {};
    int i = 0;
    for (; i <= lol; i++) {
        if (i < strlen(one)) {
            three[i] = one[i];
        }
        else if (i > strlen(one)) {
            int f = i - strlen(one) - 1;
            three[i-1] = two[f];
        }
    }
        //three[i] = '\0';
        return three;
}

int main()
{
    /*
    double S = 10000;
    double koren = sqrt(2);
    double a = sqrt(S / koren)/koren;
    double b = a / koren;
    std::cout << "Give me paper: ";
    int paper;
    std::cin >> paper;
    for (; paper > 0; paper--) {
        if (a > b) {
            a /= 2;
        }
        else {
            b /= 2;
        }
    }
    a *= 2;
    b *= 2;
    std::cout << "De sides are " << a << " and " << b << " ploshad " << a*b << "\n\n";
    */

    std::cout << "Give a string: ";
    char g[100];
    std::cin >> g;
    std::cout << "Give another string: ";
    char g1[100];
    std::cin >> g1;
    /*std::cout << "Give a: ";
    int a, b;
    std::cin >> a;
    std::cout << "Give b: ";
    std::cin >> b; */
    
    //char* subst = substring(g, a, b);
    //std::cout << '\n' << subst;

    char* stringsu = stringsum(g, g1);
    std::cout << '\n' << stringsu;
    delete[] stringsu;
    return 0;
}
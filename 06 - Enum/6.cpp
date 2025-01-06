#include <iostream>
#include <cmath>

int l = 0;
int recurse(int n) {
    if (n != 1) {
        if (l == 0) {
            l = n;
        }
        n--;
        l *= n;
        recurse(n);
    }
    return l;
}

std::string f;
int ultra_i = 0;
void dva(int h) {
    ultra_i++;
    if (h > 1) {
        std::cout << h % 2;
        h = (h % 2 ? (h - 1) / 2 : h / 2);
        dva(h);
    }
}


enum Color {
    GRAY = 90,
    RED = 91,
    GREEN = 92,
    BLUE = 94,
    PURPLE = 95,
    CYAN = 96,
    WHITE = 97,
    reset = 0
};

enum Fon {
    GRAY1 = 100,
    RED1 = 101,
    GREEN1 = 102,
    BLUE1 = 104,
    PURPLE1 = 105,
    CYAN1 = 106,
    WHITE1 = 107,
    reset1 = 0
};

void colorprint(Color s, const char stringers[]) {
    std::cout << "\033[" << s << "m" << stringers << "\033[0m" << '\n';
}
void colorprint(Fon s, const char stringers[]) {
    std::cout << "\033[" << s << "m" << stringers << "\033[0m" << '\n';
}


bool two(int g) {
    g = g & (g-1);
    if (g == 0) {
        return true;
    }
    return false;
}

int main()
{
    /*
    std::cout << "Give me a number ";
    char a[16];
    std::cin >> a;
    int c = 0;
    double d = 0;
    bool check = false;

    for (int i = 0; i < sizeof(a); i++) {
        if (a[i] == -52 || a[i] == 0) {
            break;
        }
        if (check == false) {
            check = (a[i] == '-' ? true : false);
            if (check == true) {
                continue;
            }
        }

        if (a[i] == '.') {
            for (int j = i+1 ; j < sizeof(a); j++) {
                if (a[j] == -52 || a[j] == 0) {
                    break;
                }
                d = d * 10;
                d += int(a[j]) - 48;
            }
            break;
        }
        c = c * 10;
        c += int(a[i]) - 48;
    }
    int stepen = 1;
    double d2 = d;
    while (1 < d2) {
        stepen += 1;
        d2 /= 10;
    }

    d = d / pow(10, stepen-1);

    double b = c + d;
    b = (check == true ? -b : b);
    std::cout << b << "\n\n";
    */

    /*
    std::cout << "Give a number: ";
    double aa;
    std::cin >> aa;
    std::cout << "Give a power: ";
    int bb;
    std::cin >> bb;

    double qq = 0;
    while (bb > 1) {
        if (bb % 2 == 1) {
            qq = (qq == 0 ? aa : qq*aa);
            bb--;
        }
        bb /= 2;
        aa *= aa;
    }
    std::cout << (qq == 0 ? aa : qq * aa);*/


    /*
    std::cout << "Give a number: ";
    int n;
    std::cin >> n;
    std::cout << recurse(n); */


    /*
    std::cout << "Give a number: ";
    int h;
    std::cin >> h;
    dva(h);*/


    /*
    std::cout << "Whrite your words:\n";
    char aj[64];
    std::cin >> aj;
    colorprint(Color::GREEN, aj);
    colorprint(Fon::CYAN1, aj); */


    /*
    int u = 2;
    std::cout << ~(u << 30);*/


    std::cout << two(21342);
    return 0;
}
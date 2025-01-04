#include <iostream>

struct Person {
    char* name;
    unsigned int age;
};

void printperson(Person * p) {
    std::cout << "name is " << p->name << '\n';
    std::cout << "age is " << p->age << '\n';
}


struct drob {
    int a;
    unsigned b;
    drob(*sum)(drob a, drob b);
    drob(*dif)(drob a, drob b);
    drob(*mul)(drob a, drob b);
    drob(*div)(drob a, drob b);
    void(*pri)(drob c);
};
drob sum(drob a, drob b) {
    drob c;
    c.a = a.a * b.b + b.a * a.b;
    c.b = a.b * b.b;
    std::cout << "sum\t";
    return c;
}
drob diff(drob a, drob b) {
    drob c;
    c.a = a.a * b.b - b.a * a.b;
    c.b = a.b * b.b;
    std::cout << "diff\t";
    return c;
}
drob mult(drob a, drob b) {
    drob c;
    c.a = a.a * b.a;
    c.b = a.b * b.b;
    std::cout << "mult\t";
    return c;
}
drob div(drob a, drob b) {
    drob c;
    c.a = a.b * b.a;
    c.b = a.a * b.b;
    std::cout << "div\t";
    return c;
}
double todoooooooble(drob c) {
    return double(c.a) / c.b;
}
void print(drob c) {
    std::cout << c.a << '/' << c.b << '\n';
}
drob round(drob c) {
    int num = 1;
    for(int i = 2; i <= c.a && i <= c.b; i++) {
        if (((double(c.a) / i) == c.a / i) && ((double(c.b) / i) == c.b / i)) {
            num = i;
        }
    }
    c.a /= num;
    c.b /= num;
    return c;
}

int main()
{
    /*Person me;
    me.name = new char[20] { "sdadas" };
    me.age = 12;

    printperson(&me);

    delete[] me.name;*/


    drob a = { .a = 2, .b = 3 };
    drob b = { .a = 3, .b = 4 };
    std::cout << a.a << '/' << a.b << '\n';
    std::cout << b.a << '/' << b.b << '\n';
    print(sum(a, b));
    print(diff(a, b));
    print(mult(a, b));
    print(div(a, b));
    std::cout << todoooooooble(a) << '\n';
    std::cout << todoooooooble(b) << '\n';
    drob c = { .a = 30, .b = 5 , .sum = sum, .pri = print};
    c = c.sum(a, b);
    c = c.dif(a, b);
    c = c.mul(a, b);
    c = c.div(a, b);
    c.pri(c.sum(a, b));

    //std::cout << c.a << '/' << c.b << '\n';
    //print(round(c));
    return 0;
}
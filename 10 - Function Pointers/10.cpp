#include <iostream>
#include <cmath>
#include "Header.h"

int* intevsect(int* a, int arm, int* b, int barm) {
    int counter = 0;
    for (int i = 0; i < arm; i++) {
        for (int j = 0; j < barm; j++) {
            if (a[i] == b[j]) {
                counter++;
                break;
            }
        }
    }
    int* c = new int[counter + 1];
    c[0] = counter + 1;
    counter = 1;
    for (int i = 0; i < arm; i++) {
        for (int j = 0; j < barm; j++) {
            if (a[i] == b[j]) {
                c[counter] = a[i];
                counter++;
                break;
            }
        }
    }
    return c;
}



double f3(double x) {
    return 2 * pow(x, 2) - 4 * x + 10;
}
double derivative (double (*f)(double), double x, double h) {
    return (f(x + h) - f(x)) / h;
}



void fun(int arr[100000]) {
    for (int i = 0; i < 100000 - 1; i++) {
        for (int j = 0; j < 100000 - 1; j++) {
            int a = arr[j];
            int b = arr[j + 1];
            arr[j] = (a > b ? b : a);
            arr[j + 1] = (a < b ? b : a);
        }
        //std::cout << arr[i] << ' ';
    }
}
double measure(void(*f)(int*), int* arr) {
    double start = clock();
    f(arr);
    double end = clock();
    return (end - start) / 1000;
}

int main()
{
    /*int a[7] = {4, -7, 8, 0, 1, 2, 4};
    int b[12] = { 7, 0, 8, -1, -8, 6, 4, -5, -7, 6, 7, 0 };
    int* c = intevsect(a, 7, b, 12);
    for (int i = 1; i < c[0]; i++) {
        std::cout << c[i] << ' ';
    }
    std::cout << "\n\n";
    int* d = distinct(a, 7, b, 12);
    for (int i = 1; i < d[0]; i++) {
        std::cout << d[i] << ' ';
    }
    delete[] c, d;
    std::cout << "\n\n";


    double (*sinus)(double a) = sin;
    double (*logus)(double a) = log;
    double (*formulus)(double a) = f3;
    std::cout << derivative (sinus, 3.14, 0.001) << '\n';
    std::cout << derivative (logus, 4, 0.001) << '\n';
    std::cout << derivative (formulus, 1, 0.001) << '\n';*/



    int* arr = new int[100000];
    for (int i = 0; i < 100000; i++) {
        arr[i] = rand();
    }

    std::cout << measure(fun, arr);
    return 0;
}
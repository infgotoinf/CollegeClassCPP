#include <iostream>
#include <cmath>

int main()
{
    /*
    int x[2] = { 0, 9 };
    int y[2] = { 1, 5 };
    std::cout<<sqrt(pow((x[0]>x[1]?x[0]-x[1]:x[1]-x[0])*(x[0]>x[1]?x[0]-x[1]:x[1]-x[0]),2));
    
    int c[2] = { 7, 3 };
    int skalar = (y[0] - x[0])*(c[0] - x[0]) + (y[1] - x[1])*(c[1] - x[1]);
    std::cout << "\n\n" << skalar << '\n';

    double v1 = sqrt(abs(pow((x[0] - y[0]), 2)) + abs(pow((x[1] - y[1]), 2)));
    double v2 = sqrt(abs(pow((x[0] - c[0]), 2)) + abs(pow((x[1] - c[1]), 2)));
    double supr = (v1 * v2) / (v1 * v2);
    double alpha = acos(supr) * (180.0 / 3.14);
    std::cout << supr << "\n\n";
    double v3 = sqrt(abs(pow((y[0] - c[0]), 2)) + abs(pow((y[1] - c[1]), 2)));
    double p = (v1 + v2 + v3)/ 2;
    double S = sqrt(p*(p - v1)*(p - v2)*(p - v3));
    std::cout << S << '\n';
    */

    /*
    double aaa = 1;
    double bbb = 5;
    double ccc = 4;
    double D = bbb*bbb - 4 * aaa * ccc;
    double x1 = (-bbb + sqrt(D)) / (2 * aaa);
    double x2 = (-bbb - sqrt(D)) / (2 * aaa);
    std::cout << x1 << ' ' << x2 << '\n';
    std::cout << aaa * pow(x1, 2) + bbb * x1 + ccc << '\n';
    std::cout << aaa * pow(x2, 2) + bbb * x2 + ccc << '\n';
    */

    int arr[8] = { 7, 98, -23, 0, -9, 3, 14, -56 };
    int const min = -56;
    int const max = 98;
    int size = sizeof(arr) / sizeof(int);
    for (int i = 0; i < size; i++) {
        int cur = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[cur]) {
                cur = j;
            }
        }
        int temp = arr[cur];
        arr[cur] = arr[i];
        arr[i] = temp;
    }
    for (int c : arr) {
        std::cout << c << ' ';
    }

    std::cout << '\n';
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
    int arr2[max - min] = { 0 };
    for (int i = 0; i < size; i++) {
        arr2[arr[i] + min]++;
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < arr2[i]; j++) {
            arr[i] = i + j + min;
            i++;
        }
    }
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << ' ';
    }

    std::cout << '\n';
    int arr3[10] = { 0, 2, 2, 3, 6, 7, 7, 13, 15, 18 };
    int f = 13;
    int index = -1;
    int left = 0, right = 11;
    while (left != right) {
        int i = (left + right) / 2;

        if (arr3[i] == f) {
            index = i;
            break;
        }
        else if (arr3[i] > f) {
            right = i;
        }
        else {
            left = i;
        }
    }
    std::cout << arr3[index] << " with index " << index;
    return 0;
}
#include <iostream>

void fun(int *a) {
    *a = 4;
}

void minmax(int arr[], int* min, int* max) {
    for (int i = 1; i < 10; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        else if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main()
{
    int* a = new int;
    int a1 = 0;
    fun(a);
    fun(&a1);
    std::cout << *a << '\n';
    std::cout << a << '\n';
    std::cout << &a1 << '\n';
    std::cout << a1 << "\n\n";
    delete a, a1;


    int arr[10] = { 12, -56, 3, 0, 9, 45, 4, -7, -19, 7 };
    int* min = new int{ arr[0] };
    int* max = new int{ arr[0] };
    minmax(arr, min, max);
    std::cout << "minimum is " << *min << " maximum is " << *max << '\n';
    delete min, max;


    int** arrr2 = new int* [5];
    for (int i = 0; i < 5; i++) {
        arrr2[i] = new int[5];
    }
    int g = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            arrr2[i][j] = j+g;
            std::cout << arrr2[i][j] << ' ';
        }
        std::cout << '\n';
        g++;
    }

    for (int i = 0; i < 5; i++) {
        delete[] arrr2[i];
    }
    delete[] arrr2;
    return 0;
}
#include <iostream>

void splitter(char* str, char ch) {
    int counter = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == ch) {
            counter++;
        }
    }
    int* arr = new int[counter+2];
    int i2 = 0;
    counter = 1;
    arr[0] = 0;
    for (; i2 < strlen(str); i2++) {
        if (str[i2] == ch) {
            arr[counter] = i2;
            counter++;
        }
    }
    arr[counter] = i2;
    char** mass = new char*[counter-1];
    for (int i = 0; i < counter; i++) {
        int g = arr[i + 1] - arr[i] - 1;
        (i == 0 ? g++ : g = g);
        mass[i] = new char[g];
    }

    int l = 0;
    for (int i = 0; i < counter; i++) {
        int j = 0;
        int l2 = l;
        while (str[j+l2] != ch && (j + l2) <= strlen(str)) {
            mass[i][j] = str[l];
            std::cout << mass[i][j];
            j++;
            l++;
        }
        std::cout << '\n';
        l++;
    }
    for (int i = 0; i < counter - 1; i++) {
        delete[] mass[i];
    }
    delete[] mass;
}

//////////////////////////////////////////////////////////////////////

void replacer(char* str, char take[], char eat[]) {
    int len = strlen(take);
    int eln = strlen(eat);

    int caunt = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == take[0]) {
            int i2 = 1;
            for (; i2 < len; i2++) {
                if (str[i + 1] != take[i2]) {
                    break;
                }
            }
            if (i2 == len - 1 || len - 1 == 0) {
                caunt++;
            }
        }
    }
    int h = strlen(str) - len * caunt + eln * caunt;
    char* mass2 = new char[h];
    int j = 0;
    int b = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == take[0]) {
            int i2 = 1;
            for (; i2 < len; i2++) {
                //std::cout << i2 << '\n';
                if (str[i + i2] != take[i2]) {
                    //std::cout << "FALSE\n";
                    break;
                }
            }
            //std::cout << i2 << '\t' << len-1 << '\n';
            if (i2 == len || len - 1 == 0) {
                //std::cout << "TRUE\n";
                for (int a = 0; a < eln; a++) {
                    mass2[i + b + a] = eat[a];
                    std::cout << mass2[i + b + a];
                }
                i += len - 1;
                b += eln;
            }
            else {
                mass2[i + b] = str[i];
                std::cout << mass2[i + b];
            }
        }
        else {
            mass2[i + b] = str[i];
            std::cout << mass2[i + b];
        }
    }

}

int main()
{
    char str[64] = "ahahahah";
    //splitter(str, 'a');
    char take[32] = "aha";
    char eat[32] = "ehe";
    replacer(str, take, eat);
    return 0;
}

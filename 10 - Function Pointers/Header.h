#pragma once
int* distinct(int* a, int arm, int* b, int barm) {
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


    int counternew = 0;
    for (int j = 0; j < arm; j++) {
        bool kastil = 1;
        for (int i = 1; i < c[0]; i++) {
            if (c[i] == a[j]) {
                kastil = 0;
                break;
            }
        }
        if (kastil == 1) {
            counternew++;
        }
    }
    for (int j = 0; j < barm; j++) {
        bool kastil = 1;
        for (int i = 1; i < c[0]; i++) {
            if (c[i] == b[j]) {
                kastil = 0;
                break;
            }
        }
        if (kastil == 1) {
            counternew++;
        }
    }
    int* d = new int[counternew+1];
    d[0] = counternew + 1;
    counternew = 1;
    for (int j = 0; j < arm; j++) {
        bool kastil = 1;
        for (int i = 1; i < c[0]; i++) {
            if (c[i] == a[j]) {
                kastil = 0;
                break;
            }
        }
        if (kastil == 1) {
            d[counternew] = a[j];
            counternew++;
        }
    }
    for (int j = 0; j < barm; j++) {
        bool kastil = 1;
        for (int i = 1; i < c[0]; i++) {
            if (c[i] == b[j]) {
                kastil = 0;
                break;
            }
        }
        if (kastil == 1) {
            d[counternew] = b[j];
            counternew++;
        }
    }
    delete[] c;
    return d;
}
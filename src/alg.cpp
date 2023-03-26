// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (*(arr + i) + *(arr + j) == value) {
                search++;
            }
        }
    }
    return search;
}
int countPairs2(int* arr, int len, int value) {
    while (*(arr + (len - 1)) > value) len--;
    int search = 0;
    for (int i = 0; i < len; i++) {
        for (int j = len; j > i; j--) {
            if (*(arr + i) + *(arr + j) == value){
              search++;
            }
        }
    }
    return search;
}
int binerySearch(int* arr, int size, int value, int n) {
    int ror = size;
    int lol = n;
    int search = 0;
    while (lol < ror - 1) {
        int sror = (lol + ror) / 2;
        if (*(arr + n)  + *(arr + sror) == value) {
            search++;
            int i = 1;
            for (; *(arr + n) + *(arr + sror - i) == value && (sror - i) > lol; i++)
                search++;
            i = 1;
            for (; *(arr + n) + *(arr + sror + i) == value && (sror + i) < ror; i++)
                search++;
            break;
        }
        if (*(arr + n) + *(arr + sror) > value) {
            ror = sror;
        } else {
            lol = sror;
        }
    }
    return search;
}
int countPairs3(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
        search += binerySearch(arr, len, value, i);
    }
    return search;
}

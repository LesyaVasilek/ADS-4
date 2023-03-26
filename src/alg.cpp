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
            if (*(arr + i) + *(arr + j) == value) {
              search++;
            }
        }
    }
    return search;
}
int binerySearch(int* arr, int size, int value, int n) {
    int e = size;
    int l = n;
    int search = 0;
    while (l < e - 1) {
        int o = (l + e) / 2;
        if (*(arr + n)  + *(arr + o) == value) {
            search++;
            int i = 1;
            for (; *(arr + n) + *(arr + o - i) == value && (o - i) > l; i++)
                search++;
            i = 1;
            for (; *(arr + n) + *(arr + o + i) == value && (o + i) < e; i++)
                search++;
            break;
        }
        if (*(arr + n) + *(arr + o) > value) {
            e = o;
        } else {
            l = o;
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

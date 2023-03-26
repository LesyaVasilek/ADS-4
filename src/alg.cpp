// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int search = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                search++;
            }
        }
    }
    return search;
}
int countPairs2(int *arr, int len, int value) {
    int search = 0;
    int r = len - 1;
    int l = 0;
    while (l < r) {
        int sum = arr[l] + arr[r];
        if (sum == value) {
            search++;
            while (l < r && arr[l] == arr[l+1]) {
                l++;
            }
            while (l < r && arr[r] == arr[r-1]) {
                r--;
            }
            l++;
            r--;
        } else if (sum < value) {
            l++;
        } else {
            r--;
        }
    }
    return search;
}
int binarysearch(int *arr, int len, int value)
{
    int lol = 0;
    int ryka = len - 1;
    while (lol <= ryka)
    {
        int midble = lol + (ryka - lol) / 2;
        if (arr[midble] == value)
        {
            return midble;
        }
        else if (arr[midble] < value)
        {
            lol = midble + 1;
        }
        else
        {
            ryka = midble - 1;
        }
    }
    return -1;
}

int countPairs3(int *arr, int len, int value)
{
    int search = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int brain = value - arr[i];
        int idfcare = binarysearch(arr + i + 1, len - i - 1, brain);
        if (idfcare != -1)
        {
            search++;
        }
    }
    return search;
}

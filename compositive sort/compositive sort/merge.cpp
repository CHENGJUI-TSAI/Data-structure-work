#include "sorts.h"
#include <iostream>
#include <algorithm>
using namespace std;

void Merge(int initList[], int mergedList[], const int l, const int m, const int n) {
    int i1 = l, i2 = m + 1, iResult = l;
    while (i1 <= m && i2 <= n) {
        if (initList[i1] <= initList[i2])
            mergedList[iResult++] = initList[i1++];
        else
            mergedList[iResult++] = initList[i2++];
    }
    while (i1 <= m) mergedList[iResult++] = initList[i1++];
    while (i2 <= n) mergedList[iResult++] = initList[i2++];
}

void MergePass(int initList[], int resultList[], const int n, const int s) {
    int i;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);

    if (i + s - 1 <= n)
        Merge(initList, resultList, i, i + s - 1, n);
    else
        copy(initList + i, initList + n + 1, resultList + i);
}

void MergeSort(int arr[], int size) {
    int* tempList = new int[size + 1];
    for (int l = 1; l < size; l *= 2) {
        MergePass(arr, tempList, size, l);
        l *= 2;
        MergePass(tempList, arr, size, l);
    }
    delete[] tempList;
}

void mergeSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    
    int* a = new int[n + 1];
   
    for (int i = 1; i <= n; ++i) {
        a[i] = arr[i - 1];
    }
    
    MergeSort(a, n);
   
    for (int i = 1; i <= n; ++i) {
        arr[i - 1] = a[i];
    }
    delete[] a;
}
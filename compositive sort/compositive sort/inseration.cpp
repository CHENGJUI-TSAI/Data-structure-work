#include "sorts.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void Insert(int e, int* a, int i) {
    while (e < a[i]) {
        a[i + 1] = a[i];  
        i--;
    }
    a[i + 1] = e;  
}

void insertionSort(int arr[], int size) {
    for (int i = 2; i <= size; i++) {  
        Insert(arr[i], arr, i - 1);
    }
}

void insertionSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int* a = new int[n + 1];
    // copy to 1-based
    for (int i = 1; i <= n; ++i) {
        a[i] = arr[i - 1];
    }
    // call original
    insertionSort(a, n);
    // copy back
    for (int i = 1; i <= n; ++i) {
        arr[i - 1] = a[i];
    }
    delete[] a;
}
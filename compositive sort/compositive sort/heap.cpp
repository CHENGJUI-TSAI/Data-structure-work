#include "sorts.h"
#include <iostream>
using namespace std;

template <class T>
void Adjust(T* a, const int root, const int n) {
    T e = a[root];
    int j;


    for (j = 2 * root; j <= n; j *= 2) {
        if (j < n && a[j] < a[j + 1]) j++;
        if (e >= a[j]) break;
        a[j / 2] = a[j];
    }
    a[j / 2] = e;
}

template <class T>
void HeapSort(T* a, const int n) {

    for (int i = n / 2; i >= 1; i--)
        Adjust(a, i, n);


    for (int i = n - 1; i >= 1; i--) {
        swap(a[1], a[i + 1]);
        Adjust(a, 1, i);
    }
}

void heapSort(vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    // 建 1-based C 陣列
    int* a = new int[n + 1];
    for (int i = 1; i <= n; ++i) {
        a[i] = arr[i - 1];
    }
    // 呼叫原版
    HeapSort(a, n);
    // 把結果搬回 vector
    for (int i = 1; i <= n; ++i) {
        arr[i - 1] = a[i];
    }
    delete[] a;
}

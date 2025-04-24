#include "sorts.h"
#include <iostream>
#include <algorithm>
using namespace std;

void quicksort(int* a, int left, int right) {
    if (left < right) {
        int i = left, j = right, pivot = a[left];
        do {
            do j--; while (i < j && a[j] >= pivot);
            do i++; while (i < j && a[i] <= pivot);
            if (i < j) swap(a[i], a[j]);
        } while (i < j);
        swap(a[left], a[j]);

        quicksort(a, left, j - 1);
        quicksort(a, j + 1, right);
    }
}

void quickSort(vector<int>& arr, int left, int right) {
    // 左右邊界如果 caller 傳 -1 或超出，就改成合法範圍
    int n = static_cast<int>(arr.size());
    if (left < 0)          left = 0;
    if (right >= n)        right = n - 1;

    // 呼叫你原本的那支函式
    quicksort(arr.data(), left, right);
}
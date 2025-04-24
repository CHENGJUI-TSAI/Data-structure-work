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
    // ���k��ɦp�G caller �� -1 �ζW�X�A�N�令�X�k�d��
    int n = static_cast<int>(arr.size());
    if (left < 0)          left = 0;
    if (right >= n)        right = n - 1;

    // �I�s�A�쥻������禡
    quicksort(arr.data(), left, right);
}
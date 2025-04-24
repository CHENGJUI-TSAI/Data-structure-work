#pragma once
// sorts.h
#pragma once
#include <vector>
using std::vector;

void insertionSort(vector<int>& arr);
void quickSort(vector<int>& arr, int left, int right);
void mergeSort(vector<int>& arr);
void heapSort(vector<int>&);

bool isNearlySorted(const vector<int>& arr);
void compositeSort(vector<int>& arr);

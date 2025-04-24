// main.cpp
#include "sorts.h"            // �A���Ƨ� wrapper �ŧi
#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>
#include <numeric>
using namespace std;
using Clock = chrono::high_resolution_clock;

// ����洫�p�ƾ�
static size_t swapCount = 0;

// �� swap �]�� macro�A�C�� swap �N ++swapCount
#define COUNTED_SWAP(x,y) do { std::swap((x),(y)); ++swapCount; } while(0)

// �H�U�T�Ӥu��禡�򤧫e�@��
long long averageTime(const vector<long long>& t) {
    return accumulate(t.begin(), t.end(), 0LL) / t.size();
}
long long worstTime(const vector<long long>& t) {
    return *max_element(t.begin(), t.end());
}
size_t    hiCount(const vector<size_t>& c) {
    return *max_element(c.begin(), c.end());
}

int main() {
    // �n���ժ����P N
    vector<int> testSizes = { 500, 1000, 2000, 3000, 4000, 5000 };
    const int loop = 10;  // �C�� N �]�X��

    // �ü� generator
    mt19937_64 rng{ random_device{}() };
    uniform_int_distribution<int> dist(0, 1'000'000);

    // �v�@��C�� N �� benchmark
    for (int N : testSizes) {
        // �ɶ��P�洫���Ƴ��U�@�� vector
        vector<long long> timeHeap, timeBubble, timeInsert, timeMerge, timeQuick, timeSTL;
        vector<size_t>    cntHeap, cntBubble, cntInsert, cntMerge, cntQuick, cntSTL;

        for (int r = 0; r < loop; ++r) {
            // ���ͤ@�� base ���
            vector<int> base(N);
            for (int i = 0; i < N; ++i) base[i] = dist(rng);

            // ---- Heap Sort ----
            swapCount = 0;
            {
                auto data = base;
                auto t0 = Clock::now();
                heapSort(data);
                auto t1 = Clock::now();
                timeHeap.push_back(chrono::duration_cast<chrono::microseconds>(t1 - t0).count());
                cntHeap.push_back(swapCount);
            }

           

            // ---- Insertion Sort ----
            swapCount = 0;
            {
                auto data = base;
                auto t0 = Clock::now();
                insertionSort(data);
                auto t1 = Clock::now();
                timeInsert.push_back(chrono::duration_cast<chrono::microseconds>(t1 - t0).count());
                cntInsert.push_back(swapCount);
            }

            // ---- Merge Sort ----
            swapCount = 0;
            {
                auto data = base;
                auto t0 = Clock::now();
                mergeSort(data);
                auto t1 = Clock::now();
                timeMerge.push_back(chrono::duration_cast<chrono::microseconds>(t1 - t0).count());
                cntMerge.push_back(swapCount);
            }

            // ---- Quick Sort ----
            swapCount = 0;
            {
                auto data = base;
                auto t0 = Clock::now();
                quickSort(data, 0, static_cast<int>(data.size()) - 1);
                auto t1 = Clock::now();
                timeQuick.push_back(chrono::duration_cast<chrono::microseconds>(t1 - t0).count());
                cntQuick.push_back(swapCount);
            }

            // ---- STL Sort ----
            swapCount = 0;
            {
                auto data = base;
                auto t0 = Clock::now();
                sort(data.begin(), data.end());
                auto t1 = Clock::now();
                timeSTL.push_back(chrono::duration_cast<chrono::microseconds>(t1 - t0).count());
                cntSTL.push_back(swapCount);
            }
        }

        // �L�X���G (�ɶ��� �gs�A�]�i�H�A�� 1000 �ন ms)
        cout << "---- Sorting Time Summary (�gs) ----" << endl;
        cout << "Info : testCase = " << testSizes.size()
            << ", testRange = " << N
            << ", Loop = " << loop
            << endl;

        cout << "Heap Sort:      Avg = " << averageTime(timeHeap)
            << ", Max = " << worstTime(timeHeap)
            << ", SwapCountHighest = " << hiCount(cntHeap)
            << endl;

       

        cout << "Insertion Sort: Avg = " << averageTime(timeInsert)
            << ", Max = " << worstTime(timeInsert)
            << ", SwapCountHighest = " << hiCount(cntInsert)
            << endl;

        cout << "Merge Sort:     Avg = " << averageTime(timeMerge)
            << ", Max = " << worstTime(timeMerge)
            << ", SwapCountHighest = " << hiCount(cntMerge)
            << endl;

        cout << "Quick Sort:     Avg = " << averageTime(timeQuick)
            << ", Max = " << worstTime(timeQuick)
            << ", SwapCountHighest = " << hiCount(cntQuick)
            << endl;

        cout << "STL Sort:       Avg = " << averageTime(timeSTL)
            << ", Max = " << worstTime(timeSTL)
            << ", SwapCountHighest = " << hiCount(cntSTL)
            << endl;

        cout << endl;
    }

    return 0;
}

#pragma once

#include <vector>
#include <initializer_list>
#include <string>
using namespace std;

class Sort {
private:
    vector<int> elements;

public:
    Sort(int numElements, int min, int max);          // random
    Sort(initializer_list<int> list);                 // initialization list
    Sort(const vector<int>& vec, int numElements);    // existing vector
    Sort(const char* numbers);                        // string
    Sort(int count, ...);                             // parameters

    void InsertSort(bool ascendent = false);

    void QuickSortHelp(int p, int q, bool asc);
    int Partition(int p, int q, bool asc);
    void QuickSort(bool ascendent = false);

    void BubbleSort(bool ascendent = false);

    void Print();
    int GetElementsCount();
    int GetElementFromIndex(int index);
};


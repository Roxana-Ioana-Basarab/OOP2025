#include "Sort.h"
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <cstdarg>


using namespace std;

// 1
Sort::Sort(int numElements, int min, int max) {
    elements.reserve(numElements);
    srand(time(nullptr));
    for (int i = 0; i < numElements; i++) {
        elements.push_back(rand() % (max - min + 1) + min);
    }
}

// 2
Sort::Sort(initializer_list<int> list) {
    elements.reserve(list.size());
    elements.assign(list);
}

// 3
Sort::Sort(const vector<int>& vec, int numElements) {
    elements.reserve(numElements);
    elements.assign(vec.begin(), vec.begin() + numElements);
}

//4
Sort::Sort(const char* numbers) {
        int cnt = 0;
        for (int i = 0; i < strlen(numbers); i++)
            if (numbers[i] == ',')
                cnt++; //#comma

        elements.reserve(cnt+1); //memory
        
        int nr = 0;
        for (int i = 0; i < strlen(numbers); i++)
        {
            if (numbers[i] == ',')//end of a number
            {
                elements.push_back(nr); 
                nr = 0;
            }
            else //creating number
            {
                nr = nr * 10 + (numbers[i] - '0');
            }

        }
        elements.push_back(nr); //last number
}

// 5
Sort::Sort(int count, ...) {
    elements.reserve(count);
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++) {
        elements.push_back(va_arg(args, int));
    }
    va_end(args);
}

void Sort::InsertSort(bool ascendent)
{
    int n = (int)elements.size();
    for (int i = 1;i < n;i++) {
        int temp = elements[i];
        int j = i - 1;
        while (j >= 0 && (ascendent ? elements[j] > temp : elements[j] < temp)) {
            elements[j + 1] = elements[j];
            j--;
        }
        if (elements[j + 1] != temp)
            elements[j + 1] = temp;
    }
}

int Sort::Partition(int p, int q, bool asc)
{
    int k = elements[q];
    int i = p - 1;
    for (int j = p;j < q;j++) {
        if (asc ? elements[j]<k : elements[j] > k) {
            swap(elements[++i], elements[j]);
        }
    }
    swap(elements[i + 1], elements[q]);
    return i + 1;
    
}

void Sort::QuickSortHelp(int p, int q, bool asc)
{
    if (p < q) {
        int k1 = Partition(p, q, asc);
        QuickSortHelp(p, k1 - 1,asc);
        QuickSortHelp(k1 + 1, q,asc);
    }
}


void Sort::QuickSort(bool ascendent)
{
    int p = 0, q = (int)elements.size()-1;
    QuickSortHelp(p, q, ascendent);
}


void Sort::BubbleSort(bool ascendent)
{
    int n = (int)elements.size();
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (ascendent ? elements[j] > elements[i] : elements[i] > elements[j])
                swap(elements[i],elements[j]);
}


void Sort::Print() {
    for (int num = 0;num < (int)elements.size(); num++) {
        printf ("%d ",elements[num]);
    }
    printf("\n");
}

int Sort::GetElementsCount() {
    return elements.size();
}


int Sort::GetElementFromIndex(int index) {
    if (index >= 0 && index < (int)elements.size()) {
        return elements[index];
    }
    return -1;
}
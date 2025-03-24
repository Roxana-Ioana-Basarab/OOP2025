#include "Sort.h"
#include <stdio.h>
#include <vector>

using namespace std;

int main() {

    printf("S1: \n");

    Sort s1(7, 20, 100); //1.
    s1.Print();
    s1.BubbleSort(true);
    s1.Print();

    printf("\nS2: \n");

    Sort s2 = {4, 9, 3, 7, 2}; //2. 
    s2.Print();
    s2.InsertSort(false);
    s2.Print();

    printf("\nS3: \n");

    vector<int> arr = {50, 30, 20, 10, 40}; //3.
    Sort s3(arr, 5);
    s3.Print();
    s3.QuickSort(true);
    s3.Print();

    printf("\nS4: \n");
    Sort s4("12,45,2,56,7,23");
    s4.Print();
    
    printf("\nS5: \n");
    Sort s5(8, 25, 13, 17, 45, 89, 56, 23, 10);
    s5.Print();

	return 0;
}
#include <iostream>

void insertionSortSolution(){

    int A[] = {3, 40, 32, 19, 54, 23, 7, 8};
    int n = sizeof(A) / sizeof(A[0]);

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j++){
            if(A[j-1] > A[j]){
                int temp = A[j];

                A[j] = A[j-1];
                A[j-1] = temp;
            }
        }
    }

}
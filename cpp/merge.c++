#include <iostream>



// A[p ~ q] / A[q+1 ~ r]
void merge(int A[], int p, int q, int r){

    // 왼, 오 요소개수(배열 사이즈)
    int left = q - p + 1;
    int right = r - q;

    // 왼, 오 임시배열
    int* L = new int[left];
    int* R = new int[right];

    // 왼, 오 임시배열에 있는 값이 실제 A에 들어갈때의 위치 정렬
    for(int i = 0; i < left; i++) L[i] = A[p + i];
    for(int j = 0; j < right; j++) R[j] = A[(q+1) + j];

    int i = 0, j = 0, k = p; // 각각 L,R,A배열의 현재 위치

    // 두 배열이 다 정렬된 상태이니 이걸 다시 A에 넣어야함.
    while(i < left && j < right){
        if(L[i] <= R[j]){
            A[k++] = L[i++];

        }
        else{
            A[k++] = R[j++];
        }
    }
    // 다 정렬하고 원소 1개뿐이면 그냥k에 넣기
    // (어느쪽이 남을지 모르니까 둘 다 써놓은 것. 실제로는 둘 중 하나만 실행됨)
    while(i < left){ // 왼쪽이 남은경우
        A[k++] = L[i++];
    }
    while(j < right){ // 오른쪽이 남은경우
        A[k++] = R[j++];
    }

    delete[] L;
    delete[] R;
}

// 배열을 쪼개는 재귀호출방식 (if(p >= r) return;을 만족할때까지)
void mergeSort(int A[], int p, int r){

    if(p >= r) return; // 원소가 1개일 경우는 이미 정렬상태임.
    
    int q = (p+r)/2;

    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A, p, q, r);
}
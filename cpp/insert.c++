#include <iostream>

using namespace std;

void insertionSortSolution(int A[], int n){

    for(int i = 1; i < n; i++){
        for(int j = i; j > 0; j--){
            
            if(A[j-1] > A[j]){ // A[0]의 값이 A[1]의 값보다 크면 : (40, 3) -> (3, 40)이 되어야함 즉, 
                int temp = A[j];

                A[j] = A[j-1]; // A[1]의 값이 앞으로 정렬되어야하므로 A[0]의 값이 뒤로 가야함.(둘이 숫자 교체)
                A[j-1] = temp; // 교체된 값은 임시배열변수 temp로 간다.
            }
        }
    }

}

int main(){

    int n;
    cout << "Enter count: ";
    cin >> n; // 배열 사이즈 입력

    int A[n];
    cout << "Enter numbers: ";
    for(int i = 0; i < n; i++){
        cin >> A[i];
    } // 배열에 들어갈 랜덤 값 입력

    insertionSortSolution(A, n);

    cout << "\nResult: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }

    return 0;
}
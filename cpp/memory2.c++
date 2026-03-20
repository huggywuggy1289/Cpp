#include <iostream>

using namespace std;

int main(){

    int* pointer = new int; // new연산자가 int(4바이트) 크기만큼 할당가능한 메모리 영역을 찾은뒤, 그 영역의 첫번째 주소를 가리킨다.

    double* p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.13;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << ".\n";
    p3 = p3 + 1; // 포인터를(주소를) 증가시킨다

    cout << "Now p3[0] is " << p3[0] << " and ";
    cout << "p3[1] is " << p3[1] << ".\n";

    p3 = p3 - 1; //포인터를(주소를) 감소시킨다. delete[]를 할 때는 반드시 new로 처음 할당받았던 그 시작 주소를 줘야한다.
    delete[] p3;

    return 0;
}
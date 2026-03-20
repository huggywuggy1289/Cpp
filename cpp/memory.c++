#include <iostream>

using namespace std;

int main(){

    // int val = 3;
    // cout << &val << endl; // & : 해당 변수의 값이 저장된 주소를 출력 해줌

    // // 객체 지향 프로그래밍 특징 : 배열의 크기를 미리 정하지않고 실행시간에 결정함
    // // 포인터는 메모리의 주솟값을 가리킨다. 즉, 포인터의 이름이 주소를 나타낸다.

    // int* a;
    // int* b;
    // int* c, d; //c는 포인터 변수, d는 일반적인 int형 변수가 된다.

    int one = 6;
    int* two;

    two = &one; //포인터는 one변수의 주솟값을 가리킨다.

    cout << "one의 값: " << one << endl;
    // 가리키는 실제 값을 출력하려면 *two
    cout << "*two가 가리키는 값: " << *two << endl; 

    cout << "one의 주소: " << &one << endl;
    // 주소값 그 자체를 출력하려면 two
    cout << "two에 저장된 주소: " << two << endl;

    *two = *two + 1; // one의 값을 1 증가시킴

    cout << "이제 one의 값은: " << one << endl;

    return 0;

    // one의 값: 6
    // *two가 가리키는 값: 6
    // one의 주소: 0x61ff08
    // two에 저장된 주소: 0x61ff08
    // 이제 one의 값은: 7

    // 즉 포인터변수는 주소자체를 가리키고, *two는 그 주소안에 값을 가리킨다

}
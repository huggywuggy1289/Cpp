#include <iostream>

using namespace std;

int main(){
    // 원의 넓이를 구하는 프로그램

    int r;

    cout << "반지름을 입력하세요";
    cin >> r;

    if(r < 0){
        return -1;
    }

    const double PI = 3.1415926535; // #define PIE 3.1415926535
    float s = r * r * PI; // 상수(바뀔필요가 없으며, 바뀌어서는 안되는 수)

    cout << "원의 넓이: " << s << endl;

    return 0;

}

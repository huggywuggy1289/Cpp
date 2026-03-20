#include <iostream>
#include <string>

using namespace std;

struct Mystruct{

    string name;
    int age;
    float height;
    float weight;

} A;

int main(){

    Mystruct a{"재윤", 23, 168.0, 60.0}; // 구조체 사용할 변수 선언
    
    cout << a.name << endl;
    cout << a.age << endl;
    cout << a.height << endl;
    cout << a. weight << endl; // 이렇게 해도되고

    A.name = "재윤";
    A.age = 23;
    A.height = 168.0;
    A.weight = 60;
    cout << A.name << endl;
    // 이렇게 해도 되는거지?

    return 0;
}
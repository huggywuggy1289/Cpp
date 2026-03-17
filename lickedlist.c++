#include <bits/stdc++.h>
using namespace std;
int main(){
    list<int> a; // 정수형 연결 리스트 'a'를 생성
    for (int = i; i < 10; i++)a.push_back(i); // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    for (int = i; i < 10; i++)a.push_front(i); // {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, ...}

    auto it = a.begin(); // 리스트의 첫 번째 원소를 가리키는 반복자 생성 여기서는 9
    it++; // 한칸 뒤로 이동하면 9보다 뒤인 8의 앞
    a.insert(it, 1000); // 9와 8사이 1000 삽입


    for(auto it : a) cout << it << " ";
    cout << '\n';

    a.pop_front();
    a.pop_back();

    for (auto it : a) cout << it << " ";
    return 0;
}
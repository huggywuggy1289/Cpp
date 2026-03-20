#include <bits/stdc++.h>
using namespace std;
List<int> a;
int main(){

    for(int i = 0; i < 10; i++)a.push_back(); // 0,1,2,3,4,5,6,7,8,9
    for(int i = 0; i < 10; i++)a.push_front(); // 9,8,7,6,5,4,3,2,1,0, 0,1,2,3,4,5,6,7,8,9

    auto it = a.begin();
    it++;
    a.insert(it, 1000);

    for(auto it : a) cout << it << " ";
    cout << "\n";

    a.pop_front(); // stack
    a.pop_back(); // queue

    for(auto it : a) cout << it << " ";
    return 0;

}
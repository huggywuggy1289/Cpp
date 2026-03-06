#include <bits/stdc++.h>
using namespace std;
int a[10];
int main(){
    for(int i = 0; i < 10; i++)a[i] = i;
    for(auto it : a) cout << it << " "; // auto: 리스트 a에 들어있는 데이터가 int인지 string인지 알아서 판단
    cout << "\n";
    return 0;
}
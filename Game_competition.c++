#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;

    // n이 항상 짝수라고 가정하며 a와 b의 참가자 번호가 n 이하인 자연수일때
    while(n % 2 == 0 && a <=n && b <= n){
        
        //  토너먼트에서 다음 라운드로 넘어갈때 어차피 번호가 1번부터 다시 부여받기 때문에  누가 이기는지는 고려할 대상이 아니라는 것
        // a : 8 -> 4 -> 2 -> 1
        // b : 9 -> 5 -> 3 -> 2
        // 일때  n/2 + n%2라는 것을 알 수 있음.
        while(a != b){
            a = a/2 + a%2;
            b = b/2 + b%2;
        }
        answer++;
    }
    cout << answer << endl;

    return answer;
}
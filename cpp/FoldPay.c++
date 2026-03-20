#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
// 지폐를 접을 때는 항상 길이가 긴 쪽을 반으로 접습니다.
// 접기 전 길이가 홀수였다면 접은 후 소수점 이하는 버립니다.
// 접힌 지폐를 그대로 또는 90도 돌려서 지갑에 넣을 수 있다면 그만 접습니다.
    while (!((bill[0] <= wallet[0] && bill[1] <= wallet[1]) || (bill[1] <= wallet[0] && bill[0] <= wallet[1]))) { // 지갑에 들어갈 수 있는 상태가 아닐때

        if(bill[0] > bill[1]){ // 가로가 세로보다 길때
            bill[0] /= 2; // bill[0]을 2로 나누고 나머지는 버립니다.
        }
        else if(bill[1] > bill[0]){ // 세로가 가로보다 길때 
            bill[1] /= 2; // bill[1]을 2로 나누고 나머지는 버립니다.
        }
       answer++;
    }
    return answer;
    }
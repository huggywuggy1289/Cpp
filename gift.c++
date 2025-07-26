#include <string>
#include <vector>
#include <string>
#include <vector>
#include <map>
#include <algorithm>  

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    map<string, map<string, int>> giftRecord; // 누가 누구한테 몇번 줬는지 저장하는 2차원 배열
    map<string, int> giftGiven, giftReceived;
    map<string, int> nextMonthGifts; // 다음달에 받을 돈

    // 선물 기록 누적(초기화는 한달 이후)
    for(string gift : gifts){
        int space = gift.find(' ');
        string giver = gift.substr(0,space);
        string receiver = gift.substr(space + 1);

        giftRecord[giver][receiver]++;
        giftGiven[giver]++;
        giftReceived[receiver]++;
    }

    // 선물 지수 계산
    map<string, int> giftScore;
    for (string name : friends) {
        //  자신이 친구들에게 준 선물의 수에서 받은 선물의 수를 뺀 값
        giftScore[name] = giftGiven[name] - giftReceived[name];
    }

    for(int i = 0; i < friends.size(); i++){
        for(int j = i+1; j < friends.size(); j++){
            string a = friends[i]; // i번째에 있는 a
            string b = friends[j]; // j번째에 있는 i

            int a1 = giftRecord[a][b];
            int b1 = giftRecord[b][a];

            if(a1 > b1){ // a가 준 선물이 더 많다면
                nextMonthGifts[a]++;
            }
            else if(a1 < b1){ // b가 준 선물이 더 많다면
                nextMonthGifts[b]++;
            }
            else{
                // 없거나 같다면 선물 지수 비교
                // 같다면 선물 지수 비교
                if (giftScore[a] > giftScore[b]) {
                    nextMonthGifts[a]++;
                } else if (giftScore[b] > giftScore[a]) {
                    nextMonthGifts[b]++;
                }
            }
        }
    }
    // 이 문제의 목적 : 누가 다음달에 가장 많이 받을지 선물 수 계산
    // 이때 auto는 타입을 컴파일러가 자동으로 추론하는 형태
    // & = 참조를 의미
    for(auto& p : nextMonthGifts){
        answer += max(answer, p.second); // <key, value>중 2번째 값
    }
    return answer;
}
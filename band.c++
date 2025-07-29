#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;

    int t = bandage[0]; // 기술의 시전시간
    int x = bandage[1]; // 1초당 회복량
    int y = bandage[2]; // 추가 회복량

    int hp = health; // 현재 체력
    int time = 1;           // 현재 시간 1초부터 시작
    int success_t = 0;    // 연속 성공 시간
    int attack_count = 0; // 몬스터 공격 횟수

    while(time <= attacks.back()[0]){ // 공격시간을 뒤로 감으며
        int attack_time = attacks[attack_count][0];

        // 공격감지
        if(time == attack_time){
            int damage = attacks[attack_count][1];
            hp = hp - damage;

            // 죽었음
            if (hp <= 0){
                return -1;
            }
            
            success_t = 0 ; // 붕대감기 실패로 초기화
            attack_count++;
        }

        else {
            // 공격 시간과 피해량
            success_t++;
            x++;

            if(success_t == bandage[0]){  // 연속 시전시간이 t시간과 같아지면
                hp = min(hp + bandage[2], health); // 최댓값제한 걸기
                y++;
                success_t = 0;
            }
        }
        time++;
    }
    return answer;
}
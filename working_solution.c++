#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int n = schedules.size(); // 직원이 중복없이 모두 담긴 정수배열의 사이즈가 곧 n의 사이즈

    // 직원 n명을 돌면서
    for(int i = 0; i <= n-1; i++){
        
        int latest_hour = schedules[i] / 100; // 인정되는 최대 시각
        int latest_min = schedules[i] % 100 + 10;
        if (latest_min >= 60) {
            latest_hour += 1;
            latest_min -= 60;
        }
        int latest_time = latest_hour * 100 + latest_min;
        
        bool on_time = true; // 지각여부 따지는 변수
        int days_checked = 0; // 평일 여부 따지는 변수

        for(int j = 0; days_checked< 5 && j <= 6; j++){
            // 1은 월요일, 2는 화요일, 3은 수요일, 4는 목요일, 5는 금요일, 6은 토요일, 7은 일요일에 이벤트를 시작했음을 의미한다.
            int day_of_week = (startday + j - 1) % 7 + 1; // 일반항

            // 토,일이 될 수 있는 인덱스조합 제외
            if (day_of_week == 6 || day_of_week == 7) continue;

            int actual_time = timelogs[i][j];

            if(actual_time > latest_time){ // 실제 시각이 인정되는 최대시각보다 값이 크다면
                on_time = false;
                break;
            }
            days_checked++;
        }
        if(on_time) ++answer;
    }

    return answer;
}
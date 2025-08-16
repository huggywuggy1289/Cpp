#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// targets_rows는 2차원 배열 targets의 행 길이, targets_cols는 2차원 배열 targets의 열 길이입니다.
int solution(vector<vector<int>> targets) {
    int answer = 0;
    int s,e = 0;

    // 오름차순 정렬[s,e]이므로
    sort(targets.begin(), targets.end());

    // 모든 폭격마사일을 요격하는 b의 요격미사일 수의 최솟값 구하기
    for(int i = 0; i<targets.size(); ++i){
        
        answer++;
        int last = targets[0][1];

        for(int i = 0; i < targets.size(); ++i){
            // !s < e
            if(targets[i][0] > last){
                ++answer, --i;
                break;
            }
            last = min(last, targets[i][1]);
        }
    }
    return answer;
}
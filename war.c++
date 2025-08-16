#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <vector>
#include <algorithm>

using namespace std;

// targets_rows는 2차원 배열 targets의 행 길이, targets_cols는 2차원 배열 targets의 열 길이입니다.
int solution(vector<vector<int>> targets) {
    int answer = 0;
    // 오름차순 정렬[s,e]이므로
    sort(targets.begin(), targets.end());
    answer++;

    // 모든 폭격마사일을 요격하는 b의 요격미사일 수의 최솟값 구하기
    for(int i = 0; i<targets.size(); ++i){
        
        int last = targets[i][1];

        // i가 연속으로 이어짐
        for(; i < targets.size(); ++i){
            // !s < e
            if(targets[i][0] >= last){
                ++answer; --i; // 인덱스 한칸 뒤로
                break;
            }
            last = min(last, targets[i][1]);
        }
    }
    return answer;
}
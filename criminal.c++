#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INF 1000000000

// info_rows: 물건 개수, info_cols: 2 (A흔적, B흔적)
int solution(int** info, size_t info_rows, size_t info_cols, int n, int m) {

    int* dp = (int*)malloc(sizeof(int) * m);
    for (int b = 0; b < m; ++b) dp[b] = INF;
    dp[0] = 0;
    
    for (size_t i = 0; i < info_rows; ++i) {
        int a = info[i][0]; // A 흔적
        int b = info[i][1]; // B 흔적

        int* ndp = (int*)malloc(sizeof(int) * m);
        for (int j = 0; j < m; ++j) ndp[j] = INF;

        for (int curB = 0; curB < m; ++curB) {
            if (dp[curB] == INF) continue;

            // A가 훔친다: A 흔적 증가, B 그대로
            int newA = dp[curB] + a;
            if (newA < n) { // n이상이면 안됨
                if (ndp[curB] > newA) ndp[curB] = newA;
            }

            // B가 훔친다: B 흔적 증가, A 그대로
            int newB = curB + b;
            if (newB < m) {
                if (ndp[newB] > dp[curB]) ndp[newB] = dp[curB];
            }
        }

        free(dp);
        dp = ndp;
    }

    int answer = INF;
    for (int b = 0; b < m; ++b) {
        if (dp[b] < answer) answer = dp[b];
    }
    free(dp);

    return (answer == INF) ? -1 : answer;
}

#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = -1;
    int maxSize;
    int n = park.size();
    int m = park[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));	// dp 테이블 생성
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (park[i][j] == "-1") {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                }
                else {
                    dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                }
                maxSize = max(maxSize, dp[i][j]);	// 최댓값 갱신
            }
        }
    }
    
    sort(mats.rbegin(), mats.rend());
    for (int mat : mats) {
        if (mat <= maxSize) {
            answer = mat;
            break;
        }
    }
    return answer;
}
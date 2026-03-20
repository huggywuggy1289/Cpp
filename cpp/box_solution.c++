#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int w, int target) {
    vector<int> jumps;

    // 열별 점프 크기 계산 후 역순 정렬
    for (int i = 1; i <= w * 2; i += 2) {
        jumps.push_back(i);
    }
    sort(jumps.rbegin(), jumps.rend());

    int count = 0;
    int current = target;

    while (current <= n) {
        int col = (current % w == 0) ? w : current % w;
        current += jumps[col - 1];
        count++;
    }

    return count;
}

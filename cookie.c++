#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int D, vector<int> cakes){ // 닌자맛 쿠키와 장애물 사이의 거리가 D칸
    int total_throws = 0; // 총 던진 표창의 횟수(표창 1개당 각 층의 타격을 입긴함)
    int n = cakes.size(); // cakes[i]에 쌓인 케이크 개수를 의미

    for(int i = 0; i < n; i++){
        // 내 앞의 장애물들이 나보다 낮아야 내 층이 깎이므로, 지금까지 중 최대 높이 계산해야함.
        total_throws = max(total_throws, cakes[i]);

        // 1칸 이동을 위해서는 표창한번던져서 cakes[i]=0으로 만들어야함.
        // 따라서 표창을 한번 던졌는데 i번째 케이크가 아직 남아있다면 전진실패
        // i번째 장애물 칸에 닌자가 발을 들여놓는 순간, 닌자는 이미 D + i번의 전진을 한 상태
        // 전진 횟수와 표창 투척 횟수가 1:1로 매칭되므로, 닌자가 D + i 번 전진했다면? -> 표창도 딱 D + i 번 던졌다는 뜻
        // 따라서 필요한 표창 투척 횟수는 예를 들어 5번인데 
        // 그칸에 도착할때까지 총 던진 표창 횟수가 4개면 전진불가임.
        if(total_throws > D+i){
            return -1;
        }
    }

    return max(total_throws, n);
}

int main() {
    // 1. 기본 예시 테스트
    cout << "--- Basic Examples ---" << endl;
    cout << "Test 1 (D=2, [1,2,2]): " << solution(2, {1, 2, 2}) << " (Exp: 3)" << endl;
    cout << "Test 2 (D=1, [2,2,3]): " << solution(1, {2, 2, 3}) << " (Exp: -1)" << endl;

    // 2. 경계값 테스트 (장애물 높이가 1인 경우, 거리가 0인 경우 등)
    cout << "\n--- Boundary Tests ---" << endl;
    cout << "Test 3 (D=10, [1]): " << solution(10, {1}) << " (Exp: 1)" << endl;
    cout << "Test 4 (D=0, [1]): " << solution(0, {1}) << " (Exp: 1)" << endl;
    cout << "Test 5 (D=0, [2]): " << solution(0, {2}) << " (Exp: -1)" << endl;

    // 3. 대량 데이터 및 랜덤 케이스 (약 45개 생성)
    cout << "\n--- Random & Large Tests ---" << endl;
    for (int t = 6; t <= 50; t++) {
        int random_D = rand() % 10 + 1; // 1~10 사이의 거리
        int size = rand() % 5 + 3;      // 3~7 사이의 장애물 개수
        vector<int> random_cakes;
        
        for(int j=0; j<size; j++) {
            random_cakes.push_back(rand() % 10 + 1); // 1~10 사이의 높이
        }

        int result = solution(random_D, random_cakes);
        
        cout << "Test " << t << " (D=" << random_D << ", cakes=[";
        for(int k=0; k<random_cakes.size(); k++) cout << random_cakes[k] << (k==random_cakes.size()-1 ? "" : ",");
        cout << "]) -> Result: " << result << endl;
    }

    return 0;
}
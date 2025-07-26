#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    
    int n = dice.size();
    int k = n / 2;

    vector<int> comb(n, 0);
    fill(comb.begin(), comb.begin() + k, 1); // A가 고를 주사위 표시
    int max_win = -1;

    do {
        vector<int> a, b;
        for (int i = 0; i < n; i++) {
            if (comb[i] == 1){
                a.push_back(i);
            }
            else {
                b.push_back(i);
            }
        // a의 주사위들을 굴려서 나올수 있는 모든 경우의 수
        vector<int> a_sum = {0}; // 해당 값은 반복될수록 여러개 쌓일 수 있다.
        for (int index : a) { // a가 가진 주사위 번호들을 돈다
            vector<int> temp;

            for (int sum : a_sum) { // 기존의 a_sum들을 꺼내서
                for (int face : dice[index]) { // 주사위의 인덱스를 돌면서
                    temp.push_back(sum + face);
                }
            }
            a_sum = temp;
        }

        vector<int> b_sum = {0};
        for (int index : b) {
            vector<int> temp;
            for (int sum : b_sum) {
                for (int face : dice[index]) {
                    temp.push_back(sum + face);
                }
            }
            b_sum = temp;
        }

        // 그래서 누가 더 많이 이기나?

        sort(b_sum.begin(), b_sum.end());
        int win = 0;
        for (int a : a_sum) {
            win += lower_bound(b_sum.begin(), b_sum.end(), a) - b_sum.begin();
            // b_sum = {3, 4, 5, 6}, a = 5라면 lower_bound는 5의 처음 위치인 index 2를 반환
        }

        if (win > max_win) {
            max_win = win;
            answer = a;
        }

    }
}   
    
    while (prev_permutation(comb.begin(), comb.end()));

    for (int &i : answer) i += 1;
    // 승리할 확률이 가장 높아지기 위해 A가 골라야 하는 주사위 번호를 오름차순으로
    sort(answer.begin(), answer.end());
    return answer;

}

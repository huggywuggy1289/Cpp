#include <iostream>
#include <deque>

int slide_windowSolution(){

    // 주어진 값
    String s1 = "abr";
    String s2 = "abracatabra";

    int n = s1.length();
    int target[128] = {0}; // 전체 배열
    int window[128] = {0}; // 창문 크기

    // s1의 알파벳 구성을 장부에 적는다
    for(auto& a : s1) target[a]++;

    int count = 0;
    for(int i = 0; i < s2.length(); i++){ // s2 문자열 돌면서
        window[s2[i]]++ // 윈도우에 하나씩 추가하기

        if(i > n){ // 창문크기가 문자열 사이즈를 넘어서면
            // 창문에서 맨 왼쪽놈을 빼야한다.
            window[s2[i - n]]--;
        }

        // 이제 윈도우안에 문자열이 s1문자열과 전부 똑같은지 봐야한다.
        // 현재 n은 s1의 문자열 길이이므로 딱 3개만 들어와야한다.
        // 즉, i=2일때부터 n의 개수와 같아진다. 따라서 i >= n-1
        if(i >= n-1){
            // 이제 진짜 문자열 똑같은지 봐야한다.
            bool is_match = true;
            // 알파벳 장부를 끝까지 훑는다.
            for(int j = 0; j < sizeof(target) / sizeof(target[0])){
                // 하나라도 숫자가 다르면 아나그램이 아니다.
                if(target[j] != window[j]){
                    is_match = false;
                    break;
                }
            }
            if(is_match){
                count++;
            }
        }
    }

}
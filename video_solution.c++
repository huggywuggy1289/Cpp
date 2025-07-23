#include <string>
#include <vector>
#include <time.h>

using namespace std;

int video_len0, pos0, op_start0, op_end0; //진짜 시간이 될 변수

// 1단계 프로그램 실행 시 오프닝 구간인지 "검사"
bool isOpening(int pos0){
    // 오프닝 구간에 존재한다면
    if(op_start0 <= pos0 && pos0 < op_end0){
        return true;
    }else{
        return false;
    }
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {

    // 2단계 전체 시간을 초단위로 반환 필요 string -> int & 59:59 문자열은 0~4까지
    // substr을 이용해 : 제외하고 0부터 1까지 반환(0,2), 3부터 4까지 반환(3,5)
    video_len0 = stoi(video_len.substr(0,2))*60 + stoi(video_len.substr(3,5));
    pos0 = stoi(pos.substr(0,2))*60 + stoi(pos.substr(3,5));
    op_start0 = stoi(op_start.substr(0,2))*60 + stoi(op_start.substr(3,5));
    op_end0 = stoi(op_end.substr(0,2))*60 + stoi(op_end.substr(3,5));

    // 3단계 현재 재생 위치가 오프닝 구간일 경우
    if(isOpening(pos0)){
        // 오프닝구간을 건너뛰기
        pos0 = op_end0;
    }

    // 4단계 사용자의 입력을 나타내는 1차원 문자열 배열 commands가 매개변수로 주어집니다.
    for(string i : commands){
        if(i == "prev"){
            pos0 = max(0, pos0 - 10); // 10초전으로 최솟값 0
        }
        else if(i == "next"){
            // 건너뛴 구간이 오프닝인지 아닌지 검사
            if(isOpening(pos0)){
                pos0 = op_end0; // 오프닝이면 자동으로 오프닝끝나는 시점으로 넘어가니까
            }
            // 동영상 남은 길이가 10초보다 작으면
            if(video_len0 < 10){
                pos0 = video_len0; // 현재위치가 동영상 맨끝으로 넘어감
            }
            pos0 = min(video_len0, pos0+10);
        }
    }

    // 5단계 사용자의 입력이 모두 끝난 후 동영상의 위치를 "mm:ss" 형식으로 return
    // C언어 나머지는 %, C언어 몫은 나누기와 동일하게 / 기호를 사용

    int mm = pos0 / 60;
    int ss = pos0 % 60;

    // 값을 문자열로 반환
    string m = to_string(mm);
    string s = to_string(ss);

    // 두자릿수 형태
    if(m.size() == 1) m = "0" + m;
    if(s.size() == 1) s = "0" + s;

    string result = m + ":" + s;

    return result;
}
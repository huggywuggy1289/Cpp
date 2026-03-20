#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    
    // 모든 숫자를 문자열로 전환
    for(int num : numbers){
        temp.push_back(to_string(num));
    }
    
    sort(temp.begin(), temp.end(), compare);
    
    for(const string &s : temp){
        answer += s;
    }
    
    if(answer[0] == '0'){
        return "0";
    }
    return answer;
}
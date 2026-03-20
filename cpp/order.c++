#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

// 문자열 s가 전체 주문서(삭제 전)에서 몇 번째인지 계산하는 함수
ll get_index(string s) {
    ll idx = 0;
    ll p26 = 1;
    // 길이가 s.length()보다 짧은 문자열 개수 합산
    for (int i = 1; i < s.length(); ++i) {
        p26 *= 26;
        idx += p26;
    }
    
    // 길이가 같은 문자열 중 s의 순서 계산 (26진수 방식)
    ll current_pos = 0;
    for (int i = 0; i < s.length(); ++i) {
        current_pos = current_pos * 26 + (s[i] - 'a');
    }
    return idx + current_pos + 1;
}

// 전체 주문서에서 k번째인 문자열을 찾는 함수
string get_string(ll k) {
    ll length = 1;
    ll p26 = 26;
    
    // 1. 문자열의 길이를 결정
    while (k > p26) {
        k -= p26;
        length++;
        p26 *= 26;
    }
    
    // 2. 해당 길이 내에서 k번째 문자열 구성 (0-indexed로 변경)
    k--; 
    string res = "";
    for (int i = 0; i < length; ++i) {
        res = (char)('a' + (k % 26)) + res;
        k /= 26;
    }
    return res;
}

string solution(ll n, vector<string> bans) {
    // 1. bans의 원소들을 전체 순서(index)로 변환하여 정렬
    vector<ll> banned_indices;
    for (const string& s : bans) {
        banned_indices.push_back(get_index(s));
    }
    sort(banned_indices.begin(), banned_indices.end());

    // 2. n번째 주문을 찾기 위해 보정 작업 수행
    // n번째 주문 앞에 삭제된 주문이 k개 있다면, 실제로는 n+k번째를 봐야 함
    ll current_idx = n;
    int prev_count = 0;
    
    while (true) {
        // current_idx보다 작거나 같은 banned_indices의 개수 찾기
        int count = upper_bound(banned_indices.begin(), banned_indices.end(), current_idx) - banned_indices.begin();
        
        if (count == prev_count) break; // 더 이상 앞에 추가될 삭제 주문이 없으면 종료
        
        current_idx = n + count;
        prev_count = count;
    }

    return get_string(current_idx);
}
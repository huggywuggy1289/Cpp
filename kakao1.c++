#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

vector<ll> solution(vector<int> arr, ll l, ll r) {
    int n = arr.size();
    vector<ll> sum_len(n + 1, 0);
    vector<ll> sum_val(n + 1, 0);

    for (int i = 0; i < n; i++) {
        sum_len[i + 1] = sum_len[i] + (ll)arr[i];
        sum_val[i + 1] = sum_val[i] + (ll)arr[i] * arr[i];
    }

    // b_rr의 1~p번째까지의 합을 구하는 함수
    auto get_prefix_sum = [&](ll p) {
        if (p <= 0) return 0LL;
        // p가 어느 arr[i] 블록에 있는지 이분탐색
        int idx = lower_bound(sum_len.begin() + 1, sum_len.end(), p) - sum_len.begin();
        ll prev_count = sum_len[idx - 1];
        ll remain = p - prev_count;
        return sum_val[idx - 1] + remain * (ll)arr[idx - 1];
    };

    ll K = get_prefix_sum(r) - get_prefix_sum(l - 1);
    ll L = r - l + 1;
    ll total_len = sum_len[n];
    ll C = 0;

    ll s = 1;
    ll max_s = total_len - L + 1;

    // 현재 s와 e(s+L-1)의 위치 인덱스
    int s_idx = 0;
    int e_idx = 0;

    while (s <= max_s) {
        ll e = s + L - 1;
        
        // s와 e가 각각 몇 번째 arr 블록에 있는지 업데이트
        while (s_idx < n && sum_len[s_idx + 1] < s) s_idx++;
        while (e_idx < n && sum_len[e_idx + 1] < e) e_idx++;

        if (s_idx >= n || e_idx >= n) break;

        // 현재 윈도우의 합 계산
        ll cur_sum = get_prefix_sum(e) - get_prefix_sum(s - 1);

        // 현재 s_idx 블록과 e_idx 블록이 유지되는 최대 이동 가능 거리 d
        ll d_s = sum_len[s_idx + 1] - s + 1;
        ll d_e = sum_len[e_idx + 1] - e + 1;
        ll d_limit = max_s - s + 1;
        ll d = min({d_s, d_e, d_limit});

        // 윈도우가 이동할 때 나가는 값 out = arr[s_idx], 들어오는 값 in = arr[e_idx]
        ll out_val = arr[s_idx];
        ll in_val = arr[e_idx];
        ll diff = in_val - out_val;

        if (diff == 0) {
            // 변화가 없으므로 cur_sum이 K와 같다면 d개 모두 정답
            if (cur_sum == K) C += d;
        } else {
            // cur_sum + k * diff == K 를 만족하는 k (0 <= k < d)가 있는지 확인
            // k = (K - cur_sum) / diff
            if ((K - cur_sum) % diff == 0) {
                ll k = (K - cur_sum) / diff;
                if (k >= 0 && k < d) C++;
            }
        }

        // s를 d만큼 점프
        s += d;
    }

    return {K, C};
}
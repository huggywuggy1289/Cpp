#include <vector>
#include <deque>

using namespace std;

inline int get_idx(int r, int c, int col_size) {
    return r * col_size + c;
}

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<int> rain_map(m * n, 2000000001);
    for (int i = 0; i < (int)drops.size(); i++) {
        rain_map[get_idx(drops[i][0], drops[i][1], n)] = i + 1;
    }

    int new_n = n - w + 1;
    vector<int> row_min(m * new_n);

    for (int r = 0; r < m; r++) {
        deque<int> dq;
        for (int c = 0; c < n; c++) {
            while (!dq.empty() && rain_map[get_idx(r, dq.back(), n)] >= rain_map[get_idx(r, c, n)]) {
                dq.pop_back();
            }
            dq.push_back(c);
            if (dq.front() <= c - w) dq.pop_front();

            if (c >= w - 1) {
                row_min[get_idx(r, c - w + 1, new_n)] = rain_map[get_idx(r, dq.front(), n)];
            }
        }
    }

    int max_survival_time = -1;
    vector<int> answer = {0, 0};
    vector<deque<int>> col_dqs(new_n);

    for (int r = 0; r < m; r++) {
        for (int c = 0; c < new_n; c++) {
            while (!col_dqs[c].empty() && row_min[get_idx(col_dqs[c].back(), c, new_n)] >= row_min[get_idx(r, c, new_n)]) {
                col_dqs[c].pop_back();
            }
            col_dqs[c].push_back(r);
            if (col_dqs[c].front() <= r - h) col_dqs[c].pop_front();

            if (r >= h - 1) {
                int current_min = row_min[get_idx(col_dqs[c].front(), c, new_n)];
                if (current_min > max_survival_time) {
                    max_survival_time = current_min;
                    answer = {r - h + 1, c};
                }
            }
        }
    }

    return answer;
}
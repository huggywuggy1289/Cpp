#include <vector>
#include <queue>
#include <algorithm>
#include <set>

using namespace std;

struct Edge {
    int to;
    int type;
};

int solution(int n, int infection, vector<vector<int>> edges, int k) {
    vector<vector<Edge>> adj(n + 1);
    for (const auto& e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    int max_infected = 0;

    // 현재 감염된 노드들의 상태를 관리하는 큐 (BFS 형태)
    // 사실상 k가 작고 종류가 3개이므로 모든 조합을 시도해보는 DFS가 적합합니다.
    
    // state: 현재 감염된 노드들(bitmask 또는 vector), 남은 횟수 k
    // 하지만 노드가 100개이므로 bitmask는 불가능, set이나 vector 사용
    
    auto get_infected_count = [&](const vector<int>& order) {
        vector<bool> infected(n + 1, false);
        infected[infection] = true;
        int count = 1;

        for (int type : order) {
            queue<int> q;
            // 현재 감염된 모든 노드를 시작점으로 설정
            for (int i = 1; i <= n; i++) {
                if (infected[i]) q.push(i);
            }

            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (const auto& edge : adj[curr]) {
                    if (edge.type == type && !infected[edge.to]) {
                        infected[edge.to] = true;
                        count++;
                        q.push(edge.to); // 새롭게 감염된 노드에서 같은 타입으로 더 갈 수 있음
                    }
                }
            }
        }
        return count;
    };

    // 3가지 타입을 k번 선택하는 모든 경우의 수 (중복 순열)
    // 3^k 인데 k=10이면 약 59,000가지. N=100이므로 충분히 가능.
    vector<int> current_order;
    
    // 재귀적으로 모든 파이프 오픈 순서를 탐색
    auto dfs = [&](auto self, int depth) -> void {
        if (depth == k) {
            max_infected = max(max_infected, get_infected_count(current_order));
            return;
        }

        for (int t = 1; t <= 3; t++) {
            // 직전과 같은 타입을 여는 것은 의미가 없으므로 가지치기
            if (!current_order.empty() && current_order.back() == t) continue;
            
            current_order.push_back(t);
            self(self, depth + 1);
            current_order.pop_back();
        }
        
        // k번을 다 채우지 않아도 최대값이 나올 수 있으므로 현재 상태도 체크
        max_infected = max(max_infected, get_infected_count(current_order));
    };

    dfs(dfs, 0);

    return max_infected;
}
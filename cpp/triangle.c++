#include <vector>
#include <algorithm>

using namespace std;

struct UnionFind {
    vector<int> parent;
    vector<int> size;
    int max_size;

    UnionFind(int n) {
        parent.resize(n);
        size.assign(n, 1);
        max_size = 1;
        for (int i = 0; i < n; i++) parent[i] = i;
    }


    int find(int i) {
        int root = i;
        while (parent[root] != root) {
            root = parent[root];
        }
        // 경로 압축
        while (parent[i] != root) {
            int next = parent[i];
            parent[i] = root;
            i = next;
        }
        return root;
    }

    void unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j) {
            if (size[root_i] < size[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i;
            size[root_i] += size[root_j];
            if (size[root_i] > max_size) max_size = size[root_i];
        }
    }
};

int solution(int** grid, size_t grid_rows, size_t grid_cols) {
    int N = (int)grid_rows;
    int M = (int)grid_cols;
    
    // 칸당 2개의 삼각형이 존재하므로 총 노드 수는 N * M * 2
    UnionFind uf(N * M * 2);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int curr_idx = (i * M + j) * 2;

            // 1. 위쪽 칸과 연결 (현재 칸 상단 <-> 위 칸 하단)
            if (i > 0) {
                int up_idx = ((i - 1) * M + j) * 2;
                // grid[i][j]의 방향에 상관없이 0번은 위쪽을 포함, 1번은 아래쪽을 포함
                uf.unite(curr_idx + 0, up_idx + 1);
            }

            // 2. 왼쪽 칸과 연결 (현재 칸 왼쪽 <-> 왼쪽 칸 오른쪽)
            if (j > 0) {
                int left_idx = (i * M + (j - 1)) * 2;
                
                // 현재 칸(i, j)에서 왼쪽 변을 담당하는 삼각형 번호
                // grid[i][j] == 1 (/) 이면 0번(상좌)이 왼쪽
                // grid[i][j] == -1 (\) 이면 1번(하좌)이 왼쪽
                int curr_left = (grid[i][j] == 1) ? 0 : 1;
                
                // 왼쪽 칸(i, j-1)에서 오른쪽 변을 담당하는 삼각형 번호
                // grid[i][j-1] == 1 (/) 이면 1번(하우)이 오른쪽
                // grid[i][j-1] == -1 (\) 이면 0번(상우)이 오른쪽
                int left_right = (grid[i][j - 1] == 1) ? 1 : 0;
                
                uf.unite(curr_idx + curr_left, left_idx + left_right);
            }
        }
    }

    return uf.max_size;
}
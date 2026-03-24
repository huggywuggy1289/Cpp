#include <string>
#include <vector>

using namespace std;

// 구해야하는 것 : 생성한 정점의 번호, 정점을 생성하기 전 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int donut = 0, bar = 0, eight = 0;
    int root = -1;

    int inDegree[1000001] = {0};
    int outDegree[1000001] = {0};

    for(auto& e : edges){
        outDegree[e[0]]++;
        inDegree[e[1]]++;
    }

    for(int i = 0; i <= 1000000; i++){
        if(outDegree[i] >= 2 && inDegree[i] == 0){
            root = i;
            break;
        }
    }

    int total_graph_count = outDegree[root];

    for(int i = 0; i <= 1000000; i++){
        if(i == root) continue;
        if(outDegree[i] == 2) eight++;
        if(outDegree[i] == 0 && inDegree[i] != 0) bar++;
    }

    donut = total_graph_count - eight - bar;

    answer.push_back(root);
    answer.push_back(donut);
    answer.push_back(bar);
    answer.push_back(eight);

    return answer;
}
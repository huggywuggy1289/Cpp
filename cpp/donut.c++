#include <string>
#include <vector>

using namespace std;

// 구해야하는 것 : 생성한 정점의 번호, 정점을 생성하기 전 도넛 모양 그래프의 수, 막대 모양 그래프의 수, 8자 모양 그래프의 수
vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer; 
    int donut = 0;
    int bar = 0;
    int eight = 0;
    
    //  이 그래프들과 무관한 정점을 하나 생성한 뒤, 각 도넛 모양 그래프, 막대 모양 그래프, 8자 모양 그래프의 임의의 정점 하나로 향하는 간선들을 연결하므로, 루트는 진입차수0 이자 진출차수 >=2를 만족한다.
    
    // 정점번호 a,b는 1 ≤ a, b ≤ 1,000,000을 만족하므로 inDegree[정점번호] = 진입차수 outDegree[정점번호] = 진출차수 -> 1부터 시작해야하니 1000001로 잡는다.
    int inDegree[1000001] = {0};
    int outDegree[1000001] = {0};
    
    // 각 원소는 [출발, 도착] 따라서
    // e[0] = 출발 정점 번호
    // e[1] = 도착 정점 번호
    for(auto& e : edges){ // edges의 원소타입이 vector이므로 auto&가 알아서 e를 vector<int>형식으로 받아줌
        outDegree[e[0]]++; // e[0]이 쏘는 화살표 +1
        inDegree[e[1]]++; // e[1]이 쏘는 화살표 +1
    }
    
    // 루트 찾기
    int root = -1;
    for(int i = 0; i <=1000000; i++){
        // 루트는 진입차수0 이자 진출차수 >=2를 만족
        if(inDegree[i] == 0 && outDegree[i] >= 2){
            root = i;
            break;
        }
    }
    // 그림에서 볼 수 있듯 루트에서 나가는 간선 수 = 전체 그래프 수
    int total_graph_count = outDegree[root];
    
    for(int i = 1; i <= 1000000; i++){
        if(i == root) continue;
        if(outDegree[i] == 2) eight++;
        if(outDegree[i] == 0 && inDegree[i] != 0) bar++;
    }
	// 따라서 진출차수 = 총 그래프 개수(8자+막대+도넛)
    donut = total_graph_count - eight - bar;
    answer.push_back(root);
    answer.push_back(donut);
    answer.push_back(bar);
    answer.push_back(eight);
    
    return answer;
}
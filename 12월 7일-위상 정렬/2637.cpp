#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

//위상정렬(큐, 진입차수 저장하는 벡터 이용 - 진입차수 0인 것 큐에 push 하고 맨 앞의 노드부터 pop하면서 진입차수 갱신) + DP(필요한 부품 수 구하기 위해 이전 결과를 저장한 것을 활용)
vector<vector<int>> topologicalSort(int n, vector<int> &indegree, vector<vector<ci>> &graph) {
    queue<int> q; //위상정렬 위해 큐 이용
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); //각 부품이 몇 개 필요한지 저장

    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) { //진입차수가 0이라면 -> 기본 부품
            q.push(i); //큐에 push
            dp[i][i] = 1; //기본 부품 초기화
        }
    }
    while (!q.empty()) {
        int node = q.front(); //큐의 맨 앞 노드
        q.pop(); //큐에서 pop

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; //인접 그래프에서의 다음 노드
            int cnt = graph[node][i].second; //필요한 부품 수
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 push

            for (int j = 1; j <= n; j++)
                dp[next_node][j] += dp[node][j] * cnt; //(현재 정점을 이루는 부품 개수 * 필요한 현재 정점의 개수)를 더함
        }
    }
    return dp; //각 부품이 몇 개 필요한지 저장한 2차원 벡터 리턴
}

/**
 * 각 부품마다 종류별 필요한 부품 개수를 저장하기 위해 2차원 배열 사용 (행: 부품, 열: 행을 이루는데 각 부품별 필요한 개수)
 * 위상 정렬 순서에 따라, 이어진 다음 정점의 부품별 개수를 (현재 정점을 이루는 부품별 개수 * 필요한 현재 정점 수)를 더해주며 구함
 */

int main() {
    int n, m, x, y, k;

    //입력
    cin >> n >> m;
    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //인접그래프
    vector<int> indegree(n + 1, 0); //진입차수 저장하는 벡터
    //선후관계 정의
    while (m--) {
        cin >> x >> y >> k; //y -> x
        indegree[x]++; //진입차수 증가
        graph[y].push_back({x, k}); //인접그래프 구성
    }

    //연산
    vector<vector<int>> result = topologicalSort(n, indegree, graph);

    //출력
    for (int i = 1; i <= n; i++) {
        if (result[i][i]) //기본 부품이라면
            cout << i << ' ' << result[n][i] << '\n';
    }
    return 0;
}
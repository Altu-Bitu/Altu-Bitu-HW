#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//위상정렬
vector<int> topologicalSort(int n, vector<int> &indegree, vector<vector<int>> &graph) {
    vector<int> result; //순서 저장할 벡터
    queue<int> q; //위상 정렬하기 위한 큐

    //위상정렬 하기
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) //진입차수가 0이라면
            q.push(i); //큐에 push
    }

    while (!q.empty()) { //큐에 원소가 없어질 때까지
        int node = q.front(); //맨 앞의 노드
        q.pop(); //큐에서 pop

        result.push_back(node); //현재 정점 순서에 삽입
        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i]; //인접 그래프에 있는 다음 노드 찾기
            indegree[next_node]--; //연결된 정점의 진입차수를 1씩 감소
            if (!indegree[next_node]) //연결된 정점의 진입차수가 0이 되었다면
                q.push(next_node); //큐에 다음 노드 push
        }
    }
    return result; //위상 정렬 순서 벡터 리턴
}

/**
 * 기본적인 위상 정렬 문제
 * 현재 가수와 바로 전 가수 사이의 선후관계를 정의
 * 순서를 정하는 것이 불가능한 경우(위상정렬을 할 수 없는 경우)는 모든 정점을 탐색하지 못한 경우
 */

int main() {
    int n, m, cnt, prev, cur;

    //입력
    cin >> n >> m;
    vector<int> indegree(n + 1, 0); //진입차수 저장하는 벡터
    vector<vector<int>> graph(n + 1, vector<int>(0)); //인접 그래프
    while (m--) { 
        cin >> cnt; //담당 가수의 수
        cin >> prev; //처음 가수 입력
        while (--cnt) { //선후관계 정의
            cin >> cur;
            indegree[cur]++; //진입 차수로 선후관계 정의
            graph[prev].push_back(cur); //인접그래프에서 선후관계 정의
            prev = cur; //이전 노드로 현재 노드 정의
        }
    }

    //연산
    vector<int> result = topologicalSort(n, indegree, graph);

    //출력
    if (result.size() != n) { //순서를 정하는 것이 불가한 경우
        cout << "0\n";
        return 0;
    }
    for (int i = 0; i < result.size(); i++)
        cout << result[i] << '\n';
}
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 8 * 3; //최대 N-1개의 간선을 지나게 됨 * 중복 순회 가능(3)

vector<int> dijkstra(int vertex, int start, vector<vector<ci>> &graph) {
    vector<int> dist(vertex + 1, INF); //정점까지의 최소 거리 저장
    priority_queue<ci, vector<ci>, greater<>> pq; //우선순위 큐 이용 - pair로 구성, 오름차순 정렬, first : 시작점으로부터의 거리, second : 정점

    //시작 위치 초기화
    dist[start] = 0; //시작 위치 정점까지의 거리: 0
    pq.push({0, start}); //(거리: 0, 시작 정점 위치)를 우선순위 큐에 저장

    while (!pq.empty()) {
        int weight = pq.top().first; //가장 작은 가중치값
        int node = pq.top().second; //가장 작은 가중치값 갖는 노드의 번호
        pq.pop(); //pop

        if (weight > dist[node]) //이미 확인했던 정점 - continue로 건너뛰기
            continue;

        //가중치가 dist[node]와 같거나 작다면 검사
        for (int i = 0; i < graph[node].size(); i++) { //node와 연결된 정점들 검사
            int next_node = graph[node][i].first; //연결된 정점
            int next_weight = weight + graph[node][i].second; //시작점으로부터 연결된 정점까지의 거리

            if (dist[next_node] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[next_node] = next_weight; //거리 갱신
                pq.push({next_weight, next_node}); //갱신된 값, 갱신된 노드로 우선순위 큐에 push
            }
        }
    }
    return dist; //계산한 길이 리턴
}

/**
 * 가능한 경로
 * 1. 1 -> v1 -> v2 -> n
 * 2. 1 -> v2 -> v1 -> n
 * -> 1, v1, v2를 시작점으로 하는 다익스트라 함수 실행하기
 *
 * !주의!
 * 1. 한 번 이동했던 정점, 간선을 다시 방문할 수 있음. 즉 1->N의 최댓값이 INF(1e5*8)이 아니라 3*INF!
 * 2. 출력에서 (ans == 3*INF)을 하지 않고 INF을 3*INF 값으로 초기화 하는 이유
 *    조건에 의하면 E의 값이 0일 수도 있음. 이 경우에선 1->1->N->N의 값이 INF이라 경로가 없음에도 3*INF 조건에 걸리지 않음.
 *    INF을 3*INF으로 초기화하면 해결 가능
 */
int main() {
    int n, e, a, b, c, v1, v2;

    //입력
    cin >> n >> e;

    vector<vector<ci>> graph(n + 1, vector<ci>(0)); //각 인덱스에서의 정점, 길이를 2차원 벡터에 pair로 저장
    vector<vector<int>> dist(3, vector<int>(n + 1, 0)); //1, v1, v2가 시작점인 경우에 해당 인덱스까지의 거리 저장 -> 행 개수: 3개, 열 개수: n개
    while (e--) { //무방향 그래프
        cin >> a >> b >> c;
        graph[a].emplace_back(b, c); //a번 정점에서 b번 정점까지 거리:c
        graph[b].emplace_back(a, c); //b번 정점에서 a번 정점까지 거리:c
        //양방향 그래프이므로 위의 두 가지로 모두 저장해놔야함
    }
    cin >> v1 >> v2; //반드시 지나야하는 두 개의 정점

    //연산
    vector<int> start_nodes = {1, v1, v2};
    for (int i = 0; i < 3; i++) //1, v1, v2에서 시작한 다익스트라 결과 저장
        dist[i] = dijkstra(n, start_nodes[i], graph);

    //1->v1->v2->n의 경로와 1->v2->v1->n의 경로 중 최솟값
    //무방향 그래프기 때문에 v1->v2와 v2->v1은 사실 같은 값!
    int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

    //출력
    cout << ((ans >= INF) ? -1 : ans); //최단 경로가 없는 경우 -1 출력, 있는 경우 최단 경로 길이 출력
}
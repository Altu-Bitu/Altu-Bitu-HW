#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e5 * 2; //최대 n-1개의 간선을 지나게 됨

void floydWarshall(int n, vector<vector<int>> &graph, vector<vector<int>> &table) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int new_dist = graph[i][k] + graph[k][j]; //중간에 k를 거쳐서 i에서 j로 감
                if (new_dist < graph[i][j]) { //i->k->j가 i->j보다 빠른 경로라면
                    graph[i][j] = new_dist; //더 짧은 경로로 갱신
                    table[i][j] = table[i][k]; //k를 거치는 경로가 더 짧다면 k를 거친다는 것을 표시한다. k로 가는 중간 경로도 빼놓지말기
                }
            }
        }
    }
}

/**
 * graph : 플로이드-워셜 결과 행렬 그래프
 * table : 경로표. table[i][j] = i->j로 가기 위해 제일 먼저 거쳐야 하는 정점
 *
 * 1. i->j의 중간 경로를 i로 초기화
 * 2. i->k->j가 i->j보다 짧다면 i->j의 중간 경로를 i->k의 중간 경로(table[i][k])로 갱신
 *    k로 갱신하는게 아니라 table[i][k]로 갱신하는 이유는?
 *    만약 i->k의 경로가 i->t->k라면 최종 경로는 i->t->k->j
 *    바로 k로 갱신하면 t를 놓칠 수 있기 때문에 table[i][k]로 갱신
 *    line 16을 table[i][j] = k로 바꾸면 결과가 어떻게 되는지 확인해보세요
 */
int main() {
    int n, m, s, d, c;

    //입력
    cin >> n >> m;
    vector<vector<int>> graph(n+1, vector<int>(n+1, INF)); //가중치 연산 결과 저장
    vector<vector<int>> table(n+1, vector<int>(n+1, 0)); //경로표
    for (int i = 1; i <= n; i++)
        graph[i][i] = 0;

    while (m--) { //무방향 그래프
        cin >> s >> d >> c;
        //간선 정보
        graph[s][d] = graph[d][s] = c; //무방향 그래프이므로 s->d, d->s 둘 다 가중치를 c로 저장

        //경로 정보
        table[s][d] = d; //일단 table에 d로 저장
        table[d][s] = s; //일단 table에 s로 저장
    }

    //연산
    floydWarshall(n, graph, table); //최단 경로 경로표 생성

    //출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                cout << "- ";
            else
                cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
}
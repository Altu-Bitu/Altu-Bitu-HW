#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<bool> visited; //해당 도시 방문했는지 저장할 벡터
vector<vector<int>> matrix; //도시간 이동 비용 저장할 2차원 벡터
int ans = INF; //최소 비용 저장할 변수, 최소 비용을 저장해야하므로 INF로 초기화

/**
 * 모든 도시를 방문한 뒤 돌아올 수 있는 모든 경우 탐색
 * !생각해보기! 함수의 각 인자는 각각 어떤 역할을 하고 있나요?
 */
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) { //전체 도시 개수, 출발하는 도시, 현재 도시, 지금 몇 번째 도시인가, 지금까지의 비용
    if (cost >= ans) //생각해보기 : 이 조건문이 없으면 어떻게 될까요? - 최소 비용을 구해야하기 때문에 이 조건문이 필요하다. 이 조건문이 없으면 최소 비용 구하지 못할 것이다.
        return;
    if (cnt == n) { //종료 조건 : n개의 도시를 순회했음
        //출발 도시로 다시 돌아올 수 있는지 확인
        if (matrix[cur_city][start_city] != 0)
            ans = min(ans, cost + matrix[cur_city][start_city]); //이전의 경로와 지금의 경로 중 더 작은 것을 ans변수에 저장한다.
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city에서 도시 i로 이동
        if (matrix[cur_city][i] && !visited[i]) { //길이 있고, 아직 방문하지 않은 도시 -> cur_city가 i로 바뀜
            visited[i] = true; //방문 처리
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]); //백트래킹 재귀함수 - 인자: (전체 도시 개수, 시작하는 도시는 그대로(main에서 바꿔줌), 현재 도시(i), cnt +1, 이전까지의 비용 + cur_city에서 i로 가는 비용)
            visited[i] = false; //다음 재귀함수 연산을 위해서 미방문 처리
        }
    }
}

/**
 * 백트래킹 풀이 (4ms)
 *
 * !주의! 모든 도시를 방문 후 시작 도시로 돌아와야 하기 때문에 어떤 도시에서 출발했는지 알고 있어야 함.
 */
int main() {
    int n;

    //입력
    cin >> n;
    visited.assign(n, false); //visited 배열 false로 초기화
    matrix.assign(n, vector<int>(n, 0)); //2차원 벡터 0으로 초기화
    for (int i = 0; i < n; i++) { //2차원 벡터 입력
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //연산
    //i번째 도시를 시작으로 순회
    for (int i = 0; i < n; i++) {
        visited[i] = true; //방문 처리
        backtracking(n, i, i, 1, 0); //백트래킹 함수 - 전체 도시 개수:n, start_city:i(0부터 시작), cur_city:i(0부터 시작),cnt:1, cost:0
        visited[i] = false; //미방문 처리!
    }

    //출력
    cout << ans;
}
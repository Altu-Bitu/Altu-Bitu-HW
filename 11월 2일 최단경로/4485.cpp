#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;
const int INF = 1e5 * 2; //최대 N*N 칸을 지나게 됨

int dijkstra(int n, vector<vector<int>> &board) {
    //좌, 우, 하, 상
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int ans = 0; //잃는 최소 금액
    vector<vector<int>> dist(n, vector<int>(n, INF)); //위치, 거리
    priority_queue<pair<int, ci>, vector<pair<int, ci>>, greater<>> pq; //우선순위 큐 - 좌표 - pair로 구성 - 오름차순 정렬

    //시작 위치 초기화
    dist[0][0] = board[0][0]; //시작 위치의 도둑 루피의 크기
    pq.push(make_pair(dist[0][0], make_pair(0, 0))); //시작 위치의 도둑 루피의 크기, 좌표 우선순위 큐에 저장

    while (!pq.empty()) {
        //가장 작은 도둑 루피의 크기 위치 찾고 pop
        int weight = pq.top().first; //가중치
        int row = pq.top().second.first; //행 위치
        int col = pq.top().second.second; //열 위치
        pq.pop(); //pop

        if (row == n - 1 && col == n - 1) { //제일 오른쪽 아래 칸(목적지) 도착 - break
            ans = weight; //해당 위치까지의 가중치 값으로 ans 경신
            break; //목적지 도달 했으므로 break
        }
        if(weight > dist[row][col]) //이미 확인했던 좌표 - 저장된 값이 지금 pop한 위치의 weight보다 작은 경우 -건너뛰기
            continue;

        for (int i = 0; i < 4; i++) { //지금 위치에서 상, 하, 좌, 우 4방향 갈 수 있는지 어디가 최소 가중치인지 탐색
            int nr = row + dr[i]; //탐색할 행 위치
            int nc = col + dc[i]; //탐색할 열 위치
            if ((nr < 0) || (nr >= n) || (nc < 0) || (nc >= n)) //범위를 벗어난다면
                continue;

            //범위 내에 들어온다면
            int next_weight = weight + board[nr][nc]; //시작점으로부터 연결된 좌표까지의 거리
            if (dist[nr][nc] > next_weight) { //더 짧은 경로로 갈 수 있다면
                dist[nr][nc] = next_weight; //해당 위치의 거리 갱신
                pq.push({next_weight, {nr, nc}}); //우선순위 큐에 갱신된 가중치 값으로 push
            }
        }
    }
    return ans; //ans 리턴
}

/**
 * 상하좌우로 이동 가능 -> 연결됐다는 것
 * 시작 지점이 (0, 0)인 다익스트라
 */
int main() {
    int n, num = 1; //num: 출력 시 필요함 - problem 번호로 사용

    while (true) {
        //입력
        cin >> n; 
        if (n == 0) //n에 0이 입력되면 종료
            break;

        vector<vector<int>> board(n, vector<int>(n, 0)); //각 위치의 도둑루피의 크기 입력 받을 board
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cin >> board[i][j];
        }

        //연산 & 출력
        cout << "Problem " << num++ << ": " << dijkstra(n, board) << '\n';
    }
}
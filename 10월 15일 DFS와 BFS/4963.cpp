#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

//가로, 세로, 대각선으로 연결되어 있으면 하나의 섬
//상, 하, 좌, 우, 좌상향 대각선, 우상향 대각석, 좌하향 대각선, 우하향 대각선
int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

vector<vector<int>> board; //지도
int h, w; //높이, 너비

//dfs 탐색
void dfs(int cr, int cc) {
    board[cr][cc] = 0; //방문 체크

    for (int i = 0; i < 8; i++) { //가능한 방향의 정점(자식노드) 모두 탐색
        int nr = cr + dr[i]; //x축
        int nc = cc + dc[i]; //y축
        if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc]) //탐색하려는 정점이 범위 내에 있고, 땅이라면
            dfs(nr, nc); //바로 탐색(깊게 탐색)
    }
}

//bfs 탐색
void bfs(int row, int col) {
    queue<ci> q; 

    q.push(ci(row, col)); //큐에 처음 위치 push
    board[row][col] = 0; //처음 위치 방문 체크

    while (!q.empty()) {
        int cr = q.front().first; //현재 정점의 행 정보
        int cc = q.front().second; //현재 정점의 열 정보
        q.pop(); //pop

        for (int i = 0; i < 8; i++) { //가능한 방향의 정점(자식노드) 모두 탐색
            int nr = cr + dr[i]; //x축
            int nc = cc + dc[i]; //y축
            if (nr >= 0 && nr < h && nc >= 0 && nc < w && board[nr][nc]) { //탐색하려는 정점이 범위 내에 있고, 땅이라면
                board[nr][nc] = 0; //방문 체크
                q.push(ci(nr, nc)); //다음 위치 큐에 push
            }
        }
    }
}

/**
 * 섬의 개수를 구하는 문제 -> 섬의 개수만큼 탐색을 하면 된다
 * 모든 정점을 검사해야 하므로 dfs, bfs 풀이 모두 가능
 * 입력으로 들어오는 보드를 방문 탐색 배열로 함께 사용 (방문하면 1(땅)을 0(바다)으로 바꾸기-방문 체크)
 */

int main() {
    while (true) { //계속 입력 받다가 0 두 개 입력 받으면 종료
        cin >> w >> h;
        if (w == 0) //w에 0들어오면 지도 생성 불가이므로 바로 종료
            break;

        //보드 입력 (땅:1, 바다:0)
        board.assign(h, vector<int>(w, 0));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> board[i][j];

        //연산 & 출력
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j]) { //땅을 찾았다면 바로 탐색 시작
                    ans++;
                    bfs(i, j);
                    //dfs(i, j);
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
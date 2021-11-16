#include <iostream>
#include <vector>

using namespace std;

int n, m, ans = 65;
vector<vector<int>> board;

//cctv 범위 표시
void ray(int row, int col, int dir) {
    //좌, 하, 상, 우
    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    while (row >= 0 && row < n && col >= 0 && col < m && board[row][col] != 6) { //범위 체크하고 벽이 아닌 곳 체크하며 dir 방향으로 뻗어나가며 cctv 표시
        if (board[row][col] == 0) //다른 cctv를 지우지 않기 위해 빈 공간일 때만 표시 - cctv의 범위가 지나가는 곳
            board[row][col] = 7; //0이 아닌 다른 것으로 표시
        row += dr[dir]; //dir방향으로 쭉 진행
        col += dc[dir]; //dir방향으로 쭉 진행
    }
}

//cctv 방향 지정
void install(int cctv, int row, int col, int dir) {
    //방향이 겹치는 것끼리 조건문을 걸어서 cctv범위를 체크 - 상,하,좌,우 4방향이므로 %4 모듈러 연산 이용
    if (cctv >= 1) //1, 2, 3, 4, 5번 cctv
        ray(row, col, dir);
    if (cctv >= 2 && cctv != 3) //2, 4, 5번 cctv
        ray(row, col, (dir + 2) % 4);
    if (cctv >= 3) //3, 4, 5번 cctv
        ray(row, col, (dir + 1) % 4);
    if (cctv == 5) //5번 cctv
        ray(row, col, (dir + 3) % 4);
}

//사각지대 계산
int blindSpot() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!board[i][j]) //0인 곳의 개수 세기
                cnt++;
        }
    }
    return cnt; //계산한 사각지대 수 리턴
}

void backtracking(int idx) {
    if (idx == n * m) { //기저 조건 : 사무실의 모든 위치 확인
        ans = min(ans, blindSpot()); //사각지대 계산 후 최솟값 갱신
        return;
    }

    int row = idx / m; //ex. m=8일 때, idx:0~7 첫 번째 행, 8~15 두 번째 행 ... -나누기 연산으로
    int col = idx % m; //ex. m=8일 때, idx:0,8,16..  인덱스 첫 번째 열, 1,9,17.. 인덱스 두 번째 열 -모듈러 연산으로 
    int cur = board[row][col];
    if (cur == 0 || cur == 6 || cur == 7) //cctv가 없는 곳
        return backtracking(idx + 1); //idx증가시켜 backtracking 재귀함수로 적용

    vector<vector<int>> save = board; //unvisited 처리용 board 상태 저장
    for (int i = 0; i < 4; i++) { //4개의 방향에 대해 cctv 설치(1,3,4번 방향은 4개 방향종류 존재)
        install(cur, row, col, i); //cctv 방향 지정
        backtracking(idx + 1); //idx증가시켜 backtracking 재귀함수로 적용
        board = save; //board에 save 복사

        //2번 cctv의 방향 종류는 2개, 5번 cctv의 방향 종류는 1개
        if ((cur == 2 && i == 1) || (cur == 5 && i == 0))
            break;
    }
}

/**
 * cctv가 설치될 수 있는 모든 경우를 고려하는 완전탐색 문제
 *
 * 1. 각 cctv에 대해 가능한 모든 방향을 고려하여 설치
 *    1, 3, 4번 cctv : 4방향
 *    2번 cctv : 2방향
 *    5번 cctv : 1방향
 * 2. install 함수에서 각 cctv의 빛이 뻗어나갈 방향을 잡음
 * 3. ray 함수에서 cctv의 감시 가능 범위 표시
 * 4. 모든 위치를 확인했으면 blindSpot 함수를 통해 사각지대 계산
 *
 * 풀이 : https://myunji.tistory.com/411
 * 해당 코드는 위 링크의 코드를 리팩토링한 코드입니다.
 * 말로는 풀이를 설명하기 어려우니 링크를 꼭 확인해주세요!
 */
int main() {
    //입력
    cin >> n >> m;
    board.assign(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> board[i][j];
    }

    //연산
    backtracking(0); //인덱스 0부터 시작

    //출력
    cout << ans;
}
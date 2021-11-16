#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 19;

//범위와 돌의 종류가 유효한지 확인
bool promising(int r, int c, int stone, vector<vector<int>> &board) {
    return r >= 0 && r < SIZE && c >= 0 && c < SIZE && board[r][c] == stone;
}

bool validDir(int r, int c, int d, int stone, vector<vector<int>> &board) { //r,c-좌표, d-방향, 0/1/2, 바둑판
    //가로, 세로, 우하향 대각선, 우상향 대각선 확인 필요
    int dr[4] = {0, 1, 1, -1};
    int dc[4] = {1, 0, 1, 1};

    //(r, c) 이전에 d방향에 위치한 이어지는 돌이 있나?
    bool is_six = promising(r - dr[d], c - dc[d], stone, board); //범위 내에 있고 돌인가(0이 아닌가) 

    int cnt = 0; //바둑알 개수
    while (cnt < 6 && promising(r, c, stone, board)) { //(r, c)를 가장 왼쪽으로 하는 이어지는 바둑알의 개수
        cnt++;
        r += dr[d]; //d방향으로 5개인지 판단위해 이동
        c += dc[d]; //d방향으로 5개인지 판단위해 이동
    }
    return cnt == 5 && !is_six; //같은 색 바둑알이 5개이고 이어져 있다.
}

bool isEnd(int r, int c, vector<vector<int>> &board) { //이긴 돌이 있는가?
    for (int i = 0; i < 4; i++) { //가로, 세로, 우하향 대각선, 우상향 대각선
        if (validDir(r, c, i, board[r][c], board))
            return true; //이긴 돌이 있다.
    }
    return false; //이긴 돌이 없다.
}

/**
 * 1. 특정 좌표(r, c)를 가장 왼쪽으로 하는 가능한 모든 오목 배치에 대해 오목 여부 확인
 *    가능한 모든 배치 :  오른쪽, 아래, 우하향, 우상향
 * 2. 육목이상이 되는 경우 : (r, c) 왼쪽에 같은 돌이 있는 경우
 */
int main() {
    vector<vector<int>> board(SIZE, vector<int>(SIZE, 0));

    //입력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++)
            cin >> board[i][j];
    }

    //연산 & 출력
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (!board[i][j]) //돌이 없음-board[i][j]==0인 경우
                continue;
            if (isEnd(i, j, board)) { //이긴 돌이 있다면 출력-좌표는 원래 1,1부터 시작인데 0,0으로 계산했으니 각각 1을 더한다.
                cout << board[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return 0;
            }
        }
    }
    cout << 0; //이긴 돌이 없는 경우
}
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //pair 쉽게 쓰도록 이름 정의 <x좌표, y좌표>

ci dir[4] = {{0,  1},  //우
             {-1, 0},  //상
             {0,  -1}, //좌
             {1,  0}}; //하

//게임을 진행하는 함수
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) { //판 크기, 판-2차원 벡터, 명령-pair

    deque<ci> snake; //머리 위치:front, 꼬리 위치: back으로 쓰고 머리와 꼬리가 각각 줄어들고 늘어나고 해서 deque를 사용하자.
    //뱀의 머리부터 꼬리까지 몸의 각 위치를 x좌표, y좌표를 pair로 deque에 쌓아서 저장한다.
    snake.push_front(ci(0, 0));//뱀 위치 (0,0)으로 초기화
    board[0][0] = 1; //(0,0)에 뱀이 위치하고 게임 시작한다.

    int t = 0, head = 0; //시간 t 0으로 초기화, 뱀의 머리 방향 0(오른쪽 방향)으로 초기화
    while (true) {
        t++; //1초씩 증가
        //뱀의 머리가 위치하게될 칸
        int nr = snake.front().first + dir[head].first; //현재 위치 x좌표 + 방향 x좌표
        int nc = snake.front().second + dir[head].second; //현재 위치 y좌표 + 방향 y좌표

        //게임 종료 조건 : 벽에 부딪히거나, 자기자신의 몸과 부딪힘 (보드의 인덱스를 벗어난다 || 움직인 위치의 board값이 이미 1이다)
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
            break; //종료

        if (board[nr][nc] != 2) { //이동한 칸에 사과가 없다면 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            board[snake.back().first][snake.back().second] = 0; //이동한 칸의 사과가 없다.
            snake.pop_back(); //덱에서 back을 pop한다. = 꼬리가 위치한 칸을 비운다.
        }

        //뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다
        snake.push_front(ci(nr, nc)); //몸길이를 늘린다. = 덱에서 front에 push한다.
        board[nr][nc] = 1; //뱀 위치 표시: 1

        //이번에 방향을 변환하는지 확인
        if (cmd[t] == 'L') //왼쪽 회전
            head = (head + 1) % 4;
        if (cmd[t] == 'D') //오른쪽 회전
            head = (head + 3) % 4;
    }
    return t;
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * 편의를 위해 문제와 달리 (0, 0)부터 시작
 *
 * 보드의 상태가 위와 같을 때
 * 뱀의 몸은 (0, 2)~(2, 2)에 걸쳐 있고, 사과는 (1, 1)에 위치하고 있음
 * -> 뱀의 꼬리와 머리 위치를 알기 위해 덱 사용
 * -> 덱의 front : 머리, 덱의 back : 꼬리
 *
 * 원활한 방향 변환을 위해 dir 배열 사용
 */
int main() {
    int n, k, row, col, l, x; //보드 크기, 사과의 개수, 사과의 위치-행, 사과의 위치-열, 방향 변환 횟수, 방향 변환하는 시간
    char c; //전환할 방향

   //입력
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n)); //뱀이 움직일 보드
    for (int i = 0; i < k; i++) {
        cin >> row >> col;
        board[row - 1][col - 1] = 2; //사과 표시: 2
    }
    cin >> l;
    map<int, char> cmd;
    for (int i = 0; i < l; i++) { //회전 정보 map으로 저장한다.
        cin >> x >> c;
        cmd[x] = c; //인덱스 x의 명령은 c로 map을 이용하여 저장한다.
    }

    //연산 & 출력
    cout << playGame(n, board, cmd); //게임이 몇 초에 끝나는지 출력
}
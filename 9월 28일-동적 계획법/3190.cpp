#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci; //pair ���� ������ �̸� ���� <x��ǥ, y��ǥ>

ci dir[4] = {{0,  1},  //��
             {-1, 0},  //��
             {0,  -1}, //��
             {1,  0}}; //��

//������ �����ϴ� �Լ�
int playGame(int n, vector<vector<int>> &board, map<int, char> &cmd) { //�� ũ��, ��-2���� ����, ���-pair

    deque<ci> snake; //�Ӹ� ��ġ:front, ���� ��ġ: back���� ���� �Ӹ��� ������ ���� �پ��� �þ�� �ؼ� deque�� �������.
    //���� �Ӹ����� �������� ���� �� ��ġ�� x��ǥ, y��ǥ�� pair�� deque�� �׾Ƽ� �����Ѵ�.
    snake.push_front(ci(0, 0));//�� ��ġ (0,0)���� �ʱ�ȭ
    board[0][0] = 1; //(0,0)�� ���� ��ġ�ϰ� ���� �����Ѵ�.

    int t = 0, head = 0; //�ð� t 0���� �ʱ�ȭ, ���� �Ӹ� ���� 0(������ ����)���� �ʱ�ȭ
    while (true) {
        t++; //1�ʾ� ����
        //���� �Ӹ��� ��ġ�ϰԵ� ĭ
        int nr = snake.front().first + dir[head].first; //���� ��ġ x��ǥ + ���� x��ǥ
        int nc = snake.front().second + dir[head].second; //���� ��ġ y��ǥ + ���� y��ǥ

        //���� ���� ���� : ���� �ε����ų�, �ڱ��ڽ��� ���� �ε��� (������ �ε����� ����� || ������ ��ġ�� board���� �̹� 1�̴�)
        if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1)
            break; //����

        if (board[nr][nc] != 2) { //�̵��� ĭ�� ����� ���ٸ� �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�
            board[snake.back().first][snake.back().second] = 0; //�̵��� ĭ�� ����� ����.
            snake.pop_back(); //������ back�� pop�Ѵ�. = ������ ��ġ�� ĭ�� ����.
        }

        //���� �����̸� �÷� �Ӹ��� ����ĭ�� ��ġ��Ų��
        snake.push_front(ci(nr, nc)); //�����̸� �ø���. = ������ front�� push�Ѵ�.
        board[nr][nc] = 1; //�� ��ġ ǥ��: 1

        //�̹��� ������ ��ȯ�ϴ��� Ȯ��
        if (cmd[t] == 'L') //���� ȸ��
            head = (head + 1) % 4;
        if (cmd[t] == 'D') //������ ȸ��
            head = (head + 3) % 4;
    }
    return t;
}

/**
 * 0 0 1
 * 0 2 1
 * 0 0 1
 *
 * ���Ǹ� ���� ������ �޸� (0, 0)���� ����
 *
 * ������ ���°� ���� ���� ��
 * ���� ���� (0, 2)~(2, 2)�� ���� �ְ�, ����� (1, 1)�� ��ġ�ϰ� ����
 * -> ���� ������ �Ӹ� ��ġ�� �˱� ���� �� ���
 * -> ���� front : �Ӹ�, ���� back : ����
 *
 * ��Ȱ�� ���� ��ȯ�� ���� dir �迭 ���
 */
int main() {
    int n, k, row, col, l, x; //���� ũ��, ����� ����, ����� ��ġ-��, ����� ��ġ-��, ���� ��ȯ Ƚ��, ���� ��ȯ�ϴ� �ð�
    char c; //��ȯ�� ����

   //�Է�
    cin >> n >> k;
    vector<vector<int>> board(n, vector<int>(n)); //���� ������ ����
    for (int i = 0; i < k; i++) {
        cin >> row >> col;
        board[row - 1][col - 1] = 2; //��� ǥ��: 2
    }
    cin >> l;
    map<int, char> cmd;
    for (int i = 0; i < l; i++) { //ȸ�� ���� map���� �����Ѵ�.
        cin >> x >> c;
        cmd[x] = c; //�ε��� x�� ����� c�� map�� �̿��Ͽ� �����Ѵ�.
    }

    //���� & ���
    cout << playGame(n, board, cmd); //������ �� �ʿ� �������� ���
}
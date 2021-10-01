#include <iostream>
#include <vector>

using namespace std;
const int INF = 1e9;

vector<bool> visited; //�ش� ���� �湮�ߴ��� ������ ����
vector<vector<int>> matrix; //���ð� �̵� ��� ������ 2���� ����
int ans = INF; //�ּ� ��� ������ ����, �ּ� ����� �����ؾ��ϹǷ� INF�� �ʱ�ȭ

/**
 * ��� ���ø� �湮�� �� ���ƿ� �� �ִ� ��� ��� Ž��
 * !�����غ���! �Լ��� �� ���ڴ� ���� � ������ �ϰ� �ֳ���?
 */
void backtracking(int n, int start_city, int cur_city, int cnt, int cost) { //��ü ���� ����, ����ϴ� ����, ���� ����, ���� �� ��° �����ΰ�, ���ݱ����� ���
    if (cost >= ans) //�����غ��� : �� ���ǹ��� ������ ��� �ɱ��? - �ּ� ����� ���ؾ��ϱ� ������ �� ���ǹ��� �ʿ��ϴ�. �� ���ǹ��� ������ �ּ� ��� ������ ���� ���̴�.
        return;
    if (cnt == n) { //���� ���� : n���� ���ø� ��ȸ����
        //��� ���÷� �ٽ� ���ƿ� �� �ִ��� Ȯ��
        if (matrix[cur_city][start_city] != 0)
            ans = min(ans, cost + matrix[cur_city][start_city]); //������ ��ο� ������ ��� �� �� ���� ���� ans������ �����Ѵ�.
        return;
    }
    for (int i = 0; i < n; i++) { //cur_city���� ���� i�� �̵�
        if (matrix[cur_city][i] && !visited[i]) { //���� �ְ�, ���� �湮���� ���� ���� -> cur_city�� i�� �ٲ�
            visited[i] = true; //�湮 ó��
            backtracking(n, start_city, i, cnt + 1, cost + matrix[cur_city][i]); //��Ʈ��ŷ ����Լ� - ����: (��ü ���� ����, �����ϴ� ���ô� �״��(main���� �ٲ���), ���� ����(i), cnt +1, ���������� ��� + cur_city���� i�� ���� ���)
            visited[i] = false; //���� ����Լ� ������ ���ؼ� �̹湮 ó��
        }
    }
}

/**
 * ��Ʈ��ŷ Ǯ�� (4ms)
 *
 * !����! ��� ���ø� �湮 �� ���� ���÷� ���ƿ;� �ϱ� ������ � ���ÿ��� ����ߴ��� �˰� �־�� ��.
 */
int main() {
    int n;

    //�Է�
    cin >> n;
    visited.assign(n, false); //visited �迭 false�� �ʱ�ȭ
    matrix.assign(n, vector<int>(n, 0)); //2���� ���� 0���� �ʱ�ȭ
    for (int i = 0; i < n; i++) { //2���� ���� �Է�
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    //����
    //i��° ���ø� �������� ��ȸ
    for (int i = 0; i < n; i++) {
        visited[i] = true; //�湮 ó��
        backtracking(n, i, i, 1, 0); //��Ʈ��ŷ �Լ� - ��ü ���� ����:n, start_city:i(0���� ����), cur_city:i(0���� ����),cnt:1, cost:0
        visited[i] = false; //�̹湮 ó��!
    }

    //���
    cout << ans;
}
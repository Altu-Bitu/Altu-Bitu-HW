#include <iostream>
#include <vector>

using namespace std;

//�κ� ��� ���� ������ �Լ�
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { //3*3��� �� �ϹǷ� 3��
        for (int j = col; j < col + 3; j++) { //3���� Ȯ��
            if (matrix_a[i][j] == '1') //1�̸�
                matrix_a[i][j] = '0'; //0����
            else //0�̸�
                matrix_a[i][j] = '1'; //1�� �ٲٱ�
        }
    }
}

//���������� A == B���� Ȯ���ϴ� �Լ�
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) //�ϳ��� �ٸ��� false ����
                return false;
        }
    }

    return true; //�� ������ ���
}

/**
 * (0, 0) �ε������� �κ������ ���� �� �ִ� ������ �ε������� �˻��ϸ� �׸����ϰ� Ǫ�� ����
 * A, B ����� ���� �ε��� ���� ���� �ٸ��ٸ� A ��Ŀ��� ���� �ε����� '����'�ϴ� 3x3 ũ�⸸ŭ�� �κ� ��� ���� ������
 * �˻簡 ��� ���� ��, A�� B�� ���� �ٸ��ٸ� �ٲ� �� ���� �����
 * !����! �Է��� ������� �־����Ƿ� string���� ����
 */

int main() {
    int n, m;

    //�Է�
    cin >> n >> m;
    //�Է��� ������� �־����Ƿ� string���� ����Ѵ�. string������ ������ �ε����� �� ���ھ� ������ �� �����Ƿ� ���� char�� 2���� ���ͷ� �ٲ� �ʿ䰡 ����.
    vector<string> matrix_a(n);
    vector<string> matrix_b(n);
    for (int i = 0; i < n; i++)
        cin >> matrix_a[i];

    for (int i = 0; i < n; i++)
        cin >> matrix_b[i];

    //����
    int ans = 0; //�ٲٴ� Ƚ��
    for (int i = 0; i <= n - 3; i++) { //���� ����: reverseMtx�Լ����� 3��, 3���� ���ϹǷ� ���⼭�� i�� n-3�ε�������
        for (int j = 0; j <= m - 3; j++) { //j�� m-3�ε������� �ݺ����� �����Ѵ�.
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)���Ұ� ���� �ٸ��ٸ�
                reverseMtx(i, j, matrix_a); //3*3�� �����´�.
                ans++; //�ٲٴ� Ƚ�� 1 ����
            }
        }
    }

    //���
    if (!isPossible(n, m, matrix_a, matrix_b)) //���������� �� ����� ���Ұ� ��� ������ Ȯ���ϰ�
        ans = -1; //�ٸ��� ���� -1
    cout << ans; //������ ���� �ٲ� Ƚ���� �ȴ�. �̰��� ����Ѵ�.

    return 0;
}
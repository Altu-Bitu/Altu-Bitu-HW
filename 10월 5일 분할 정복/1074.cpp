#include <iostream>

using namespace std;

int ans = 0; //Ƚ��
bool found = false; //�����غ��� : �� ������ ���ٸ� ��� �ǳ���?

void divide(int r, int c, int row, int col, int size) {
    //Conquer : ã�� ��ġ�� ������
    if (row == r && col == c) { //ã�� ��ġ
        found = true; //ã�Ҵ�! - ����
        return; //����
    }
    if (found) //?
        return;

    //Combine : (r, c)���� ���� Ž���ϴ� ������ ���� ����
    if (r < row || r >= row + size || c < col || c >= col + size) { //�� ��и� �ȿ� (r, c)�� ���� �� - r�� c������ �Ǵ�
        ans += size * size; //(r, c) �տ� (size * size)���� ���Ұ� ����
        //z�� ���� ������ ���簢���̹Ƿ� size*size�� �����������Ѵ�.
        //cout << row << ' ' << col << ' ' << size << '\n'; //���ذ� ��ƴٸ� ����غ���
        return;
    }

    //Divide : 4���� ��и����� ������
    int next_size = size / 2; //2^n�� 4���� ��и����� ������ 2^(n-1) �� size/2
    for (int i = 0; i <= next_size; i += next_size) {
        for (int j = 0; j <= next_size; j += next_size)
            divide(r, c, row + i, col + j, next_size); //�������� ������ ������ 4�и����� ������.
    }
}

/**
 * 1. ���� 4��� �ϱ�
 * 2. z�� ���¿� ���� 1->2->3->4 ��и� ������ Ž��
 * 3. ���� sub-��и��� (r, c)�� ������ �Ѿ��, �� ��и��� (r, c)���� ���� Ž���ϴ� ��и� (�ֱ׷��� �����غ���)
 *    sub-��и��� ũ��� (sub-size * sub-size)�̹Ƿ� (r, c) �տ� �׸�ŭ�� ���Ұ� ����
 */
int main() {
    int n, r, c;

    //�Է�
    cin >> n >> r >> c;

    //����
    divide(r, c, 0, 0, 1 << n); //2^n�� 1<<n���� ǥ����
    //���
    cout << ans;
}
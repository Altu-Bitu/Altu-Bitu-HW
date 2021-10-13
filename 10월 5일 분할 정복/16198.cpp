#include <iostream>
#include <vector>

using namespace std;

vector<int> w;
int ans;

void backtracking(int sum) { //��Ʈ��ŷ �̿� - ����ġ��, ����:sum
    if (w.size() == 2) { //������ ������ 2�� -> �� �̻� �� �� ����
        ans = max(ans, sum); //�ִ��� ������
        return;
    }
    for (int i = 1; i < w.size() - 1; i++) { //ó���� ������ ���� �Ұ��̹Ƿ�
        int temp_w = w[i]; //���� ����
        int sum_w = w[i - 1] * w[i + 1]; //���� ������
        w.erase(w.begin() + i); //������ ���� ���� ������ ����.
        backtracking(sum + sum_w); //�� ��츶�� ������ ���� ��� ���ؼ� ������.
        w.insert(w.begin() + i, temp_w); //���� backtracking���� return�� ��� �ٸ� ���� �Ѿ�� ���ؾ��ϹǷ� erase �ߴ� �� insert�ϱ�
    }
}

/**
 * ������ ��� ��츦 ���ؼ� �������
 * �̶�, ����� �������� ���� ������ �� �Ŀ� �迭���� �����, �ٽ� ���ƿ��� �� ������ ���� �迭�� �ִ´�.
 */
int main() {
    int n;

    //�Է�
    cin >> n;
    w.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    //����
    backtracking(0); //��� ��� ���ؼ� �ִ� ã��
/* 7
 * 2 2 7 6 90 5 9
 * i=1
 * temp_w = w[1] = 2
 * sum_w = w[0]*w[2]=14
 * erase: 2 7 6 90 5 9
 * backtracking(0+2);
 *  i=1
 *  temp_w = w[1] = 7
 *  sum_w = 12
 *  w: 2 6 90 5 9
 *  backtracking(2+12)
 *      i=1
 *      temp_w = w[1] = 6
 *      sum_w = 180
 *      w: 2 90 5 9
 *      backtracking(14+180)
 *          i=1
 *          temp_w = w[1] = 90
 *          sum_w = 10
 *          w: 2 5 9
 *          backtracking(194+10)
 *              i=1
 *              temp_w = w[1] = 5
 *              sum_w = 18
 *              w: 2 9
 *              backtracking(204+18)
 *                  ans = 222
 *                  return;
 *              w: 2 5 9
 *          w: 2 90 5 9
 *          i=2
 *          temp_w = w[2] = 5
 *          sum_w = 90*9 = 810
 *          w: 2 90 9
 *          backtracking(194 + 810)
 *              i=1
 *              temp_w = w[1] = 90
 *              sum_w = 18
 *              w: 2 9
 *              backtracking(1004+18)
 *              ans = 1022
 *              return;
 *      i=2
 *      temp_w = w[2] = 90
 *      sum_w = 30
 *      w: 2 6 5 9
 *      ...
 *
 *
 *
 */
    //���
    cout << ans << '\n';

    return 0;
}
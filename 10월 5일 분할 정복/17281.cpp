#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> innings; //��ü �̴� ���� �Է� �޾Ƽ� ������ 2���� ����
vector<int> order(10, 0); //Ÿ��
vector<bool> check(10, false); //index+1�� Ÿ�ڰ� ���ߵǾ��°��ƴѰ�
int n, ans;

//���� ��ġ�� ����
int calcScore() {
    int score = 0; //�� ����
    int idx = 1; //Ÿ�� ����� order �ε��� ��ȣ
    for (int i = 0; i < n; i++) { //i: �̴�
        vector<bool> baseman(4, 0); //�� ������� ������ �ִ��� - Ȩ, 1��, 2��, 3�� - 4��
        int out = 0; //�ƿ� ���� ī��Ʈ - 3�̸� �ش� �̴� ����
        while (out < 3) { //�ƿ� ���� ī��Ʈ - 3�̸� �ش� �̴� ����
            int state = innings[i][order[idx++]]; //���� ������ ���� ���� - 0,1,2,3,4
            if (idx == 10) //9�������� ������ �����Ƿ� 10���� �� 1������ �ǵ���
                idx = 1;
            switch (state) {
                case 0: //�ƿ�
                    out++; //�ƿ�ī��Ʈ ����
                    break;
                case 1: //��Ÿ, 1�羿 ����
                    score += baseman[3]; //3�翡 �ִ� �����ִٸ� Ȩ ����
                    for (int i = 3; i > 0; i--)
                        baseman[i] = baseman[i - 1]; //�������ִ� ������ �� ĭ�� ����
                    baseman[1] = 1; //���ο� ���� 1�翡 ����
                    break;
                case 2: //2��Ÿ, 2�羿 ����
                    score += baseman[3] + baseman[2]; //3��, 2�翡 ���� �ִٸ� Ȩ ����
                    baseman[3] = baseman[1]; //1�� -> 3�� �̵�
                    baseman[2] = 1; //���ο� ���� 2�翡 ����
                    baseman[1] = 0; //�ʱ�ȭ - 1�翡 ��� ������
                    break;
                case 3: //3��Ÿ, 3�羿 ����
                    for (int i = 3; i > 0; i--) { //3��, 2��, 1�翡 ���� �ִٸ� Ȩ ����
                        score += baseman[i]; //1,2,3�翡 �ִ� ����� �� Ȩ ��
                        baseman[i] = 0; //1,2,3�翡 �ִ� ����� �� Ȩ ��
                    }
                    baseman[3] = 1; //���ο� ���� 3�翡 ����
                    break;
                case 4: //Ȩ��
                    for (int i = 3; i > 0; i--) { //3��, 2��, 1�翡 ���� �ִٸ� Ȩ ����
                        score += baseman[i]; //��� Ȩ ��
                        baseman[i] = 0; //��� ��ġ�� ���� ������
                    }
                    score++; //���ο� ������ Ȩ �ٷ� ����
                    break;
            }
        }
    }

    return score; //�� ���� ��ȯ
}

//������ ��ġ ��� ���ϱ� - �տ� �̴� ������ �� ���� �̴� ���� �������µ� �̰��� array�Լ��� ���ڷ� �޴´�.
void array(int cnt) { //cnt: Ÿ�ڼ���
    if (cnt == 4) { //4�� Ÿ�ڴ� ������ �����Ƿ�
        array(cnt + 1); //cnt �� ���� ����
        return;
    }
    if (cnt == 10) { //9�� Ÿ�ڱ��� ������ (��������)
        int score = calcScore(); //���� ���
        ans = max(ans, score); //�ִ� ���� ���ϱ�
        return;
    }
    for (int i = 2; i <= 9; i++) {
        if (!check[i]) {
            order[cnt] = i; //cnt�� Ÿ��: i�� ����
            check[i] = true; //i�� ���� ���� ������
            array(cnt + 1); //���� Ÿ��
            check[i] = false; //array(cnt+1) ������ false�� ���� ���·� �ǵ���.
        }
    }
}

/**
 * ���� + ���Ʈ ����, ��Ʈ��ŷ
 * 1. �켱 ������ Ÿ���� ��� ���Ѵ�. (�̶�, 4�� Ÿ�ڴ� �׻� 1�� �������� ��) (���Ʈ ����, ��Ʈ��ŷ)
 * 2. ���� Ÿ���� ���� ������ ������ ���ϸ� �ִ� ������ �����Ѵ�. (����)
 */

int main() {
    //�Է�
    cin >> n;
    innings.assign(n, vector<int>(10, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> innings[i][j];
        }
    }

    //����
    order[4] = 1; //4�� Ÿ�ڴ� 1�� ����
    check[1] = true; //1�� ������ ���� ������
    array(1); //������ ��ġ ��� ���ϱ�

    //���
    cout << ans << '\n';

    return 0;
}
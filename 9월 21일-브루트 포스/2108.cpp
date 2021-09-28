#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //����� �ִ�

int calcMode(vector<int> &frequency) {//��Ȳ�� �´� �ֺ� ����
    int max_value = 0;  //�ֺ��� �󵵼�
    for (int i = 0; i <= SIZE * 2; i++) { //�ֺ��� �󵵼� ���ϱ�, ������ 4000�����̹Ƿ� i�� 8000���ϱ��� ����.
        if (frequency[i] > max_value)
            max_value = frequency[i];
    }
    //�� ��°�� ���� �ֺ� ���ϱ�
    int cnt = 0;  //�ֺ� ����
    int mode = 0; //�ֺ�
    for (int i = 0; i <= SIZE * 2; i++) { //0~8000���� ����
        if (frequency[i] == max_value) { //�ֺ󰪰� frequency[i]�� ���� ��
            mode = i - SIZE; //SIZE�� ���� ������ �ε����� �����߾����Ƿ� ���� ���� SIZE�� ���־�� ��
            cnt++; //cnt 1 ����
            if (cnt == 2) //cnt==2, ��, �ֺ��� �� ���̴�. -> �� ��°�� ���� �ֺ�
                break; //�ֺ󰪰� ���� �󵵷� ������ ���� �� ���ٰ� �ϴ��� �� ��°�� ���� �ֺ󰪸� �˸� �ǹǷ� �̶� break
        }
    }

    return mode; //��Ȳ�� �´� �ֺ� ����
}

/**
 * 1. ������ ��� �� �Ǽ� �ڷ������� ������ �� �ݿø��ϴ°� ����
 * 2. n�� Ȧ���̹Ƿ� �߾Ӱ��� �׻� (n / 2)��° �ε���
 * 3. �ֺ��� ������ �󵵼� ������ �� ��°�� '����' ����
 * 4. �ֺ��� �����ϰ� �ϳ��� �ִ� ��� ���
 */

int main() {
    int n; //n�� Ȧ��

    //�Է�
    cin >> n;

    vector<int> num(n); //�ԷµǴ� ��ü ���� ����
    vector<int> frequency(SIZE * 2 + 1, 0); //�ε����� �Է� �� + 4000�� ��. ���� 0 ~ 8000. �� �ε����� �ش� ���� �󸶳� ���Դ��� ����
    //������ �� ���� �������� �˰���� ���� �ε������� 4000�� ������Ѵ�.
    //�ε������� 0���� ����� ���� �� �����Ƿ� 4000�� �����ִ� ���̴�.

    double sum = 0; //��� ���ϱ� ���� �� ����
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += (double) num[i]; //��
        frequency[num[i] + SIZE]++; //�� ���ڿ� 4000�� ���� �ε����� frequency ����
    }

    //����
    sort(num.begin(), num.end()); //���� -> �߾Ӱ� �� ���� ���ϱ� ����

    //���
    cout << round(sum / n) << '\n';                //������
    cout << num[n / 2] << '\n';                    //�߾Ӱ�
    cout << calcMode(frequency) << '\n';           //�ֺ�
    cout << num[num.size() - 1] - num[0] << '\n';  //����

    return 0;
}
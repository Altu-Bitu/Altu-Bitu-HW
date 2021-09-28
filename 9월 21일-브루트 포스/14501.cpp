#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //���ð��� ������ pair�� ���� ���� ci��� �θ���� ����. (typedef �̿�)

int ans; //����: �ִ� ����

//���� �� �ִ� �ִ� ���� �����ϴ� �Լ�, cnt: ��� ���� ������ ��, sum: ���ݱ����� ����
void maxConsul(int n, vector<ci> &consulting, int start, int sum) {
    //����: https://engkimbs.tistory.com/49
    //vector�� �ٸ� vector�� ������ �� ��� ��Ҹ� �����ϹǷ� ������� �߻�
    //&�� ���� �޸𸮸� �����ϴ� ����� �ǹǷ� ���� �ð��� ���� ���.


    if (start > n) //��� ������ ���� ������� �Ѵ´ٸ� -> ����� �� ���� ���
        return; //����� �� ������ ���̻� ����� �� �����Ƿ� return

    ans = max(ans, sum); //�ִ� ���� ���

    for (int i = start; i < n; i++) //i��° ���� ����ϴ� ���
        maxConsul(n, consulting, i + consulting[i].first, sum + consulting[i].second);
    //����Լ� �̿��Ͽ��� start���� n-1�ϱ��� ���ϴ� ���� ��� ��츦 �����Ͽ� �ִ� ������ ����ϵ��� �Ѵ�.00
    //�Ϲ� �ݺ������δ� �����ϱ� �����. ����Լ� ����ϱ�!
}

/**
* [���]
 * ����� ������ ���� ��, ���� �� �ִ� �ִ� ������ ���ϴ� ���α׷�
 *
 * [Ǯ��]
 * 1�� ���� ���޴� ��쿡�� �����ؼ� �� �� �ִ� ��� ����� ���� �� �غ���
 * n = 15 �̹Ƿ�, ����� �ϴµ� �ʿ��� �Ⱓ�� ��� 1���̶� �����ϸ� �ִ� ���� Ƚ����
 * -> C(15,1) + C(15,2) + ... + C(15,15) <= C(15,7) * 15 = 96,525 �̹Ƿ� ����� ���Ʈ ���� ���� ����!
 */

int main() {
    int n; //������ ���� ��

    //�Է�
    cin >> n;
    vector<ci> consulting(n); //vector�� �ڷ����� ������ typedef�� ���� ci�� �ϰ�, vector�� ũ�⸦ n���� ���Ѵ�.

    for (int i = 0; i < n; i++)
        cin >> consulting[i].first >> consulting[i].second; //first: ��� �ð�, second: ����

    //����
    maxConsul(n, consulting, 0, 0);
    //�ε���:0, sum:0�� ���¿��� �����Ѵ�. �������� ������ ����Լ��� ��� ���� ��� ��츦 �����ϸ� �ִ� ������ ans�� ����Ѵ�.

    //�ִ� ���� ans ���
    cout << ans << '\n';

    return 0;
}
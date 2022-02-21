#include <iostream>
#include <cmath>

using namespace std;

//�׻� x >= y �̹Ƿ� ��Ұ��踦 üũ���� ����
int calcGCD(int x, int y) {
    int tmp;
    while (y != 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    return x;
}

/**
 * �ִ������� G, �ּҰ������ L �̶�� ����.
 * G*L = A*B �̰�
 * A = G*a, B = G*b�� ��Ÿ�� �� �ִ�.
 * �̿� ���� G*L = G*G*a*b�� �� �� �ְ� �̸� �����ϸ�
 * L/G = a*b �̴�.
 *
 * A+B�� �ּҰ� �Ƿ���, a+b�� �ּҰ� �Ǿ�� �ϰ�, �׷��� ���ؼ� a, b�� ���̰� �ּҿ��� �Ѵ�.
 */
int main() {
    int gcd, lcm;

    //�Է�
    cin >> gcd >> lcm;

    //����
    int ab = lcm / gcd;
    int a = -1, b = -1;
    for (int i = sqrt(ab); i > 0; i--) { //a, b�� ���̰� ���� ���� �����ٺ��� üũ
        if (ab % i != 0)
            continue;
        //i�� ab�� ������
        int tmp_a = i, tmp_b = ab / i;
        //�� ���� ���μ����� üũ -> ���� �� ���� ���μҰ� �ƴ϶�� �� ���� �ִ������� gcd�� �� �� ����
        if (calcGCD(tmp_b, tmp_a) == 1) { 
            a = tmp_a;
            b = tmp_b;
            break;
        }
    }

    //���
    cout << a * gcd << ' ' << b * gcd;
}
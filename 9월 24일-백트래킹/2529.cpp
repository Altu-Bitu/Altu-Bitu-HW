#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 10;

int k; //�ε�ȣ ����
bool is_find; //ã�Ҵ�, ��ã�Ҵ�.
vector<char> op(SIZE); //�ε�ȣ ����
vector<int> arr(SIZE), num(SIZE);  //�� ��° �ڸ��� � ���ڿ����� ǥ���� ����, ����� k���� ���� ������ ����
vector<bool> check(SIZE); //�ش� ���ڰ� �������� �� �������� ������ ����

//������ ���ڿ��� �ٲٴ� �Լ�
string arrToString(vector<int> &arr) {
    string result;
    for (int i = 0; i <= k; i++)
        result += (arr[i] + '0'); //����->����
    return result; //����->���ڿ� ����
}

//���������� ���� ���ɼ� �ִ� ������ üũ�ϴ� �Լ�
bool promising(int idx) {
    //false �� ���
    if (op[idx] == '<' && arr[idx] > arr[idx + 1]) //�ε�ȣ�� '<'�ε� ���ڴ� '>'������ ��
        return false;
    if (op[idx] == '>' && arr[idx] < arr[idx + 1]) //�ε�ȣ�� '>'�ε� ���ڴ� '<'������ ��
        return false;
    return true; //�������� true
}

//�ִ� or �ּڰ� ���ϴ� ��Ʈ��ŷ �Լ� (num�迭�� ���� ����)
void findValue(int cnt) {
    //���� 2�� �̻��� ��ġ�ƴٸ�, �ش� ���ڰ� �־��� �ε�ȣ �����ϴ��� �˻�, �������� ������ �ٷ� ���� (����ġ��)
    if (cnt >= 2 && !promising(cnt - 2))
        return;
    if (cnt == k + 1) { //�ε�ȣ �����ϴ� ���� ã�� (��������)
        is_find = true; //ã�Ҵ� ǥ��
        return;
    }
    for (int i = 0; i <= k; i++) { //num[i]: �ִ��̸� 9 ~ (9-k), �ּڰ��̸� 0 ~ k
        if (!check[num[i]]) { //num[i]�� ������ �ʾҴٸ�
            check[num[i]] = true; //num[i]�� check true�� �ٲٰ�
            arr[cnt] = num[i]; //cnt��° �ڸ��� num[i]�� ��ġ�ϵ����Ѵ�.
            findValue(cnt + 1); //cnt+1 �ڸ��� ���� ã�� ���� �ڱ��Լ��� �����Ѵ�.
            if (is_find) //���ڿ��� ������ �� ã�Ҵ�.
                return; //����
            check[num[i]] = false; //���� ������ ���� num[i]�� check�� false�� �ʱ�ȭ���ش�.
            arr[cnt] = 0; //���� ������ ���� cnt��° �ڸ� ���� 0���� �ʱ�ȭ���ش�.
        }
    }
}

/**
 * [��Ʈ��ŷ Ǯ��] (0ms)
 * ���� �ߺ����� ��ġ�� (N�� M(1)�� ����)
 * ���� ��ġ�� ������ �ش� ���� �� �� ���� �ε�ȣ ���踦 �����ϴ��� Ȯ��, �������� ������ back (����ġ��)
 */

int main() {
    string max_num, min_num; //����

    //�Է�
    cin >> k; //�ε�ȣ ����
    for (int i = 0; i < k; i++) { //�ε�ȣ �Է�
        cin >> op[i];
    }

    //�ִ� ����
    for (int i = 0; i <= k; i++) //num�迭�� �� �̸� ����
        num[i] = 9 - i; //�ִ��� 9���� (9-k)���� ���ڷ� �̷����
    findValue(0); //�ִ� ã��
    max_num = arrToString(arr); //�ִ� ����

    //�ʱ�ȭ !����! �������� ��� �� �ʱ�ȭ ���Ա� ����� �� üũ����
    is_find = false; //�� ã�Ҵٰ� �ʱ�ȭ
    check.assign(SIZE, false); //check�迭 false�� �ʱ�ȭ
    arr.assign(SIZE, 0); //cnt��° �ڸ� �� ǥ���� �迭 0���� �ʱ�ȭ

    //�ּڰ� ����
    for (int i = 0; i <= k; i++)
        num[i] = i; //�ּڰ��� 0���� k���� ���ڷ� �̷����
    findValue(0); //�ּڰ� ã��
    min_num = arrToString(arr); //�ּڰ� ����

    //���
    cout << max_num << '\n' << min_num;

    return 0;
}
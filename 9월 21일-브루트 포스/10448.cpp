#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeTriangularNum(vector<int> v){//�ﰢ�� ���� ���Ϳ� ����
    for (int i = 1; i <= 44; i++) {
        v.push_back(i * (i + 1) / 2);
    }
}

bool triangularSum(vector<int> v, int num) //��� ����� �ﰢ�� ���� ���
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                if (v[i] + v[j] + v[k] == num)
                    return true;
            }
        }
    }
    return false;
}


int main() {
    vector<int> v;
    int t, k;
    cin >> t;

    makeTriangularNum(v); //�ﰢ���� ���� ����
    for (int i = 0; i < t; i++) {
        cin >> k;

        bool result = triangularSum(v, k);
        cout<<result<<'\n';
        //result���� true�̸� 1��, false�̸� 0���� ��µ�. ���ڷ� �ٲ� �ʿ� ����.
    }
}
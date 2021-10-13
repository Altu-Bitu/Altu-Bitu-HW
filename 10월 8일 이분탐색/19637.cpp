#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, string>> v;

void finding(){ //�̺� Ž�� �̿��ؼ� Īȣ ã�� �Լ�
    for (int i = 0; i < m; i++) {
        int power;
        cin >> power;

        int left = 0;
        int right = n-1;
        int mid;
        while (left < right) { //�������̹Ƿ� right�� ��������
            mid = (left+right)/2;

            if(power <= v[mid].first){ //~���� ~�ʰ� ������ �����Ƿ� right=mid -1�� �ƴ� right=mid�� �ۼ��Ѵ�.
                right = mid;
            }
            else if(power > v[mid].first){
                left = mid + 1;
            }
        }
        cout<<v[right].second<<'\n'; //right�� string���� �������.

    }
}

int main() {
    ios::sync_with_stdio(false); //�� 2�� �ڵ�
    cin.tie(NULL); //�� ���� �ð��ʰ� ���.

    cin >> n >> m;
    v.assign(n,pair<int, string> (-1, ""));
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }

    //�񳻸����� ����: ������ ���Ұ� �ٷ� �տ� �ִ� ���Һ��� ũ�ų� ���� ���

    finding();

}


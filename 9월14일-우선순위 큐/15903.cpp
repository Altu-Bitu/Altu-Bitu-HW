#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<long long> v; //���� ũ�Ⱑ ũ�Ƿ� long long���� �����ϴ� ���� ����.
    long long answer=0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        long long num;
        cin>> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end()); //�������� ����

    for(int i=0; i<m; i++){
        long long r = v[0]+v[1]; //���� ���� �� 2�� �̾Ƽ� ���ϱ�
        v[0]=r;//���� �� �����ϱ�
        v[1]=r;//���� �� �����ϱ�

        sort(v.begin(), v.end()); //�ٽ� ����
    }

    for(int i=0; i<n; i++){
        answer += v[i];
    }

    cout<<answer;
}

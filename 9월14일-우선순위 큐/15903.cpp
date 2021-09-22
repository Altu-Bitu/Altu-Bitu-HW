#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    priority_queue <long long, vector<long long>, greater<>> pq; //���� ũ�Ⱑ ũ�Ƿ� long long���� ����
    long long answer=0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        long long num;
        cin>> num;
        pq.push(num);
    }
    //�켱���� ť�̹Ƿ� �ڵ����� �������� ���� - greater �����Ƿ�

    for(int i=0; i<m; i++){
        long long a = pq.top(); //���� ���� �� 2�� �̾Ƽ� ���ϱ�
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long r = a+b;
        pq.push(r);//���� �� �����ϱ�
        pq.push(r);//���� �� �����ϱ�

    }

    for(int i=0; i<n; i++){
        answer += pq.top();
        pq.pop();
    }

    cout<<answer;
}

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main(){
    int n, m;
    priority_queue <long long, vector<long long>, greater<>> pq; //수의 크기가 크므로 long long으로 선언
    long long answer=0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        long long num;
        cin>> num;
        pq.push(num);
    }
    //우선순위 큐이므로 자동으로 오름차순 정렬 - greater 썼으므로

    for(int i=0; i<m; i++){
        long long a = pq.top(); //가장 작은 것 2개 뽑아서 더하기
        pq.pop();
        long long b = pq.top();
        pq.pop();
        long long r = a+b;
        pq.push(r);//더한 값 저장하기
        pq.push(r);//더한 값 저장하기

    }

    for(int i=0; i<n; i++){
        answer += pq.top();
        pq.pop();
    }

    cout<<answer;
}

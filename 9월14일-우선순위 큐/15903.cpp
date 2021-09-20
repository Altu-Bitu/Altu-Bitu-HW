#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m;
    vector<long long> v; //수의 크기가 크므로 long long으로 선언하는 것이 좋다.
    long long answer=0;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        long long num;
        cin>> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end()); //오름차순 정렬

    for(int i=0; i<m; i++){
        long long r = v[0]+v[1]; //가장 작은 것 2개 뽑아서 더하기
        v[0]=r;//더한 값 저장하기
        v[1]=r;//더한 값 저장하기

        sort(v.begin(), v.end()); //다시 정렬
    }

    for(int i=0; i<n; i++){
        answer += v[i];
    }

    cout<<answer;
}

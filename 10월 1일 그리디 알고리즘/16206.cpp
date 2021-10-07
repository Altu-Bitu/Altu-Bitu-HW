#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//길이 10인 롤케익 최대 개수 구하는 함수
int rollcake(vector<int> &v, int n, int m){
    int cnt=0; //롤케익 개수
    sort(v.begin(), v.end()); //일단 정렬

    //10의 배수가 앞쪽에 오름차순 정렬이 되어있어야 최대 개수가 나온다.
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n; j++){
            if(v[j]%10==0 && v[i]%10!=0)
                swap(v[i],v[j]);
        }
    }

    for(int i=0; i<n; i++){
        while(m>0 && v[i]>10){ //자를 수 있는 횟수 남아있고 롤케익의 길이가 10 초과일 때
            v[i]=v[i]-10;
            cnt++;
            m--;
        }
        if(v[i]==10) //길이가 10이라면 자르지 않고 롤케익 개수만 증가
            cnt++;
        if(m==0) //자를 수 있는 횟수가 0이라면 더 이상 진행이 불필요하므로 break
            break;
    }
    return cnt; //cnt 리턴
}

int main(){
    vector<int> v;
    int n,m;
    cin>>n>>m;
    v.assign(n,0);

    //입력
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //출력
    int answer = rollcake(v,n,m);
    cout<<answer;
}

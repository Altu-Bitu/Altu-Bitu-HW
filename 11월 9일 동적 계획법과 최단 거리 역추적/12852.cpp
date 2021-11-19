#include <iostream>

using namespace std;

int dp[1000001]; //해당 인덱스를 1로 만드는 최소 연산 횟수 저장 (dp[현재 지점]=dp[이전 지점]+1)
int path[1000001]; //다음 경로 저장 (연산 적용 후의 인덱스 저장) 

int make_one(int n){

    dp[1]=0; //1에서 1: 횟수는 0

    for(int i=2; i<=n; i++){
        //3번 연산 - 일단 dp에 값을 넣어놔야 1,2번 연산 시작 가능(비교) - 기본 연산으로 3번 연산 수행
        dp[i]=dp[i-1]+1; 
        path[i]=i-1;
        
        if(i%3==0){ //1번 연산
            if(dp[i]>dp[i/3]+1){  
                dp[i]=dp[i/3]+1;
                path[i]=i/3;
            }
        }

        if(i%2==0){ //2번 연산
            if(dp[i]>dp[i/2]+1){
                if(dp[i]>dp[i/2]+1){
                    dp[i]=dp[i/2]+1;
                    path[i]=i/2;
                }
            }
        }  
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;

    int num = make_one(n); //최소 횟수 연산 
    cout<<num<<'\n';

    for(int i=n; i>=1; i=path[i]){ //경로 출력
        cout<<i<<' ';
    }
}
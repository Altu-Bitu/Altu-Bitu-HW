#include <iostream>

using namespace std;

//n-1의 계단 수의 끝자리에서 +1, -1한 것이 붙은 것이 n의 계단 수이다. (끝자리가 1~8인 경우)
//끝자리가 0인 경우, 끝자리 +1
//끝자리가 9인 경우, 끝자리 -1

long long stairNum(int n){
    long long dp[101][10]; //전체 자리 수(1~100), 끝자리 수(0~9)
    long long num=0; //계단 수의 개수

    dp[1][0]=0;
    for(int i=1; i<=9; i++)
        dp[1][i] = 1; //한 자리 수-끝자리 수가 i인 수 1개씩 있음
    for(int i=2; i<=n; i++){ //i자리 수
        dp[i][0] = dp[i-1][1]%1000000000;
        dp[i][9] = dp[i-1][8]%1000000000;
        for(int j=1; j<=8; j++)
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
    }

    //n자리 수에서 계단 수의 개수
    for(int i=0; i<=9; i++){
        num += dp[n][i];
    }

    num %= 1000000000;

    return num;
}

int main(){
    int n;
    cin>>n;
    long long result = stairNum(n);
    cout<<result;
}


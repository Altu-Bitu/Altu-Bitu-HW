#include <iostream>

using namespace std;

//n-1�� ��� ���� ���ڸ����� +1, -1�� ���� ���� ���� n�� ��� ���̴�. (���ڸ��� 1~8�� ���)
//���ڸ��� 0�� ���, ���ڸ� +1
//���ڸ��� 9�� ���, ���ڸ� -1

long long stairNum(int n){
    long long dp[101][10]; //��ü �ڸ� ��(1~100), ���ڸ� ��(0~9)
    long long num=0; //��� ���� ����

    dp[1][0]=0;
    for(int i=1; i<=9; i++)
        dp[1][i] = 1; //�� �ڸ� ��-���ڸ� ���� i�� �� 1���� ����
    for(int i=2; i<=n; i++){ //i�ڸ� ��
        dp[i][0] = dp[i-1][1]%1000000000;
        dp[i][9] = dp[i-1][8]%1000000000;
        for(int j=1; j<=8; j++)
            dp[i][j] = (dp[i-1][j-1]+dp[i-1][j+1])%1000000000;
    }

    //n�ڸ� ������ ��� ���� ����
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


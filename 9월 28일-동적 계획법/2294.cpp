#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int knapsackCoin(int n, int k, vector<int> &coin) {
    vector<int> dp(k + 1, INF); //dp 벡터, INF로 초기화

    dp[0] = 0; //0가치를 만드는 경우 초기화
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) { //!생각해보기! 배낭 문제에서의 1차원 dp구현과 다른 점은?
            if (dp[j - coin[i]] != INF)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            /*3 15
             * 1
             * 5
             * 12
             * 입력 되었을 때
             * dp[1-1]=dp[0]=0!=INF -> dp[1]=min(dp[1], dp[0]+1)=min(INF,1)=1
             * dp[2-1]=1!=INF -> dp[2] = min(dp[2], dp[1]+1) = 2
             * ...
             * dp[15-1]=14!=INF -> dp[15] = 15
             *
             * dp[5-5]=0!=INF -> dp[5]=min(dp[5], dp[5-5]+1)=min(5,1)=1
             * dp[6-5]=1!=INF -> dp[6]=min(dp[6], dp[6-5]+1)=min(6,2)=2
             * dp[10-5]=5!=INF -> dp[10]=min(dp[10], dp[10-5]+1)=min(10,1+1)=2
             * dp[15]=dp[15-5]+1=dp[10]+1=3
             * dp[15-12]=min(dp[15], dp[3]+1)=3
             * 구하고자하는 k에서 이번 동전만큼의 값을 빼고(동전 개수는 +1) 그 차액을 만들 동전의 최소 개수를 구한다.
             */
        }
    }

    if (dp[k] == INF)
        return -1; //불가능한 경우 -1 리턴
    return dp[k];
}

/**
 * 배낭 문제(12865)와 유사
 * 현재 가치를 만드는 동전 개수의 최솟값 저장
 * = max(기존 값, [현재 가치 - 현재 사용하려는 동전 가치]의 동전 개수 최솟값 + 1)
 *
 * !주의! 최솟값을 찾는 문제이므로 dp 배열 초기화 중요
 * !주의! 배낭 문제와 다르게, 꼭 현재 가치를 정확하게 만드는 경우만 검사해야함
 */

int main() {
    int n, k; //n가지 종류의 동전, k원이 되게 해라

    //입력
    cin >> n >> k;
    vector<int> coin(n, 0); //n가지 종류의 동전 값 저장할 벡터
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    //연산 + 출력
    cout << knapsackCoin(n, k, coin) << '\n';

    return 0;
}
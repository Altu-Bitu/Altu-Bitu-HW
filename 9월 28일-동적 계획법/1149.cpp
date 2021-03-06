#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e6 + 1; //(1000*1000+1)=(최대비용 * 최대N + 1)

vector<vector<int>> cost;

int paintDp(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));//2차원 벡터, i번째 집이 xx색일 때, i번째 집 칠할 때까지의 비용 합 저장 - dp 값 저장

    //i번째 집을 각각의 색으로 칠하는 최소 비용
    for (int i = 1; i <= n; i++) {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]); //빨간색으로 칠할 때, i-1이 초록색 or 파란색인 경우 중 dp 최솟값 + i를 빨간색으로 칠하는 비용
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]); //초록색으로 칠할 때, i-1이 빨간색 or 파란색인 경우 중 dp 최솟값 + i를 초록색으로 칠하는 비용
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]); //파란색으로 칠할 때, i-1이 빨간색 or 초록색인 경우 중 dp 최솟값 + i를 파란색으로 칠하는 비용
    }

    int ans = INF; //리턴할 값, 정답
    for (int i = 0; i < 3; i++)
        ans = min(ans, dp[n][i]); //n번째 집을 빨간색으로 칠하는 비용, 초록색으로 칠하는 비용, 파란색으로 칠하는 비용 중 최솟값을 답으로 리턴한다.

    return ans;
}

/**
 * 앞 뒤의 집의 색이 서로 달라야 한다.
 * 1번 집부터 시작해서 이전 집과 다른 색을 계속 골라주면 자동으로 앞 뒤 집의 색이 서로 달라진다
 * 따라서, 각 집에 대해 각각 3가지 색을 선택한 경우의 최솟값을 계속 저장하며 풀자
 *
 * dp[i][빨간색] = min(dp[i-1][초록색], dp[i-1][파란색]) + 비용[i][빨간색]
 * dp[i][초록색] = min(dp[i-1][빨간색], dp[i-1][파란색]) + 비용[i][초록색]
 * dp[i][파란색] = min(dp[i-1][빨간색], dp[i-1][초록색]) + 비용[i][파란색]
 */

int main() {
    int n;

    //입력
    cin >> n;
    cost.assign(n + 1, vector<int>(3, 0)); //비용 저장할 2차원 벡터 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> cost[i][j];
        }
    }

    //연산 + 출력
    cout << paintDp(n) << '\n';

    return 0;
}
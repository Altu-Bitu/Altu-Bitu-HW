#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;

int knapsackCoin(int n, int k, vector<int> &coin) {
    vector<int> dp(k + 1, INF); //dp ����, INF�� �ʱ�ȭ

    dp[0] = 0; //0��ġ�� ����� ��� �ʱ�ȭ
    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) { //!�����غ���! �賶 ���������� 1���� dp������ �ٸ� ����?
            if (dp[j - coin[i]] != INF)
                dp[j] = min(dp[j], dp[j - coin[i]] + 1);
            /*3 15
             * 1
             * 5
             * 12
             * �Է� �Ǿ��� ��
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
             * ���ϰ����ϴ� k���� �̹� ������ŭ�� ���� ����(���� ������ +1) �� ������ ���� ������ �ּ� ������ ���Ѵ�.
             */
        }
    }

    if (dp[k] == INF)
        return -1; //�Ұ����� ��� -1 ����
    return dp[k];
}

/**
 * �賶 ����(12865)�� ����
 * ���� ��ġ�� ����� ���� ������ �ּڰ� ����
 * = max(���� ��, [���� ��ġ - ���� ����Ϸ��� ���� ��ġ]�� ���� ���� �ּڰ� + 1)
 *
 * !����! �ּڰ��� ã�� �����̹Ƿ� dp �迭 �ʱ�ȭ �߿�
 * !����! �賶 ������ �ٸ���, �� ���� ��ġ�� ��Ȯ�ϰ� ����� ��츸 �˻��ؾ���
 */

int main() {
    int n, k; //n���� ������ ����, k���� �ǰ� �ض�

    //�Է�
    cin >> n >> k;
    vector<int> coin(n, 0); //n���� ������ ���� �� ������ ����
    for (int i = 0; i < n; i++)
        cin >> coin[i];

    //���� + ���
    cout << knapsackCoin(n, k, coin) << '\n';

    return 0;
}
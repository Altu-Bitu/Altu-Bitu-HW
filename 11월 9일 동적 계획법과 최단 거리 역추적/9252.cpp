#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
//상, 좌, 좌상향
int dr[3] = {-1, 0, -1};
int dc[3] = {0, -1, -1};

//역추적
string back(string str1, vector<vector<int>> &path) {
    string result = "";
    int r = n, c = m;
    while (path[r][c] != -1) { //숫자가 들어가있는 path배열에서 동작
        int d = path[r][c]; //방향
        //좌상향에서 가져온 경우 -> str1[r - 1] == str2[c - 1] ->같은 숫자 중에 좌상향에 있는 숫자위치에 LCS에 해당하는 문자가 있다.
        //그림 참고: https://eochodevlog.tistory.com/65
        if (d == 2) 
            result += str1[r - 1]; //lcs에 해당하는 문자
        r += dr[d]; //역추적
        c += dc[d]; //역추적
    }
    reverse(result.begin(), result.end());
    return result;
}

//LCS 길이 구하는 함수
int lcs(string str1, string str2, vector<vector<int>> &path) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0)); //(i,j)좌표까지 lcs길이 저장
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (str1[i - 1] != str2[j - 1]) { //두 문자가 서로 다르면
                dp[i][j] = dp[i - 1][j]; //우선 위쪽 값 가져온 것으로 저장
                path[i][j] = 0; //경로(방향) 저장 - 상
                if (dp[i][j] < dp[i][j - 1]) { //왼쪽이 더 크다면
                    dp[i][j] = dp[i][j - 1]; //큰 것으로 길이 갱신
                    path[i][j] = 1; //경로(방향) 저장 - 좌
                }
            } else if (str1[i - 1] == str2[j - 1]) { //두 문자가 서로 같다면 ->LCS 증가
                dp[i][j] = dp[i - 1][j - 1] + 1; //길이 증가 갱신
                path[i][j] = 2; //경로(방향) 저장 -좌상
            }
        }
    }
    return dp[n][m]; //LCS 길이 리턴
}

/**
 * 기본 문제: LCS (해당 풀이는 "08. 동적계획법.pdf" 참고)
 *
 * [역추적]
 * - 위쪽, 왼쪽, 좌상향 중 어느 방향에서 왔는지 경로를 저장한 후, 역추적하는 문제
 * - 경로 저장은 dp배열이 갱신될 때 함
 *
 * 해당 풀이는 인덱스를 편하게 관리하기 위해 dp와 path 배열을 (1, 1)부터 시작
 */

int main() {
    string str1, str2;

    //입력
    cin >> str1 >> str2;
    n = str1.length();
    m = str2.length();
    vector<vector<int>> path(n + 1, vector<int>(m + 1, -1)); //그 전 방향 저장하는 배열

    //연산
    int ans = lcs(str1, str2, path); //lcs (길이)
    string result = back(str1, path); //역추적 (lcs 해당 문자열)

    //출력
    cout << ans << '\n' << result << '\n'; //길이, lcs문자열
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

//부분 행렬 원소 뒤집는 함수
void reverseMtx(int row, int col, vector<string> &matrix_a) {
    for (int i = row; i < row + 3; i++) { //3*3행렬 비교 하므로 3행
        for (int j = col; j < col + 3; j++) { //3열씩 확인
            if (matrix_a[i][j] == '1') //1이면
                matrix_a[i][j] = '0'; //0으로
            else //0이면
                matrix_a[i][j] = '1'; //1로 바꾸기
        }
    }
}

//마지막으로 A == B인지 확인하는 함수
int isPossible(int n, int m, vector<string> &matrix_a, vector<string> &matrix_b) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix_a[i][j] != matrix_b[i][j]) //하나라도 다르면 false 리턴
                return false;
        }
    }

    return true; //다 동일한 경우
}

/**
 * (0, 0) 인덱스부터 부분행렬을 만들 수 있는 마지막 인덱스까지 검사하며 그리디하게 푸는 문제
 * A, B 행렬의 현재 인덱스 값이 서로 다르다면 A 행렬에서 현재 인덱스로 '시작'하는 3x3 크기만큼의 부분 행렬 원소 뒤집기
 * 검사가 모두 끝난 후, A와 B가 서로 다르다면 바꿀 수 없는 경우임
 * !주의! 입력이 공백없이 주어지므로 string으로 받음
 */

int main() {
    int n, m;

    //입력
    cin >> n >> m;
    //입력이 공백없이 주어지므로 string형을 사용한다. string형으로 받으면 인덱스로 한 글자씩 접근할 수 있으므로 굳이 char형 2차원 벡터로 바꿀 필요가 없다.
    vector<string> matrix_a(n);
    vector<string> matrix_b(n);
    for (int i = 0; i < n; i++)
        cin >> matrix_a[i];

    for (int i = 0; i < n; i++)
        cin >> matrix_b[i];

    //연산
    int ans = 0; //바꾸는 횟수
    for (int i = 0; i <= n - 3; i++) { //범위 조심: reverseMtx함수에서 3행, 3열씩 비교하므로 여기서는 i는 n-3인덱스까지
        for (int j = 0; j <= m - 3; j++) { //j는 m-3인덱스까지 반복문을 실행한다.
            if (matrix_a[i][j] != matrix_b[i][j]) { //(i, j)원소가 서로 다르다면
                reverseMtx(i, j, matrix_a); //3*3씩 뒤집는다.
                ans++; //바꾸는 횟수 1 증가
            }
        }
    }

    //출력
    if (!isPossible(n, m, matrix_a, matrix_b)) //마지막으로 두 행렬의 원소가 모두 같은지 확인하고
        ans = -1; //다르면 답은 -1
    cout << ans; //같은면 답은 바꾼 횟수가 된다. 이것을 출력한다.

    return 0;
}
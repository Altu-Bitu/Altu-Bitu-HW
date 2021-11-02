#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//좋은 수인지 검사하는 함수(투 포인터)
bool isGood(vector<int> &num, int left, int right, int idx) {
    while (left < right) { 
        if (left == idx) { //left가 현재 수 위치와 같은 경우
            left++; //현재 수 위치 오른쪽으로 넘어가서 검사
            continue;
        }
        if (right == idx) { //right가 현재 수 위치와 같은 경우
            right--; //현재 수 위치 왼쪽으로 넘어가서 검사
            continue;
        }

        if (num[left] + num[right] == num[idx]) //좋은 수 조건
            return true; //true 리턴

        if (num[left] + num[right] > num[idx]) //만드려는 수보다 크다면 (정렬되어있는 상태이므로)
            right--; //right 왼쪽으로
        else //작다면 
            left++; //left 오른쪽으로 
    }
    return false; //false 리턴
}

/**
 * 1. 각 수마다 양 쪽 끝에서 포인터를 시작해서 좁혀오면서 어떤 '다른 두 수'가 현재 수를 만들 수 있는지 검사
 * 2. 포인터를 차례로 옮기며 검사하기 위해 미리 수를 오름차순 정렬함
 * 3. 현재 만드려는 수의 위치와 left, right 포인터 위치가 겹칠 경우 처리 주의
 */

int main() {
    int n, ans = 0;

    //입력
    cin >> n;
    vector<int> num(n, 0);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    //연산
    sort(num.begin(), num.end()); //정렬 필수!
    for (int i = 0; i < n; i++) {
        if (isGood(num, 0, n - 1, i)) //투 포인터 이용 연산
            ans++; //좋은 수 존재하면 ans 증가
    }

    //출력
    cout << ans << '\n';

    return 0;
}
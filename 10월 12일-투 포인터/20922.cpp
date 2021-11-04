#include <iostream>
#include <vector>

using namespace std;
const int MAX = 100000; //원소의 최댓값

int findLen(vector<int> &arr, int n, int k) {
    vector<int> cnt(MAX + 1, 0); //각 원소 등장 횟수 저장하는 배열 - 등장 횟수로 길이 연장 가능한지 판별해야함

    int ans = 0, left = 0, right = 0;  //최장 연속 부분 수열의 길이, 수열의 맨 왼쪽 위치, 수열의 맨 오른쪽 위치

    //left는 항상 right의 왼쪽 또는 같은 위치에 있어야 함
    while (left <= right && right < n) { //right도 범위 내에 있어야함
        if (cnt[arr[right]] + 1 <= k) { //현재 right가 가리키는 원소를 포함해도 등장 횟수가 k번 이하이면
            cnt[arr[right]]++; //길이 증가
            ans = max(ans, (right - left) + 1); //최장 연속 부분 수열의 길이 갱신
            right++; //오른쪽으로 한 칸 더 옮겨보기 
        } else { //현재 right가 가리키는 원소를 포함하면 등장 횟수가 k번을 초과
            cnt[arr[left]]--; //길이를 하나 줄이고
            left++; //left를 오른쪽으로 옮기기
        }
    }
    return ans; //최장 연속 부분 수열의 길이 리턴
}

/**
 * 1. 최장 연속 부분 수열의 '길이'를 구해야 함 -> 구간 내의 모든 원소를 고려하기 때문에 한쪽에서 시작하는 투 포인터
 * 2. 각 원소의 최댓값이 100,000이기 때문에 배열로 등장 횟수 체크할 수 있음
 * 3. right를 옮기고 바로 원소를 추가했던 기존 방법과 달리, 일단 포인터만 옮겨놓고 원소를 추가해도 되는지 확인
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k; //수열의 길이, 같은 원소가 k개 이하
    vector<int> arr(n, 0); //수열 저장 
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //연산 & 출력
    cout << findLen(arr, n, k);
}
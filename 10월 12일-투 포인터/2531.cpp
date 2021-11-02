#include <iostream>
#include <vector>

using namespace std;

int chooseSushi(vector<int> &belt, int n, int d, int k, int c) {
    vector<int> sushi(d + 1, 0); //초밥 각 번호(인덱스)별 개수 저장

    //쿠폰으로 먹은 초밥
    int section_sushi = 1; //현재 가짓수: 1
    sushi[c]++; //쿠폰으로 먹은 초밥-> 가짓수 하나 증가

    //윈도우 초기화
    //연속으로 먹은 초밥 개수: k
    for (int i = 0; i < k; i++) {
        sushi[belt[i]]++; //해당 번호의 초밥의 개수 증가
        if (sushi[belt[i]] == 1) //해당 번호의 초밥의 개수가 1이 된다면 새로운 종류가 들어온 것이므로
            section_sushi++; //현재 가짓수 증가
    }

    int ans = section_sushi;
    int left = 0, right = k - 1;
    do { //원형태로 윈도우를 옮겨야 하기 때문에 종료조건은 left가 초기값(=0)이 됐을 때
        sushi[belt[left]]--; //left위치에서 하나 이동 -> 개수 하나 감소
        if (!sushi[belt[left]]) //해당 종류의 초밥이 윈도우에 없다면
            section_sushi--; //현재 가짓수 감소

        //윈도우의 양 끝 이동
        left = (left + 1) % n; //모듈러 연산
        right = (right + 1) % n; //모듈러 연산

        sushi[belt[right]]++; //right위치에서 하나 이동 -> 개수 하나 증가
        if (sushi[belt[right]] == 1) //새로운 종류가 들어오면
            section_sushi++; //현재 가짓수 증가

        ans = max(ans, section_sushi);
    } while (left); //left가 0이되면 종료
    return ans; //최대 가짓수 리턴
}

/**
 * 1. 연속해서 먹어야 할 접시가 k로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * 3. 쿠폰으로 먹은 초밥을 먼저 고려해놓기
 * 4. 초밥의 종류가 최대 3000개로 많지 않음. 보석 쇼핑 문제처럼 각 종류별 먹은 초밥의 개수를 세어주기
 */
int main() {
    int n, d, k, c;

    //입력
    cin >> n >> d >> k >> c;
    vector<int> belt(n, 0); //벨트 위의 초밥 저장
    for (int i = 0; i < n; i++)
        cin >> belt[i];

    //연산 & 출력
    cout << chooseSushi(belt, n, d, k, c);
}
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //상담시간과 이익을 pair로 묶은 것을 ci라고 부르기로 하자. (typedef 이용)

int ans; //정답: 최대 이익

//얻을 수 있는 최대 이익 리턴하는 함수, cnt: 상담 시작 가능한 날, sum: 지금까지의 이익
void maxConsul(int n, vector<ci> &consulting, int start, int sum) {
    //참고: https://engkimbs.tistory.com/49
    //vector를 다른 vector에 대입할 때 모든 요소를 복사하므로 오버헤드 발생
    //&를 쓰면 메모리를 참조하는 방식이 되므로 수행 시간이 적게 든다.


    if (start > n) //상담 끝나는 날이 퇴사일을 넘는다면 -> 상담할 수 없는 경우
        return; //상담할 수 없으면 더이상 계산할 것 없으므로 return

    ans = max(ans, sum); //최대 이익 계산

    for (int i = start; i < n; i++) //i번째 날을 상담하는 경우
        maxConsul(n, consulting, i + consulting[i].first, sum + consulting[i].second);
    //재귀함수 이용하여서 start부터 n-1일까지 일하는 동안 모든 경우를 조사하여 최대 이익을 계산하도록 한다.00
    //일반 반복문으로는 구현하기 어려움. 재귀함수 사용하기!
}

/**
* [퇴사]
 * 상담을 적절히 했을 때, 얻을 수 있는 최대 수익을 구하는 프로그램
 *
 * [풀이]
 * 1일 부터 상담받는 경우에서 시작해서 할 수 있는 모든 경우의 수를 다 해보자
 * n = 15 이므로, 상담을 하는데 필요한 기간이 모두 1일이라 가정하면 최대 연산 횟수는
 * -> C(15,1) + C(15,2) + ... + C(15,15) <= C(15,7) * 15 = 96,525 이므로 충분히 브루트 포스 접근 가능!
 */

int main() {
    int n; //퇴사까지 남은 날

    //입력
    cin >> n;
    vector<ci> consulting(n); //vector의 자료형을 위에서 typedef로 정한 ci로 하고, vector의 크기를 n으로 정한다.

    for (int i = 0; i < n; i++)
        cin >> consulting[i].first >> consulting[i].second; //first: 상담 시간, second: 이익

    //연산
    maxConsul(n, consulting, 0, 0);
    //인덱스:0, sum:0인 상태에서 시작한다. 기저조건 전까지 재귀함수가 계속 돌며 모든 경우를 조사하며 최대 이익인 ans를 계산한다.

    //최대 이익 ans 출력
    cout << ans << '\n';

    return 0;
}
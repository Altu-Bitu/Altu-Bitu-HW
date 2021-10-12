#include <iostream>
#include <vector>

using namespace std;

vector<int> w;
int ans;

void backtracking(int sum) { //백트래킹 이용 - 가지치기, 인자:sum
    if (w.size() == 2) { //에너지 구슬이 2개 -> 더 이상 고를 수 없음
        ans = max(ans, sum); //최댓값을 답으로
        return;
    }
    for (int i = 1; i < w.size() - 1; i++) { //처음과 마지막 선택 불가이므로
        int temp_w = w[i]; //현재 구슬
        int sum_w = w[i - 1] * w[i + 1]; //현재 에너지
        w.erase(w.begin() + i); //문제에 따라 현재 구슬을 없앰.
        backtracking(sum + sum_w); //각 경우마다 에너지 값을 모두 구해서 비교하자.
        w.insert(w.begin() + i, temp_w); //위의 backtracking에서 return한 경우 다른 경우로 넘어가서 비교해야하므로 erase 했던 값 insert하기
    }
}

/**
 * 가능한 모든 경우를 구해서 계산하자
 * 이때, 사용한 에너지는 따로 저장해 둔 후에 배열에서 지우고, 다시 돌아왔을 때 저장한 값을 배열에 넣는다.
 */
int main() {
    int n;

    //입력
    cin >> n;
    w.assign(n, 0);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    //연산
    backtracking(0); //모든 경우 비교해서 최댓값 찾기
/* 7
 * 2 2 7 6 90 5 9
 * i=1
 * temp_w = w[1] = 2
 * sum_w = w[0]*w[2]=14
 * erase: 2 7 6 90 5 9
 * backtracking(0+2);
 *  i=1
 *  temp_w = w[1] = 7
 *  sum_w = 12
 *  w: 2 6 90 5 9
 *  backtracking(2+12)
 *      i=1
 *      temp_w = w[1] = 6
 *      sum_w = 180
 *      w: 2 90 5 9
 *      backtracking(14+180)
 *          i=1
 *          temp_w = w[1] = 90
 *          sum_w = 10
 *          w: 2 5 9
 *          backtracking(194+10)
 *              i=1
 *              temp_w = w[1] = 5
 *              sum_w = 18
 *              w: 2 9
 *              backtracking(204+18)
 *                  ans = 222
 *                  return;
 *              w: 2 5 9
 *          w: 2 90 5 9
 *          i=2
 *          temp_w = w[2] = 5
 *          sum_w = 90*9 = 810
 *          w: 2 90 9
 *          backtracking(194 + 810)
 *              i=1
 *              temp_w = w[1] = 90
 *              sum_w = 18
 *              w: 2 9
 *              backtracking(1004+18)
 *              ans = 1022
 *              return;
 *      i=2
 *      temp_w = w[2] = 90
 *      sum_w = 30
 *      w: 2 6 5 9
 *      ...
 *
 *
 *
 */
    //출력
    cout << ans << '\n';

    return 0;
}
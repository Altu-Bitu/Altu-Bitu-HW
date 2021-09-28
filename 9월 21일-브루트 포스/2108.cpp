#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int SIZE = 4000; //양수의 최댓값

int calcMode(vector<int> &frequency) {//상황에 맞는 최빈값 리턴
    int max_value = 0;  //최빈값의 빈도수
    for (int i = 0; i <= SIZE * 2; i++) { //최빈값의 빈도수 구하기, 절댓값이 4000이하이므로 i는 8000이하까지 돈다.
        if (frequency[i] > max_value)
            max_value = frequency[i];
    }
    //두 번째로 작은 최빈값 구하기
    int cnt = 0;  //최빈값 개수
    int mode = 0; //최빈값
    for (int i = 0; i <= SIZE * 2; i++) { //0~8000까지 조사
        if (frequency[i] == max_value) { //최빈값과 frequency[i]가 같을 때
            mode = i - SIZE; //SIZE를 더한 값으로 인덱스에 저장했었으므로 실제 값은 SIZE를 빼주어야 함
            cnt++; //cnt 1 증가
            if (cnt == 2) //cnt==2, 즉, 최빈값이 두 개이다. -> 두 번째로 작은 최빈값
                break; //최빈값과 같은 빈도로 나오는 것이 더 많다고 하더라도 두 번째로 작은 최빈값만 알면 되므로 이때 break
        }
    }

    return mode; //상황에 맞는 최빈값 리턴
}

/**
 * 1. 산술평균 계산 시 실수 자료형으로 맞춰준 후 반올림하는거 주의
 * 2. n은 홀수이므로 중앙값은 항상 (n / 2)번째 인덱스
 * 3. 최빈값은 동일한 빈도수 내에서 두 번째로 '작은' 값임
 * 4. 최빈값이 유일하게 하나만 있는 경우 고려
 */

int main() {
    int n; //n은 홀수

    //입력
    cin >> n;

    vector<int> num(n); //입력되는 전체 숫자 저장
    vector<int> frequency(SIZE * 2 + 1, 0); //인덱스는 입력 수 + 4000의 값. 따라서 0 ~ 8000. 각 인덱스에 해당 수가 얼마나 나왔는지 저장
    //실제로 그 수가 무엇인지 알고싶을 때는 인덱스에서 4000을 빼줘야한다.
    //인덱스에는 0포함 양수만 들어올 수 있으므로 4000을 더해주는 것이다.

    double sum = 0; //평균 구하기 위한 합 변수
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += (double) num[i]; //합
        frequency[num[i] + SIZE]++; //각 숫자에 4000을 더한 인덱스에 frequency 증가
    }

    //연산
    sort(num.begin(), num.end()); //정렬 -> 중앙값 및 범위 구하기 위해

    //출력
    cout << round(sum / n) << '\n';                //산술평균
    cout << num[n / 2] << '\n';                    //중앙값
    cout << calcMode(frequency) << '\n';           //최빈값
    cout << num[num.size() - 1] - num[0] << '\n';  //범위

    return 0;
}
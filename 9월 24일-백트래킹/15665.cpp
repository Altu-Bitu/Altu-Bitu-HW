#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7;

int n,m;
int arr[SIZE], result[SIZE];

void backtracking(int cnt){ //백트래킹 함수
    if(cnt==m){ //cnt가 m 즉, result배열의 크기가 m이 되면 m개의 숫자가 들어간 것이므로 출력하고 다음
        for(int i=0; i<cnt; i++)
            cout<<result[i]<<' ';
        cout<<'\n';
        return;
    }

    //이전에 골랐던 수와 비교해서 중복을 피해야한다.
    int pre = -1; //이전에 골랐던 수 저장할 변수

    for(int i=0; i<n; i++){
        if(pre != arr[i]){ //이전에 골랐던 수가 지금 고르는 수와 다르다면
            result[cnt] = arr[i]; //result배열에 넣고
            pre = arr[i]; //이전 수에 지금 고른 수 저장하고
            backtracking(cnt+1); //다음 cnt로 넘어가는 재귀함수
        }
    }
}

int main(){
    //입력
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    backtracking(0);
}

/* 4 2
 * 9 7 9 1
 * 입력 받는 경우
 *
 * arr={1,7,9,9}
 *
 * backtracking(0)
 * pre=-1
 * -1 != 1
 * result[0] = 1
 * pre = 1
 *
 * backtracking(1)
 * pre = -1
 * -1 != 1
 * result[1] = 1
 * pre = 1
 *
 * backtracking(2)
 * 기저조건에 걸리므로 (result[0], result[1])=(1,1) 출력하고 return
 *
 * backtracking(1)
 * pre = 1
 * 1 != 7
 * result[1] = 7
 * pre = 7
 * backtracking(2)
 * 기저조건에 걸리므로 (1,7) 출력하고 return
 *
 * backtracking(1)
 * pre = 7
 * 7 != 9
 * result[1] = 9
 * pre = 9
 * backtracking(2)
 * (1,9) 출력하고 return
 *
 * backtracking(1)
 * pre = 9
 * 9 == 9
 * 넘어감
 *
 * => arr[0](= 1)이 첫 번째 나올 때,
 * (1,1), (1,7), (1,9)
 * 나오고 arr[1](= 7)이 첫 번째 나오는 단계로 넘어감.
 *
 */

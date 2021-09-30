#include <iostream>

using namespace std;

const int SIZE = 10;
int n;
int w[SIZE][SIZE];
bool check[SIZE]={false};

int result=0;
int k,j;

/* 4
 * 0 10 15 20
 * 5 0 9 10
 * 6 13 0 12
 * 8 8 9 0
 *
 * 이라고 주어질 때
 * check[0][1][2][3]
 * 0행
 * check[0]=true 하고
 * 10, 15, 20 순서대로 탐색한다.
 * 10 - 0행 1열이므로 check[1]=true하고 result + 10, 1행으로 이동
 *      1행에서 check true된 0열, 1열 말고 2열(9) 탐색
 *      9 - 2열이므로 check[2]=true하고 result + 9, 2행으로 이동
 *          2행에서 check true된 0,1,2열 말고 3열(12)로 탐색
 *          12 -3열으므로 check[3]=true하고 result + 12, 3행으로 이동
 *          (3,0) 좌표값 더함. result + 8 =>결과 1=39(10,9,12,8)
 *          check[3]=false
 *      10 선택 - 3열로 이동
 *      9선택
 */

void backtracking(int cnt, int r){//백트래킹 함수
    if(cnt==n) {
        k = j;
        //cout<<"k: "<<k<<' '<<w[k][0]<<'\n';
        result += w[k][0];
        cout<<"result: "<<result<<'\n';
        return;
    }
    for(j=0; j<n; j++){

        if(r!=j && !check[j]){
            //cout<<"cnt: "<<cnt<<'\n';
            check[j]=true;
            result += w[r][j];
            //cout<<"Result: "<<result<<'\n';
            backtracking(cnt+1, j);
        }
    }

}

int main(){
    cin>>n;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    for(int i=0; i<n; i++) {
        result=0;
        check[i] = true;
        backtracking(1, i);

    }
    cout<<result;


}
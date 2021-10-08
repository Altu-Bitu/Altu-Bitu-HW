#include <iostream>
#include <vector>
#include <string>

using namespace std;

//마지막에 다 동일한지 확인하는 함수
 int isPossible(vector<string> &v1, vector<string> &v2, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v1[i][j]!=v2[i][j])
                return false;
        }
    }
    return true;
}

//다를 때 3*3 뒤집는 함수
void convert(vector<string> &v, int r, int c){
    for(int i=r; i<r+3; i++){ //변수 실수 하지 않기
        for(int j=c; j<c+3; j++){
            if (v[i][j] == '1')
                v[i][j] = '0';
            else
                v[i][j] = '1';
        }
    }
}
//연산
int matrix(vector<string> &v1, vector<string> &v2, int n, int m){
    int cnt=0;
    for (int i = 0; i <= n-3; i++) {
        for (int j = 0; j <= m-3; j++) {
            if(v1[i][j]!=v2[i][j]){
                convert(v1, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    //어차피 string은 인덱스로 한 글자씩 접근할 수 있으므로 굳이 char형 2차원 벡터로 선언하지 않고
    //string형 1차원 벡터로 선언한다.

    int n,m;
    cin>>n>>m;
    vector<string> v1(n);
    vector<string> v2(n);
    //입력
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }

    for(int i=0; i<n; i++){
        cin>>v2[i];
    }

    int answer = matrix(v1,v2,n,m);
    //다 뒤집고 마지막에 다 동일한지 확인
    if(!isPossible(v1,v2,n,m))
        answer=-1;
    cout<<answer;

}
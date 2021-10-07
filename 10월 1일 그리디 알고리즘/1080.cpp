#include <iostream>
#include <vector>
#include <string>

using namespace std;

void convert(vector<vector<char>> &v, int r, int c){ //다를 때 전환하는 함수
    for(int i=r; i<r+3; r++){
        for(int j=c; j<c+3; j++){
            if(v[i][j]=='1')
                v[i][j]='0';
            else
                v[i][j]='1';
        }
    }
}

int matrix(vector<vector<char>> &v1, vector<vector<char>> &v2, int n, int m){
    int cnt=0, i, j;
    bool flag=true;
    for (i = 0; i < n-3; i++) {
        for (j = 0; j < m-3; j++) {
            if(v1[i][j]!=v2[i][j]){
                convert(v1, i, j);
                convert(v2, i, j);
                cnt++;
            }

        }
        if(v1[i][m-1]!=v2[i][m-1]) {
            flag = false;
            break;
        }
    }

    if(!flag)
        return -1;

    flag=true;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(v1[i][j]!=v2[i][j])
                flag=false;
        }
    }

    if(!flag)
        return -1;

    return cnt;

}


int main(){
    vector<vector<char>> v1;
    vector<vector<char>> v2;
    vector<string> v;
    int n,m;
    cin>>n>>m;

    v1.assign(n, vector<char>(m,'0'));
    v2.assign(n, vector<char>(m,'0'));
    v.assign(2*n, "");
    //입력
    for(int i=0; i<2*n; i++){
        cin>>v[i];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            v1[i][j]=v[i][j];
        }
    }

    for(int i=n; i<2*n; i++){
        for(int j=0; j<m; j++){
            v2[i-n][j]=v[i][j];
        }
    }

    int answer = matrix(v1,v2,n,m);
    cout<<answer;
}
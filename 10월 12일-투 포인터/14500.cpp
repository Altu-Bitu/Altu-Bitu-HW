#include <iostream>
#include <vector>
using namespace std;
 
int place(vector<vector<int>> &v, int n, int m){
    int maxSum=0;
    
    //노란색
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-1; j++){
            int temp = v[i][j]+v[i+1][j]+v[i][j+1]+v[i+1][j+1];
            maxSum = max(maxSum, temp);
        }
    }
    
    //초록색-세로
    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int temp = v[i][j]+v[i+1][j]+v[i+1][j+1]+v[i+2][j+1];
            maxSum = max(maxSum, temp);
            temp = v[i+1][j]+v[i+2][j]+v[i][j+1]+v[i+1][j+1]; //대칭
            maxSum = max(maxSum, temp);
        }
    }

    //초록색-가로
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){
            int temp = v[i+1][j]+v[i+1][j+1]+v[i][j+1]+v[i][j+2];
            maxSum = max(maxSum, temp);
            temp = v[i][j]+v[i][j+1]+v[i+1][j+1]+v[i+1][j+2]; //대칭
            maxSum = max(maxSum, temp);
        }
    }

    //하늘색
    for(int i=0; i<n; i++){
        for(int j=0; j<m-3; j++){
            int temp = v[i][j]+v[i][j+1]+v[i][j+2]+v[i][j+3];//가로
            maxSum = max(maxSum, temp);
        }
    }
    for(int i=0; i<n-3; i++){
        for(int j=0; j<m; j++){
            int temp = v[i][j]+v[i+1][j]+v[i+2][j]+v[i+3][j]; //세로
            maxSum = max(maxSum, temp);
        }
    }


    //보라색과 주황색
    //양 끝 고려
    //가로
    for(int i=0; i<n-1; i++){
        for(int j=0; j<m-2; j++){//가로 블록 세 개 +아래
            int tr = v[i][j]+v[i][j+1]+v[i][j+2]; 
            int tr1 = tr+v[i+1][j];
            int tr2 = tr+v[i+1][j+1];
            int tr3 = tr+v[i+1][j+2];
            int tempr = max(tr1, tr2);
            tempr = max(tempr, tr3);
            maxSum = max(maxSum, tempr);
        }
    }

    for(int i=1; i<n; i++){
        for(int j=0; j<m-2; j++){
            int tr = v[i][j]+v[i][j+1]+v[i][j+2]; //가로 블록 세 개 +위
            int tr1 = tr+v[i-1][j];
            int tr2 = tr+v[i-1][j+1];
            int tr3 = tr+v[i-1][j+2];
            int tempr = max(tr1, tr2);
            tempr = max(tempr, tr3);
            maxSum = max(maxSum, tempr);
        }
    }
    //세로
    for(int i=0; i<n-2; i++){
        for(int j=1; j<m; j++){
            int tc = v[i][j]+v[i+1][j]+v[i+2][j]; //세로 블록 세 개 + 왼쪽
            int tc1 = tc+v[i][j-1];
            int tc2 = tc+v[i+1][j-1];
            int tc3 = tc+v[i+2][j-1];
            int tempc = max(tc1, tc2);
            tempc= max(tempc, tc3);
            maxSum = max(maxSum, tempc);
        }
    }

    for(int i=0; i<n-2; i++){
        for(int j=0; j<m-1; j++){
            int tc = v[i][j]+v[i+1][j]+v[i+2][j]; //세로 블록 세 개 +오른쪽
            int tc1 = tc+v[i][j+1];
            int tc2 = tc+v[i+1][j+1];
            int tc3 = tc+v[i+2][j+1];
            int tempc = max(tc1, tc2);
            tempc= max(tempc, tc3);
            maxSum = max(maxSum, tempc);
        }
    }

    return maxSum;
}

int main(){
    vector<vector<int>>v;
    int n,m;
    cin>>n>>m;
    v.assign(n, vector<int>(m));

    for(int i=0; i<n; i++){
       for(int j=0; j<m; j++){
            cin>>v[i][j];
        }
    }

    int answer = place(v, n, m);
    cout<<answer;
}
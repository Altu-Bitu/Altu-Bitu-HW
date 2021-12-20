#include <vector>
#include <iostream>

using namespace std;

vector<vector<char>> board(50, vector<char>(50,' '));
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool valid(int n, int a, int b){ //인접 범위 체크
    if(a<0 || b<0 || a>=n || b>=n){
        return false;
    }
    return true;
}

int countCandy(vector<vector<char>> &v, int n){ //연속된 사탕 개수 세는 함수
    int cnt=1;
    for(int j=0; j<n; j++){ //열 - 연속된 사탕 개수 세기
        int ccnt=1;
        for(int i=0; i<n-1; i++){
            if(v[i][j]==v[i+1][j]){
                ccnt++;
            }
            else{
                ccnt=1;
            }
            cnt = max(cnt, ccnt);
        }        
    }
    for(int i=0; i<n; i++){ //행 - 연속된 사탕 개수 세기
        int rcnt=1;
        for(int j=0; j<n-1; j++){
            if(v[i][j]==v[i][j+1]){
                rcnt++;
            }
            else{
                rcnt=1;
            }
            cnt = max(cnt, rcnt);
        }        
    }
    return cnt;
}

int maxCandy(int n){ // 최대 연속 사탕 개수 세기
    vector<vector<char>> cboard(50, vector<char>(50,' '));
    copy(board.begin(), board.end(), cboard.begin()); //벡터 복사(board->cboard로 복사)
    int res=countCandy(cboard,n); //처음 board의 최대 연속 사탕 개수 세기
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int t=0; t<4; t++){ //인접 좌표의 사탕 색깔이 다른 경우 swap하고 개수 세고 다시 swap해서 원래대로 돌려놓기
                int x = i + dx[t];
                int y = j + dy[t];
                if(valid(n,x,y)){
                    if(cboard[x][y]!=cboard[i][j]){
                        swap(cboard[x][y], cboard[i][j]);
                        res = max(res,countCandy(cboard, n));
                        swap(cboard[x][y], cboard[i][j]);
                    }
                }
            }
            
        }
    }
    return res;
}

int main(){
    int n;
    int answer;

    //입력
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }

    //연산
    answer = maxCandy(n);
    
    //출력
    cout<<answer;    
}
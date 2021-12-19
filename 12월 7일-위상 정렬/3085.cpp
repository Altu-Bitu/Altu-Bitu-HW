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

int countCandy(vector<vector<char>> &v, int n){
    int cnt=1;
    for(int j=0; j<n; j++){ //열
        int ccnt=1;
        for(int i=0; i<n-1; i++){
            if(v[i][j]==v[i+1][j]){
                ccnt++;
            }
        }
        cnt = max(cnt, ccnt);
    }
    for(int i=0; i<n; i++){ //행
        int rcnt=1;
        for(int j=0; j<n-1; j++){
            if(v[i][j]==v[i][j+1]){
                rcnt++;
            }
        }
        cnt = max(cnt, rcnt);
    }

    return cnt;
}

int maxCandy(int n){
    vector<vector<char>> cboard(50, vector<char>(50,' '));
    copy(board.begin(), board.end(), cboard.begin()); //벡터 복사
    int res=countCandy(cboard,n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int t=0; t<4; t++){
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

    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>board[i][j];
        }
    }
    answer = maxCandy(n);
    cout<<answer;    
}

/*
반례

6
CCYYCC
YYCCYY
CCYYCC
YYCCYY
CCYYCC
YYCCYY
답: 3
- 2로 나옴

40
YYYYYYYYYCYYYYYYYYYYYYYYYCZZZZZZZYYYYYZC
PYPCYZCPYCZZCCPZYYPZYYYYPPZZPYCCCZYZZZPY
ZPPCYCCPYYZYPPZCZPYCCCZZYYPZZPYPPPPZPCZC
ZCYYZZYCPPPCCYPYYPZZZZCCCCZZCZCYCYZCZZYC
PYZYZZCCZZCCPPYCZPYPPZYZYYYZZPPCCZYYYZCZ
PPPCZZPCCCCCCCCCCCCCCCCCCYCZYYYZCYYCPCPZ
PZYPZYPPYYYZZZPPPZPYZPYZCZZPYZCZZPPCYCCZ
YPPYYYYCCPYPZPCPPPCZCZZYZZZZYYZPZZCCCZYY
YPZCZCPZYYZCCPPPYPPCCPCYZYYYCPPPYCYYCPYC
ZPYZCCZCYZYYCPCCPPYYZPYCCPPCPZCCZCCZYYPY
CPPPCPZZZCYCPYCZYZZPYPZCYYCCZCZZPZYCPZCZ
YZYCYPCPPYPPPPYYYPYPCPCPZZPPCYZCZPZZZZYP
ZCZPYZPPYYYPYPCZYZZYZZPZCZPPPZYCZYPCPYYC
YPZPZYCCYPZZCCPYYCYZYYYYYCZYZZYZZPPYCZCZ
YCZPZCCCCCYCCCCCCCCCCCZYPYZPCZPZZPZZYPYY
YYYYYYYYYYPYYYYYYYYYYYYYYYYYYYYYYYYYYZZP
ZYZCZZCCZPZCZYCPYPCCPYZYCCPPZZCZYCZCYPYP
YYZYPZZYCPCYCZPZYCZPZCCZYCCCZZZYYYZYYPCP
YZZPZYPYCZCPPCZPYCCPYCYZPCCYYZYPCPPPYYPZ
YYZPPZYCZZZYYPYCYZCCYYZPYCCYPZCCZCCCYYZC
CYZZPPCZYZYCCPCYYCPZPPZZPCZZYZZYZZCZYYPC
PPZYZYZPZZZZYPZYYPZPPZPPZCYCPZYZPPYYYYYZ
CZZZYPZYCCYYYPPZYCYPZPCCPCYYYZZYCPYCYCYY
YCZZCZCCYPPYYZYYYPPPZZYYCCCYYZZZYZZZYYCC
YCZPZPPPZPCYYYZZYCPPZYPZYCZZZZZPYYPYCYPC
PCZZZYYZCPCPCZYYYCPYZCCPZCZPYZZPYPZPYZYY
ZZZZPPPPPYZCZCPYYCCCCCCCCCCCYCCCCCCPCCCP
CPYCYZCZCZCYCPCYYCYZCZYYZCCPZZYZPZCPYCCP
YZZYYZZZZPZZCZCYYCZZPYZYCCPCPZYCYCZPYZPZ
YZZZZZZZZZZZZZZZZZZZZZZZCZZZZZZZZZZZZZZZ
YZZPPPPPPPPPPPPPPCPPPPPYYCYCZZZCCPCCYPYZ
YYZCPYPPYZPPYCZPYCZPCPCZZZCYCZYZCPCPZPZZ
CYZPCYYYYYYYYYYYYCYYYYYYYYYYYZYYCYZYPYZC
CPZCCZZZZZZZZZZZZCZZZZZZZZZZYZCCZCPZZCCY
YYZPCPZZCYYYYYCPYCZPYYYPPZZCCZZCPPPPCCPP
YYZZPCCYZCCCYPCYYPZCZZZZZPPYZCCCCCZCPPCY
PYYYYYYYYYYYYYYYYYYYYYYPYCZZPPYZYPPPPYCC
YPZCZPZYPZPPCYCZYCYPCCCZCZZCCZYZYYCYYZCZ
CPPZZPCYYCCCYCCPZPYYZYCYZYZYPYCPPZPCPCYC
ZPCYPYZPPCYYPYZZZPPZZZCCPYCYPCYYCYPPYCZY
답: 37
-38로 나옴
*/
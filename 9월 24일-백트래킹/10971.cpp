#include <iostream>

using namespace std;

const int SIZE = 10;
int n;
int w[SIZE][SIZE];
bool check[SIZE]={false};

int result=0;
int k,j;

void backtracking(int cnt, int r){
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
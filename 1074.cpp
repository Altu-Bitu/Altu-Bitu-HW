#include <iostream>
#include <vector>

using namespace std;

//분할 정복
//divide: r,c가 어디에 있는지 기준으로 2차원 배열 나누기
//conquer: r,c 인덱스가 같은가
//combine: 순서 따지기
int n,r,c;

int divide(vector<vector<int>> &v, int size, int y, int x){
    //conquer: r,c 인덱스가 같은가
    if(y==r && x==c){
        //return ;
    }

    //divide: 2차원 배열 나누기
    //r,c가 어디에 있는지 판단



}

int main(){


    cin>>n>>r>>c;
    vector<vector<int>> v(2^n, vector<int>(2^n, 0));


}

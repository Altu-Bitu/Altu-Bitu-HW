#include<iostream>

using namespace std;

char arr[397][397];

void star(int num){
    for(int i=0; i<4*num-3; i++){
        arr[i][0]='*';
    }

}

int main(){
    int N;
    cin>>N;
    star(N);
}

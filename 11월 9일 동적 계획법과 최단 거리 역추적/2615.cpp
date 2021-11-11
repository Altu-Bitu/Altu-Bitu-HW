#include <iostream>

using namespace std;

int main(){
    int board[19][19];

    //바둑판 입력
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin>>board[i][j];
        }
    }
}
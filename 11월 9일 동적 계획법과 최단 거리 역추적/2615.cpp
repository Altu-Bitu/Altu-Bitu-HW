#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ci;

int main(){
    

    int board[19][19];
    bool visited[19][19]={false};

    //바둑판 입력
    for(int i=0; i<19; i++){
        for(int j=0; j<19; j++){
            cin>>board[i][j];
        }
    }

    for(int i=0; i<19; i++){ //우 5칸
        for(int j=0; j<15; j++){
            if(board[i][j]!=0){
                
                if(board[i][j+1]== board[i][j] && board[i][j+2]==board[i][j] && board[i][j+3]==board[i][j] && board[i][j+4]==board[i][j]){ //우
                    if(j<14 && board[i][j+5]==board[i][j]){
                        
                        continue;
                    }
                    else{
                        cout<<"우\n";
                        cout<<board[i][j]<<'\n'<<i+1<<' '<<j+1;
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=0; i<15; i++){ //하 5칸
        for(int j=0; j<19; j++){
            if(board[i][j]!=0){
                if(board[i+1][j]== board[i][j] && board[i+2][j]==board[i][j] && board[i+3][j]==board[i][j] && board[i+4][j]==board[i][j]){//하
                    if(i<14 && board[i+5][j]==board[i][j]){
                        
                        continue;
                    }
                    else{
                        cout<<"하\n";
                        cout<<board[i][j]<<'\n'<<i+1<<' '<<j+1;
                        return 0;
                    }
                }
            }
        }
    }

    for(int i=0; i<15; i++){ //우하 5칸
        for(int j=0; j<15; j++){
            if(board[i][j]!=0){
                if(board[i+1][j+1]== board[i][j] && board[i+2][j+2]==board[i][j] && board[i+3][j+3]==board[i][j] && board[i+4][j+4]==board[i][j]){ //우하
                    if(i<14 && j<14 && board[i+5][j+5]==board[i][j]){
                       
                        continue;
                    }
                    else{
                        cout<<"우하\n";
                        cout<<board[i][j]<<'\n'<<i+1<<' '<<j+1;
                        return 0;
                        
                    }
                }
            }
        }
    }

    //좌하 5칸
    for(int i=0; i<19; i++){
        for(int j=4; j<19; j++){
            if(board[i][j]!=0){
                if(board[i+1][j-1]== board[i][j] && board[i+2][j-2]==board[i][j] && board[i+3][j-3]==board[i][j] && board[i+4][j-4]==board[i][j]){ //좌하
                    if(j>4 && board[i+5][j-5]==board[i][j]){
                        ;
                        continue;
                    }
                    else{
                        cout<<"좌하\n";
                        cout<<board[i][j]<<'\n'<<i+1<<' '<<j+1;
                        return 0;
                    }
                }
            }
        }
    }

    cout<<0;
    return 0;


}
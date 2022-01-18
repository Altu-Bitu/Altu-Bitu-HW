#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> &board, vector<int> &moves){
    int bsize = board.size();
    int answer=0; //없어지는 인형 개수
    vector<int> position(bsize); //인형이 있는 끝위치(board에서 0이 아닌 곳 중에 가장 높은 수)
    stack<int> st; //뽑힌 인형이 들어갈 스택
    
    //각 줄의 인형이 있는 끝위치
    for(int i=0; i<bsize; i++){
        for(int j=0; j<bsize; j++){
            if(board[j][i]==0){
                position[i] = j+1;
            }
        }
    }

    //계산 편하게 하기 위해 인덱스 조정
    for(int i=0; i<moves.size(); i++){
        moves[i] = moves[i]-1;
    }

    //인형 뽑기
    for(int i=0; i<moves.size(); i++){
        int doll;
        if(position[moves[i]]<bsize){
            doll = board[position[moves[i]]][moves[i]];
            position[moves[i]]++;
        }
        else{ 
            continue;
        }

        if(st.empty() || doll!=st.top()){
            st.push(doll); 
        }
        else{ //같은 인형이면 없어짐
            answer += 2;
            st.pop();
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> board={{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> moves={1,5,3,5,1,2,1,4};

    int answer = solution(board, moves);
    cout<<answer;
}

//인형은 밑에서부터 쌓이고 위에서부터 뽑으니까 스택을 사용하면 되겠다고 생각함.
//vector<stack<int>> 이런 식으로 할까 했지만 에러 발생.
//각 인형이 있는 끝위치를 알아내서 그 위치를 활용하기로 함.
//조건문으로 board 크기를 체크
//stack으로 뽑은 인형과 stack의 top이 같은지 확인해서 없어지는 인형 개수 세기.
//2019 카카오 개발자 겨울 인턴십 문제
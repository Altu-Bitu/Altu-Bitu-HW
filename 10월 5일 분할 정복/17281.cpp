#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int idx=0;
int baseball(){
    vector<int> v; //해당 이닝 선수 정보
    vector<bool> pos; //홈, 1루, 2루, 3루에 선수가 있는지 담을 벡터
    int score=0; //이번 순열에서의 점수
    int outcnt=0; //아웃되는 선수 몇 명인지 - 3명이면 break
    v.assign(9,0);


    for(int i=0; i<9; i++){
        cin>>v[i];
    }
    sort(v.begin()+1, v.end()); //next_permutation이 모든 경우의 수를 돌려면 미리 오름차순 정렬을 해주어야함.
    while (next_permutation(v.begin()+1, v.end())){ //v[1]~v[8]에 대한 순열의 모든 경우의 수 확인
        score=0; //이번 순열의 점수
        pos.assign(4, false); //홈, 1루, 2루, 3루 false로 초기화

        while(true){

            int i = idx%8+1; //v[1]~v[8]까지 돌아가야하므로 idx를 이렇게 설정
            pos[0]=true;
            if(v[i]==0) {
                outcnt++;
                pos[0]=false;
            }
            if(outcnt==3) {
                idx=i+1;
                break;
            }

            if(v[i]==1){ //1루타
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //해당 베이스에 주자가 있다면
                        if(j==3){//3루에 주자가 있다면
                            pos[j]=false;
                            score++; //3루 주자 홈인 -> 점수 증가
                        }
                        else{
                            pos[j]=false; //지금 자리 빈 자리로 만들고
                            pos[j+1]=true; //한 칸 앞으로 뛰어
                        }
                    }
                }
            }
            else if(v[i]==2){//2루타
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //해당 베이스에 주자가 있다면
                        if(j==3 || j==2){
                            pos[j]=false;
                            score++; //3,2루 주자 홈인 -> 점수 증가
                        }
                        else{
                            pos[j]=false; //지금 자리 빈 자리로 만들고
                            pos[j+2]=true; //두 칸 앞으로 뛰어
                        }
                    }
                }
            }
            else if(v[i]==3){//3루타
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //해당 베이스에 주자가 있다면
                        if(j==3 || j==2 || j==1){
                            pos[j]=false;
                            score++; //3,2,1루 주자 홈인 -> 점수 증가
                        }
                        else{
                            pos[j]=false; //지금 자리 빈 자리로 만들고
                            pos[j+3]=true; //세 칸 앞으로 뛰어
                        }
                    }
                }
            }
            else{ //홈런
                for(int j=3; j>=0; j--){
                    if(pos[j]) {
                        pos[j] = false;
                        score++;
                    }
                }
            }
            if(i==3){ //3번 타자까지 했을 때 4번 타자인 1번 선수 계산
                if(v[0]==1){ //1루타
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //해당 베이스에 주자가 있다면
                            if(j==3){//3루에 주자가 있다면
                                pos[j]=false;
                                score++; //3루 주자 홈인 -> 점수 증가
                            }
                            else{
                                pos[j]=false; //지금 자리 빈 자리로 만들고
                                pos[j+1]=true; //한 칸 앞으로 뛰어
                            }
                        }
                    }
                }
                else if(v[0]==2){//2루타
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //해당 베이스에 주자가 있다면
                            if(j==3 || j==2){
                                pos[j]=false;
                                score++; //3,2루 주자 홈인 -> 점수 증가
                            }
                            else{
                                pos[j]=false; //지금 자리 빈 자리로 만들고
                                pos[j+2]=true; //두 칸 앞으로 뛰어
                            }
                        }
                    }
                }
                else if(v[0]==3){//3루타
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //해당 베이스에 주자가 있다면
                            if(j==3 || j==2 || j==1){
                                pos[j]=false;
                                score++; //3,2,1루 주자 홈인 -> 점수 증가
                            }
                            else{
                                pos[j]=false; //지금 자리 빈 자리로 만들고
                                pos[j+3]=true; //세 칸 앞으로 뛰어
                            }
                        }
                    }
                }
                else{ //홈런
                    for(int j=3; j>=0; j--){
                        if(pos[j]) {
                            pos[j] = false;
                            score++;
                        }
                    }
                }
            }
            idx++;
        }
    };

    return score;
}

int main(){
    int maxScore=0;
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        maxScore= max(maxScore, baseball());
    }

    cout<<maxScore;
}
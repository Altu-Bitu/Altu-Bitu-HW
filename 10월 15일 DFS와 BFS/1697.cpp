#include <iostream>
#include <queue>

using namespace std;
bool visited[100001]={false}; //방문 여부
queue <pair<int,int>> q; //<위치, 시간>

//bfs
int minTime(int n, int k){ //큐에 위치와 시간을 pair로 만들어서 넣은 큐의 front에서 갈 수 있는 모든 경우를 계산해서 조건 검사한 후에 다시 큐에 넣는다.
    int place, time;
    while(!q.empty()){

        place = q.front().first;
        time = q.front().second;
        q.pop();

        if(place == k){ //답인 경우
            break; //break하고 return
        }

        //조건: 위치가 범위 내에 있는가, 방문하지 않은 위치인가
        if(place-1>=0 && !visited[place-1]){ //-1로 움직였을 때 조건 체크
            q.push(make_pair(place-1, time+1)); //큐에 넣기
            visited[place-1]=true; //place-1 방문 체크
        }

        if(place+1<=100000 && !visited[place+1]){ //+1로 움직였을 때 조건 체크
            q.push(make_pair(place+1, time+1)); //큐에 넣기
            visited[place+1]=true; //place+1 방문 체크 
        }

        if(place*2<=100000 && !visited[place*2]){ //*2로 움직였을 때 조건 체크
            q.push(make_pair(place*2, time+1)); //큐에 넣기
            visited[place*2]=true; //place*2 방문 체크
        }
    }

    return time;
} 

int main(){
    int n, k;
    int cnt=0;
    cin>>n>>k; //수빈, 동생 위치

    q.push(make_pair(n,0)); //수빈 위치
    visited[n]=true; //방문 체크

    int answer= minTime(n,k); //연산

    cout<<answer;
    
}
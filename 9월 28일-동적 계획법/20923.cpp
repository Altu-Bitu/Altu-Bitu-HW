#include <iostream>
#include <deque>
#include <queue>
using namespace std;

string arr[2500001];


void game(deque<int> &dq1, queue<int> &q1, deque<int> &dq2, queue<int> &q2){
    int a=0,b=0;
    for(int i=0; i<2500000; i++){
        if(dq1.empty() || dq2.empty()) {
            if(dq1.empty()){
                arr[i]="su";
                //break;
            }
            else{
                arr[i]="do";
                //break;
            }
        }
        else{
            a=dq1.front();
            dq1.pop_front(); //도도의 덱에서 빼서
            q1.push(a); //그라운드에 넣기
            if(dq1.empty() || dq2.empty()) {
                if(dq1.empty()){
                    arr[i]="su";
                    return;
                }
                else{
                    arr[i]="do";
                    return;
                }
            }

            if(a==5){ //도도의 것이 5가 나왔을 때, 도도가 가져감
              for(int i=0; i<q2.size(); i++){ //수연 그라운드에 있던 카드들 다 가져가고
                    int st = q2.front();
                    q2.pop();
                    dq1.push_back(st);
              }

              for(int i=0; i<q1.size(); i++){ //자기 그라운드의 카드들 다 가져간다.
                int st = q1.front();
                    q1.pop();
                    dq1.push_back(st);
              }

            }

            if(a+b==5){
                for(int i=0; i<q1.size(); i++){ //도도 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);
                }
                for(int i=0; i<q2.size(); i++){ //자기 그라운드의 카드들 다 가져간다.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);
                }
            }

            b=dq2.front();
            dq2.pop_front();
            q2.push(b);
            if(dq1.empty() || dq2.empty()) {
                if(dq1.empty()){
                    arr[i]="su";
                    return;
                }
                else{
                    arr[i]="do";
                    return;
                }
            }

            if(b==5){ //수연이의 것이 5가 나왔을 때, 도도가 가져감
                for(int i=0; i<q2.size(); i++){ //수연 그라운드에 있던 카드들 다 가져가고
                    int st = q2.front();
                    q2.pop();
                    dq1.push_back(st);
                }

                for(int i=0; i<q1.size(); i++){ //자기 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq1.push_back(st);
                }

            }

            if(a+b==5){
                for(int i=0; i<q1.size(); i++){ //도도 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);
                }
                for(int i=0; i<q2.size(); i++){ //자기 그라운드의 카드들 다 가져간다.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);
                }
            }
        }
        if(dq1.size()>dq2.size())
            arr[i]="do";
        else if(dq1.size()<dq2.size())
            arr[i]="su";
        else
            arr[i]="dosu";
    }

}

int main(){
    int n,m;
    deque<int> ddq; //도도 덱
    queue<int> dground; //도도 그라운드
    deque<int> sdq; //수연 덱
    queue<int> sground; //수연 그라운드
    cin>>n>>m;

    //입력
    for(int i=0; i<n; i++){
        int a, b;
        cin>>a>>b;
        ddq.push_front(a);
        sdq.push_front(b);
    }

    game(ddq, dground, sdq, sground);
    cout<<arr[m-1];
}

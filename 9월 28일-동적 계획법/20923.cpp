#include <iostream>
#include <deque>
#include <queue>
using namespace std;

string game(int m, deque<int> &dq1, queue<int> &q1, deque<int> &dq2, queue<int> &q2){
    int a=0,b=0;
    int i;
    int cnt=0;
    for(i=0; i<m; i++){
        //cout<<"i: "<<i<<'\n';
        if(i%2==0) {
            if(dq1.empty())
               break;

            a = dq1.front();
            dq1.pop_front(); //도도의 덱에서 빼서
            q1.push(a); //그라운드에 넣기



            if (q1.back() == 5) { //도도의 것이 5가 나왔을 때, 도도가 가져감
                while(!q2.empty()) { //수연 그라운드에 있던 카드들 다 가져가고
                    int st = q2.front();
                    q2.pop();
                    dq1.push_back(st);

                }

                while(!q1.empty()) { //자기 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq1.push_back(st);

                }

            }

            if (!dq1.empty() && !dq2.empty() && !q1.empty() && !q2.empty() && q1.back() + q2.back() == 5) {
                while(!q1.empty()) { //도도 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);

                }
                while(!q2.empty()) { //자기 그라운드의 카드들 다 가져간다.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);

                }
            }
            if (dq1.empty() || dq2.empty()) {
              break;
            }
            ++cnt;
            //cout<<"do: "<<dq1.size()<<' '<<q1.size()<<'\n';
            //cout<<"su: "<<dq2.size()<<' '<<q2.size()<<'\n';
            //cout<<"cnt: "<<cnt<<'\n';
            if(cnt==m-1)
                break;

        }
        //cout<<"i: "<<i<<'\n';
        else {
            if(dq2.empty())
                break;

            b = dq2.front();
            dq2.pop_front();
            q2.push(b);

            if (dq1.empty() || dq2.empty()) {
                break;
            }

            if (q2.back() == 5) { //수연이의 것이 5가 나왔을 때, 도도가 가져감
                while(!q2.empty()) { //수연 그라운드에 있던 카드들 다 가져가고
                    int st = q2.front();
                    //cout<<"st: "<<st<<'\n';
                    q2.pop();
                    dq1.push_back(st);


                }

                while(!q1.empty()) { //자기 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    //cout<<"st: "<<st<<'\n';
                    q1.pop();
                    dq1.push_back(st);

                }

            }

            if (!dq1.empty() && !dq2.empty() && !q1.empty() && !q2.empty() && q1.back() + q2.back() == 5) {
                while(!q1.empty()) { //도도 그라운드의 카드들 다 가져간다.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);

                }
                while(!q2.empty()) { //자기 그라운드의 카드들 다 가져간다.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);

                }
            }
            if (dq1.empty() || dq2.empty()) {
               break;
            }
            ++cnt;
            //++i;
            //cout<<"i: "<<i<<'\n';
            //cout<<"do: "<<dq1.size()<<' '<<q1.size()<<'\n';
            //cout<<"su: "<<dq2.size()<<' '<<q2.size()<<'\n';
            //cout<<"m-1: "<<m-1<<'\n';
            //cout<<"cnt: "<<cnt<<'\n';
            if(cnt==m-1)
                break;
        }


    }
    if(dq1.size()>dq2.size()){
        return "do";
    }
    else if(dq1.size()<dq2.size()){
        return "su";
    }
    else{
        return "dosu";
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

    cout<<game(m,ddq, dground, sdq, sground);
    //cout<<arr[m-1];
    //cout<<"do: "<<ddq.size()<<' '<<dground.size()<<'\n';
    //cout<<"su: "<<sdq.size()<<' '<<sground.size()<<'\n';
}

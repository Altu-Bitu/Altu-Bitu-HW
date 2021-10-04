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
            dq1.pop_front(); //������ ������ ����
            q1.push(a); //�׶��忡 �ֱ�



            if (q1.back() == 5) { //������ ���� 5�� ������ ��, ������ ������
                while(!q2.empty()) { //���� �׶��忡 �ִ� ī��� �� ��������
                    int st = q2.front();
                    q2.pop();
                    dq1.push_back(st);

                }

                while(!q1.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq1.push_back(st);

                }

            }

            if (!dq1.empty() && !dq2.empty() && !q1.empty() && !q2.empty() && q1.back() + q2.back() == 5) {
                while(!q1.empty()) { //���� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);

                }
                while(!q2.empty()) { //�ڱ� �׶����� ī��� �� ��������.
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

            if (q2.back() == 5) { //�������� ���� 5�� ������ ��, ������ ������
                while(!q2.empty()) { //���� �׶��忡 �ִ� ī��� �� ��������
                    int st = q2.front();
                    //cout<<"st: "<<st<<'\n';
                    q2.pop();
                    dq1.push_back(st);


                }

                while(!q1.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    //cout<<"st: "<<st<<'\n';
                    q1.pop();
                    dq1.push_back(st);

                }

            }

            if (!dq1.empty() && !dq2.empty() && !q1.empty() && !q2.empty() && q1.back() + q2.back() == 5) {
                while(!q1.empty()) { //���� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);

                }
                while(!q2.empty()) { //�ڱ� �׶����� ī��� �� ��������.
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
    deque<int> ddq; //���� ��
    queue<int> dground; //���� �׶���
    deque<int> sdq; //���� ��
    queue<int> sground; //���� �׶���
    cin>>n>>m;

    //�Է�
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

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

string game(int m, deque<int> &dq1, queue<int> &q1, deque<int> &dq2, queue<int> &q2){
    int a=0,b=0;
    int i;
    int cnt=1;
    for(i=0; i<2500000; i++){
        //cout<<"i: "<<i<<'\n';
        if(i%2==0) {
            a = dq1.front();
            dq1.pop_front(); //������ ������ ����
            q1.push(a); //�׶��忡 �ֱ�
            a= q1.back();
            if (dq1.empty() || dq2.empty()) {
                if (dq1.empty()) {
                   break;
                } else {
                   break;
                }
            }

            if (a == 5) { //������ ���� 5�� ������ ��, ������ ������
                while(!q2.empty()) { //���� �׶��忡 �ִ� ī��� �� ��������
                    int st = q2.front();
                    q2.pop();
                    dq1.push_back(st);
                    b=q2.back();
                }

                while(!q1.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq1.push_back(st);
                    a= q1.back();
                }

            }

            if (a + b == 5) {
                while(!q1.empty()) { //���� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);
                    a= q1.back();
                }
                while(!q2.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);
                    b=q2.back();
                }
            }
            if (dq1.empty() || dq2.empty()) {
                if (dq1.empty()) {
                    break;
                } else {
                    break;
                }
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
            b = dq2.front();
            dq2.pop_front();
            q2.push(b);
            b=q2.back();
            if (dq1.empty() || dq2.empty()) {
                if (dq1.empty()) {
                    break;
                } else {
                    break;
                }
            }

            if (b == 5) { //�������� ���� 5�� ������ ��, ������ ������
                while(!q2.empty()) { //���� �׶��忡 �ִ� ī��� �� ��������
                    int st = q2.front();
                    //cout<<"st: "<<st<<'\n';
                    q2.pop();
                    dq1.push_back(st);
                    b=q2.back();

                }

                while(!q1.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    //cout<<"st: "<<st<<'\n';
                    q1.pop();
                    dq1.push_back(st);
                    a= q1.back();
                }

            }

            if (a + b == 5) {
                while(!q1.empty()) { //���� �׶����� ī��� �� ��������.
                    int st = q1.front();
                    q1.pop();
                    dq2.push_back(st);
                    a= q1.back();
                }
                while(!q2.empty()) { //�ڱ� �׶����� ī��� �� ��������.
                    int st = q2.front();
                    q2.pop();
                    dq2.push_back(st);
                    b=q2.back();
                }
            }
            if (dq1.empty() || dq2.empty()) {
                if (dq1.empty()) {
                    break;
                } else {
                    break;
                }
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

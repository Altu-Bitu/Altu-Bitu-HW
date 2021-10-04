#include <iostream>
#include <deque>
#include <queue>
using namespace std;

string arr[2500001];


void game(int m, deque<int> &dq1, queue<int> &q1, deque<int> &dq2, queue<int> &q2){
    int a=0,b=0;
    int i;
    for(i=0; i<2500000; i++){
        //cout<<"i: "<<i<<'\n';
        a=dq1.front();
        dq1.pop_front(); //������ ������ ����
        q1.push(a); //�׶��忡 �ֱ�

        if(dq1.empty() || dq2.empty()) {
            if(dq1.empty()){
                arr[i]="su";
                break;
            }
            else{
                arr[i]="do";
                break;
            }
        }

        if(a==5){ //������ ���� 5�� ������ ��, ������ ������
            for(int j=0; j<q2.size(); j++) { //���� �׶��忡 �ִ� ī��� �� ��������
                int st = q2.front();
                q2.pop();
                dq1.push_back(st);
            }

            for(int j=0; j<q1.size(); j++){ //�ڱ� �׶����� ī��� �� ��������.
                int st = q1.front();
                q1.pop();
                dq1.push_back(st);
            }

        }

        if(a+b==5){
            for(int j=0; j<q1.size(); j++){ //���� �׶����� ī��� �� ��������.
                int st = q1.front();
                q1.pop();
                dq2.push_back(st);
            }
            for(int j=0; j<q2.size(); j++){ //�ڱ� �׶����� ī��� �� ��������.
                int st = q2.front();
                q2.pop();
                dq2.push_back(st);
            }
        }
        //cout<<"do: "<<dq1.size()<<' '<<q1.size()<<'\n';
       // cout<<"su: "<<dq2.size()<<' '<<q2.size()<<'\n';
        ++i;
        //cout<<"i: "<<i<<'\n';
        b=dq2.front();
        dq2.pop_front();
        q2.push(b);
        if(dq1.empty() || dq2.empty()) {
            if(dq1.empty()){
                arr[i]="su";
                break;
            }
            else{
                arr[i]="do";
                break;
            }
        }

        if(b==5){ //�������� ���� 5�� ������ ��, ������ ������
            for(int j=0; j<q2.size()+2; j++){ //���� �׶��忡 �ִ� ī��� �� ��������
                int st = q2.front();
                //cout<<"st: "<<st<<'\n';
                q2.pop();
                dq1.push_back(st);
            }

            for(int j=0; j<q1.size()+1; j++){ //�ڱ� �׶����� ī��� �� ��������.
                int st = q1.front();
                //cout<<"st: "<<st<<'\n';
                q1.pop();
                dq1.push_back(st);
            }

        }

        if(a+b==5){
            for(int j=0; j<q1.size(); j++){ //���� �׶����� ī��� �� ��������.
                int st = q1.front();
                q1.pop();
                dq2.push_back(st);
            }
            for(int j=0; j<q2.size(); j++){ //�ڱ� �׶����� ī��� �� ��������.
                int st = q2.front();
                q2.pop();
                dq2.push_back(st);
            }
        }
        //++i;
        //cout<<"i: "<<i<<'\n';
       // cout<<"do: "<<dq1.size()<<' '<<q1.size()<<'\n';
        //cout<<"su: "<<dq2.size()<<' '<<q2.size()<<'\n';
        //cout<<"m-1: "<<m-1<<'\n';
        if(i==m-1)
            break;

    }
    if(dq1.size()>dq2.size()){
        for(int j=i; j<2500000; j++){
            arr[j]="do";
        }
    }

    else if(dq1.size()<dq2.size()){
        for(int j=i; j<2500000; j++){
            arr[j]="su";
        }
    }

    else{
        for(int j=i; j<2500000; j++){
            arr[j]="dosu";
        }
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

    game(m,ddq, dground, sdq, sground);
    cout<<arr[m-1];
    //cout<<"do: "<<ddq.size()<<' '<<dground.size()<<'\n';
    //cout<<"su: "<<sdq.size()<<' '<<sground.size()<<'\n';
}

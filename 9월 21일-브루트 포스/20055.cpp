#include <iostream>
#include <queue>

using namespace std;

int main(){
    //pair: ������, �ڽ� ����
    deque<pair<int, bool>> dq1; //1, 2, 3,-, N
    deque<pair<int, bool>> dq2; //2N, 2N-1, 2N-2,-, N+1

    int n,k;
    int cnt=0; //�� �ܰ迡�� ����


    //�Է�
    cin>>n>>k;

    for(int i=1; i<=n; i++){
        int num;
        cin>>num;
        dq1.emplace_back(num,false);
    }

    for(int i=n+1; i<=2*n; i++){
        int num;
        cin>>num;
        dq2.push_front(make_pair(num,false));
    }

    cout<<"0\n";
    for(int i=0; i<n; i++){
        cout<<dq1[i].first<<' ';
    }
    cout<<'\n';
    for(int i=0; i<n; i++){
        cout<<dq2[i].first<<' ';
    }
    cout<<'\n';
    cout<<'\n';


    while(true){
        int zcnt=0; //0 ����
        cnt++; //�ܰ� ����

        if(dq1[n-1].second) //���� �����ϸ� ������ ������.
            dq1[n-1].second=false;

        //1. ��ĭ ȸ��
        pair<int, int> pa1;
        pa1 = dq1.back();
        dq1.pop_back();
        if(dq1[n-1].second) //���� �����ϸ� ������ ������.
            dq1[n-1].second=false;


        pair<int, int> pa2;
        pa2 = dq2.front();
        dq2.pop_front();

        dq2.emplace_back(pa1);
        dq1.push_front(pa2);
        cout<<"1\n";
        for(int i=0; i<n; i++){
            cout<<dq1[i].first<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; i++){
            cout<<dq2[i].first<<' ';
        }
        cout<<'\n';
        cout<<'\n';

        for(int i=n-2; i>=0; i--){
            if(dq1[i+1].first>=1 && dq1[i+1].second==false && dq1[i].second==true){ //2. �������� 1�̻��̰� ���� ĭ�� �κ��� ���ٸ�
                //�̵�
                dq1[i+1].first--;
                dq1[i+1].second=true;
                dq1[i].second=false;

            }
            if(dq1[n-1].second) //���� �����ϸ� ������ ������.
                dq1[n-1].second=false;

        }
        cout<<"2\n";
        for(int i=0; i<n; i++){
            cout<<dq1[i].first<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; i++){
            cout<<dq2[i].first<<' ';
        }
        cout<<'\n';
        cout<<'\n';


        //3. �ø��� ��ġ�� �������� 0�� �ƴϸ� �ø��� ��ġ�� �κ��� �ø���.
        if(dq1[0].first>0){
            dq1[0].first--;
            dq1[0].second=true;
        }

        if(dq1[n-1].second) //���� �����ϸ� ������ ������.
            dq1[n-1].second=false;

        cout<<"3\n";
        for(int i=0; i<n; i++){
            cout<<dq1[i].first<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; i++){
            cout<<dq2[i].first<<' ';
        }
        cout<<'\n';
        cout<<'\n';


        //4. �������� 0�� ĭ�� ���� ����
        for(int i=0; i<n; i++){
            if(dq1[i].first==0)
                zcnt++;
            if(dq2[i].first==0)
                zcnt++;
        }

        //k�� �̻��̸� break
        if(zcnt==k){
            break;
        }
        cout<<"4\n";
        for(int i=0; i<n; i++){
            cout<<dq1[i].first<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; i++){
            cout<<dq2[i].first<<' ';
        }
        cout<<'\n';
        cout<<"cnt: "<<cnt<<'\n';
        cout<<'\n';
        cout<<'\n';
    }

    cout<<cnt;

}

#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int main(){
    //����� �� ���, ���� ����ؼ� ����ϹǷ� ��� ���� �켱���� ť, ���� ���� �켱���� ť �� �� �������Ѵ�.
    priority_queue<int, vector<int>, greater<int>> pq1; //��� �������� ���� ex. 1, 2, 3
    priority_queue<int> pq2; //���� ���� �켱���� ť-�������� ex. -1, -2, -3
    int n;

    cin>>n;

    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        if(num!=0){
            if(num>0)
                pq1.push(num);
            else
                pq2.push(num);
        }
        else{
            if(pq1.empty() && pq2.empty()) //�� �� ����ִ� ���
                cout<<"0\n";
            else{
                if(pq1.empty()){ //pq1�� ��������� pq2���� pop
                    cout<<pq2.top()<<'\n';
                    pq2.pop();
                }
                else if(pq2.empty()){ //pq2�� ��������� pq1���� pop
                    cout<<pq1.top()<<'\n';
                    pq1.pop();
                }
                else{ //�� �� �ִ� ���, ���� �� - ���� �� �ִ� �켱���� ť���� pop
                    if(pq1.top()<pq2.top()*(-1)){
                        cout<<pq1.top()<<'\n';
                        pq1.pop();
                    }
                    else{
                        cout<<pq2.top()<<'\n';
                        pq2.pop();
                    }
                }
            }
        }
    }
}
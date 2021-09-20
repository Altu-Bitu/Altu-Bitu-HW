#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>


using namespace std;

struct compare{
    //pair�� first: ����, second: ���� ��(����/���)
    bool operator()(const pair<int, int> &A, const pair<int,int> &B){
        if(A.first == B.first){ //������ ���� ���
            return A.second > B.second; //���� �� ��
        }
        else //������ �ٸ� ���
            return A.first > B.first; //�������� ��
    }
};

void absHeap(int n, priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1){
    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        if(num!=0){ //push
            pq1.push(pair<int,int>(abs(num),num)); //���񰪰� ���� ���� pair�� ����� push
        }
        else{ //pop
            if(pq1.empty()) //�� �� ����ִ� ���
                cout<<"0\n";
            else {
                cout<<pq1.top().second<<"\n"; //������ ����ϰ� pop
                pq1.pop();
            }
        }
    }
}

int main(){
    //����� �� ���, ���� ����ؼ� ����ϹǷ� ��� ���� �켱���� ť, ���� ���� �켱���� ť �� �� �������Ѵ�.

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1;
    //priority_queue<�ڷ���, container, compare�Լ�>�� ����

    int n;

    cin>>n;

    absHeap(n, pq1);

}
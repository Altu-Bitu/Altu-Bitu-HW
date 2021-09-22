#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(int a, int b) { //�������� ���Ͽ� ���� ���� ����
        if (abs(a) == abs(b))
            return a > b;
        return abs(a) > abs(b);
    }
};

void absHeap(int n, priority_queue<int, vector<int>, compare> pq1){
    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        if(num!=0){ //push
            pq1.push(num);
        }
        else{ //pop
            if(pq1.empty()) //�� �� ����ִ� ���
                cout<<"0\n";
            else {
                cout<<pq1.top()<<"\n"; //������ ����ϰ� pop
                pq1.pop();
            }
        }
    }
}

int main(){
    //����� �� ���, ���� ����ؼ� ����ϹǷ� ��� ���� �켱���� ť, ���� ���� �켱���� ť �� �� �������Ѵ�.

    priority_queue<int, vector<int>, compare> pq1;
    //priority_queue<�ڷ���, container, compare�Լ�>�� ����

    int n;

    cin>>n;

    absHeap(n, pq1);

}
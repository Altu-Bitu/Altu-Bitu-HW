#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct compare{
    bool operator()(int a, int b) { //절댓값으로 비교하여 원래 값을 저장
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
            if(pq1.empty()) //둘 다 비어있는 경우
                cout<<"0\n";
            else {
                cout<<pq1.top()<<"\n"; //원래값 출력하고 pop
                pq1.pop();
            }
        }
    }
}

int main(){
    //출력할 때 양수, 음수 고려해서 출력하므로 양수 담은 우선순위 큐, 음수 담은 우선순위 큐 둘 다 만들어야한다.

    priority_queue<int, vector<int>, compare> pq1;
    //priority_queue<자료형, container, compare함수>로 정의

    int n;

    cin>>n;

    absHeap(n, pq1);

}
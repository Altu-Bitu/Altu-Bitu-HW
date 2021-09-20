#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>


using namespace std;

struct compare{
    //pair의 first: 절댓값, second: 원래 값(음수/양수)
    bool operator()(const pair<int, int> &A, const pair<int,int> &B){
        if(A.first == B.first){ //절댓값이 같은 경우
            return A.second > B.second; //원래 값 비교
        }
        else //절댓값이 다른 경우
            return A.first > B.first; //절댓값으로 비교
    }
};

void absHeap(int n, priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1){
    for(int i=0; i<n; i++){
        int num;
        cin>>num;

        if(num!=0){ //push
            pq1.push(pair<int,int>(abs(num),num)); //절댓값과 원래 값을 pair로 만들어 push
        }
        else{ //pop
            if(pq1.empty()) //둘 다 비어있는 경우
                cout<<"0\n";
            else {
                cout<<pq1.top().second<<"\n"; //원래값 출력하고 pop
                pq1.pop();
            }
        }
    }
}

int main(){
    //출력할 때 양수, 음수 고려해서 출력하므로 양수 담은 우선순위 큐, 음수 담은 우선순위 큐 둘 다 만들어야한다.

    priority_queue<pair<int,int>, vector<pair<int,int>>, compare> pq1;
    //priority_queue<자료형, container, compare함수>로 정의

    int n;

    cin>>n;

    absHeap(n, pq1);

}
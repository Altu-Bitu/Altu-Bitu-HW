#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int main(){
    //출력할 때 양수, 음수 고려해서 출력하므로 양수 담은 우선순위 큐, 음수 담은 우선순위 큐 둘 다 만들어야한다.
    priority_queue<int, vector<int>, greater<int>> pq1; //양수 오름차순 저장 ex. 1, 2, 3
    priority_queue<int> pq2; //음수 담은 우선순위 큐-내림차순 ex. -1, -2, -3
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
            if(pq1.empty() && pq2.empty()) //둘 다 비어있는 경우
                cout<<"0\n";
            else{
                if(pq1.empty()){ //pq1이 비어있으면 pq2에서 pop
                    cout<<pq2.top()<<'\n';
                    pq2.pop();
                }
                else if(pq2.empty()){ //pq2가 비어있으면 pq1에서 pop
                    cout<<pq1.top()<<'\n';
                    pq1.pop();
                }
                else{ //둘 다 있는 경우, 절댓값 비교 - 작은 값 있는 우선순위 큐에서 pop
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
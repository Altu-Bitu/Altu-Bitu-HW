#include <iostream>
#include <stack>

using namespace std;

int main(){
    pair<int, int> pa;
    stack<pair<int, int>> st;
    int cnt=0;
    int n,p;

    //같은 줄 , 높은 프렛- 누르기만 하면 됨
    //같은 줄 , 낮은 프렛 - 이미 있는 프렛 아니면 새로 눌러야함. 위에 거 떼야함
    //다른 줄 - 누르기

    cin>>n>>p;

    for(int i=0; i<n; i++){
        int l,p;
        cin>>l>>p;
        auto pa1 = make_pair(l,p);
        st.push(pa1);
        cnt++;
    }
}

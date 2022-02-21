#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<int> v;
    vector<int> t;
    stack<int> st;

    cin>>n;

    v.assign(n+1,0);
    t.assign(n+1,0);

    for(int i=1; i<n+1; i++){
        cin>>v[i];
    }

    for(int i=n; i>=1; i--){

        //인덱스 이용- 인덱스를 스택에 저장하고 인덱스로 v벡터에 접근하여 높이값을 알아내고 비교한다.
        while(!st.empty() && v[st.top()]<v[i]){
            t[st.top()]=i;
            st.pop();
        }

        st.push(i);
    }
    
    for(int i=1; i<n+1; i++){
        cout<<t[i]<<' ';
    }   
}
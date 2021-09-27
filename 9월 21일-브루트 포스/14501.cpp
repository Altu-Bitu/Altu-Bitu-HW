#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<pair<int, int>> v;

    int answer=0;
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        int t, p;
        cin>>t>>p;
        v.push_back(make_pair(t, p));
    }

    int idx;
    for(int i=0; i<v.size(); i++) {
        int result=0;
        idx=i;
        //일을 계속 하는 경우 - 정답x -이유: 중간에 일을 안 하는 날이 있을 수 있음.
        while (true) {
            if (idx+v[idx].first-1 >=v.size())
                break;
            result += v[idx].second;
            idx += v[idx].first;
            cout<<"result: "<<result<<'\n';
            cout<<"idx: "<<idx<<'\n';

        }

        if(answer<result)
            answer = result;
        cout<<"?";
    }

    cout<<answer;
}


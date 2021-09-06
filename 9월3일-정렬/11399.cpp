#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int N;
    int result=0;

    cin>>N;

    for(int i=0; i<N;i++){
        int num;
        cin>>num;
        v.push_back(num);
    }

    sort(v.begin(), v.end()); //정렬

    //누적합
    int cnt=1;
    while(N>0){
        result += v[N-1]*(cnt);
        N--;
        cnt++;
    }

    cout<<result;
}


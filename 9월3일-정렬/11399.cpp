#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int func(int n, vector<int> v1){
    int result=0;

    for(int i=0; i<n;i++){
        int num;
        cin>>num;
        v1.push_back(num);
    }

    sort(v1.begin(), v1.end());

    //´©ÀûÇÕ
    int cnt=1;
    while(n>0){
        result += v1[n-1]*(cnt);
        n--;
        cnt++;
    }

    return result;
}

int main(){
    vector<int> v;
    int N;

    cin>>N;

   int answer = func(N, v);

    cout<<answer;
}


#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int func(int n, vector<double> v1){
    double B, C;
    long long result=0; //int로 하면 범위 초과로 오류 발생

    v1.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v1[i];
    }

    cin>>B>>C;

    for(int i=0; i<n; i++){
        result += 1;
        v1[i]=v1[i]-B;
        if(v1[i]>0){
            result += ceil(v1[i]/C);
        }

    }

    return result;
}

int main() {
    double N;
    vector<double> A;
    cin >> N;

    int answer = func(N, A);

    cout<<answer;

}

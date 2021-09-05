#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double N, B, C;
vector<double> A;
long result=0;

int main() {

    cin >> N;
    A.assign(N, 0);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin>>B>>C;

    for(int i=0; i<N; i++){
        result += 1;
        A[i]=A[i]-B;
        if(A[i]>0){
            result += ceil(A[i]/C);
        }

    }
    cout<<result;

}
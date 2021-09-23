#include <iostream>
#include <vector>

using namespace std;

//최대공약수 구하기 - 유클리드 호제법 이용
int gcd(int a, int b){
    if(a%b==0)
        return b;
    return gcd(b, a%b);
}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        int n;
        vector<int> v;

        cin>>n;

        for(int j=0; j<n; j++){
            int num;
            cin>>num;
            v.push_back(num);
        }

        long long sum=0;
        for(int j=0; j<n; j++){
            for(int k=j+1; k<n; k++)
                sum += gcd(v[j], v[k]); //모든 쌍의 최대공약수 계산해서 더하기
        }
        cout<<sum<<'\n';

    }
}


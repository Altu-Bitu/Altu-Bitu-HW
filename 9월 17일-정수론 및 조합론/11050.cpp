#include <iostream>

using namespace std;

//팩토리얼 함수
int fact(int n){
    int r=1;
    for(int i=1; i<=n; i++)
        r *= i;
    return r;
}

int main(){
    int n, k;
    int a=1,b=1,c=1;

    cin>>n>>k;

    //n!
    a = fact(n);
    //k!
    b = fact(k);
    //(n-k)!
    c = fact(n-k);

    int answer = a/(b*c);

    cout<<answer;
}

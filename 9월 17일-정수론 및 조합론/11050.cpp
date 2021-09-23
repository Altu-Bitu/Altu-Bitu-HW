#include <iostream>

using namespace std;

int main(){
    int n, k;
    int a=1,b=1,c=1;

    cin>>n>>k;

    //n!
    for(int i=1; i<=n; i++){
        a *=i;
    }
    //k!
    for(int i=1; i<=k; i++)
        b *= i;
    //(n-k)!
    for(int i=1; i<=n-k; i++)
        c *= i;

    int answer = a/(b*c);

    cout<<answer;
}


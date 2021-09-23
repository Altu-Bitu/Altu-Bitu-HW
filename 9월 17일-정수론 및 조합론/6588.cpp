#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> is_prime;

//에라토스테네스의 체
void isPrime(int n){
    is_prime.assign(n+1, true);
    for(int i=2; i<=sqrt(n); i++){ //제곱근
        if(is_prime[i]){
            for(int j=i+i; j<=n; j+=i){
                if(!is_prime[j])
                    continue;
                is_prime[j]=false;
            }
        }
    }
}

//골드바흐의 추측
string goldbach(int n){
    string result;

    for(int i=3; i<=n; i++){
        if(is_prime[i] && is_prime[n-i]){ //n도 소수, n-i도 소수인 경우
            result = to_string(n)+" = "+to_string(i)+" + " + to_string(n-i);
            return result;
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main(){
    //시간 초과때문에 아래 두 줄 코드 반드시 필요
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string answer;

    isPrime(1000000); //일단 에라토스테네스의 체 만들어 놓고 반복문 시행
    while(true){
        int n;
        cin>>n;

        if(n==0)
            break;
        else{
            answer=goldbach(n);
            cout<<answer<<'\n';
        }
    }

}

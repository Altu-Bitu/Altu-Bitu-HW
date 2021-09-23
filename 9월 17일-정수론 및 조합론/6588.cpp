#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<bool> is_prime;

//�����佺�׳׽��� ü
void isPrime(int n){
    is_prime.assign(n+1, true);
    for(int i=2; i<=sqrt(n); i++){ //������
        if(is_prime[i]){
            for(int j=i+i; j<=n; j+=i){
                if(!is_prime[j])
                    continue;
                is_prime[j]=false;
            }
        }
    }
}

//�������� ����
string goldbach(int n){
    string result;

    for(int i=3; i<=n; i++){
        if(is_prime[i] && is_prime[n-i]){ //n�� �Ҽ�, n-i�� �Ҽ��� ���
            result = to_string(n)+" = "+to_string(i)+" + " + to_string(n-i);
            return result;
        }
    }
    return "Goldbach's conjecture is wrong.";
}

int main(){
    //�ð� �ʰ������� �Ʒ� �� �� �ڵ� �ݵ�� �ʿ�
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string answer;

    isPrime(1000000); //�ϴ� �����佺�׳׽��� ü ����� ���� �ݺ��� ����
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

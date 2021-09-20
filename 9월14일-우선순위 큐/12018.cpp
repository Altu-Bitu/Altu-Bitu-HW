#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v; //�ش� ���� �����ϱ� ���� �ʿ��� �ּ� ���ϸ��� ������ ����

    int test;
    int mileage;
    int cnt=0;

    cin>>test>>mileage;

    for(int i=0; i<test; i++){
        int peo, limit;
        cin>>peo>>limit;
        vector<int> p(peo);
        for(int j=0; j<peo; j++){
           cin>>p[j];
        }

        sort(p.begin(), p.end(), greater<int>());

        if(peo<limit){ //��û�� ��� �� < ������û ���� ��� ��
            v.push_back(1); //���ϸ��� 1�̸� ������û ����
        }
        else{ //��û�� ��� �� >= ������û ���� ��� ��
            v.push_back(p[limit-1]); //limit ��° ���ϸ����� ������û ����
        }

    }

    sort(v.begin(), v.end()); //�������� ����, ���� �ͺ��� ���� �ִ�� ������û �����ϰ� �ϵ��� �Ѵ�.

    for(int i=0; i<v.size(); i++){
        if(mileage - v[i]>=0){
            mileage -= v[i];
            cnt++;
        }
        else
            break;
    }

    cout<<cnt;

}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v; //해당 과목 수강하기 위해 필요한 최소 마일리지 저장할 벡터

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

        if(peo<limit){ //신청한 사람 수 < 수강신청 가능 사람 수
            v.push_back(1); //마일리지 1이면 수강신청 가능
        }
        else{ //신청한 사람 수 >= 수강신청 가능 사람 수
            v.push_back(p[limit-1]); //limit 번째 마일리지면 수강신청 가능
        }

    }

    sort(v.begin(), v.end()); //오름차순 정렬, 작은 것부터 빼서 최대로 수강신청 가능하게 하도록 한다.

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


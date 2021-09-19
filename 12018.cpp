#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;

    int test;
    int mileage;

    cin>>test>>mileage;

    for(int i=0; i<test; i++){
        int peo, limit;
        cin>>peo>>limit;
        vector<int> p(peo);
        for(int j=0; j<peo; j++){
           cin>>p[j];
        }

        //make_heap(p.begin(), p.end(), greater<int>());
        sort(p.begin(), p.end(), greater<int>());

        if(peo<limit){
            v.push_back(1);
        }
        else{
            v.push_back(p[limit-1]);
        }

    }
    sort(v.begin(), v.end());

    int idx=0;
    while(mileage-v[idx]>=0){
        mileage -= v[idx];
        idx++;
    }

    cout<<idx;

}


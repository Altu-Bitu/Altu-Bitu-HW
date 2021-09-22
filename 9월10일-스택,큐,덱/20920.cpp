#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//수정필요
bool cmp(string a, string b){

};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<string> v;
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string word;
        cin>>word;

        if(word.length()<m)
            continue;

        v.push_back(word);
    }

    sort(v.begin(), v.end(), cmp);
}

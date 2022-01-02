#include <iostream>
#include <set>

using namespace std;

int main(){
    int n, m, cnt=0;
    set<string> s;
    
    cin>>n>>m;

    for(int i=0; i<n; i++){
        string words;
        cin>>words;
        s.insert(words);
    }

    for(int i=0; i<m; i++){
        string word;
        cin>>word;
        if(s.find(word)!= s.end()){
            cnt++;
        }
    }

    cout<<cnt;
}

//set의 find함수!!
#include <iostream>
#include <set>

using namespace std;

set<string> lxsx(set<string> &lx, int m){
    set<string> names;
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        /*for(auto name: listen){
            if(s==name){
                names.insert(s);
                break;
            }
        }*/

        if(lx.find(s)!=lx.end()){
            names.insert(s);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,m;
    set<string> listen;

    cin>>n>>m;

    for(int i=0; i<n; i++){
        string name;
        cin>>name;
        
        listen.insert(name);
    }

    set<string> names = lxsx(listen,m);

    cout<<names.size()<<'\n';
    for(auto iter:names){
        cout<<iter<<'\n';
    }
}

/*
1. 명단에는 중복되는 이름이 없다. 사전순으로 정렬한 것 출력 -> set 쓰기
1-1. 듣지 못한 사람의 명단을 set에 저장한다.
1-2. 듣지 못한 사람의 명단이 있는 set에 보지 못한 사람의 이름이 있는지 찾는다.
1-2-1. 이중for문을 사용하였으나 시간초과 발생
1-2-2. set의 find함수를 사용하여 해결
1-3. 있으면 names set에 넣고 아니면 안 넣는다.
*/
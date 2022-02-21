#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt=0;
    cin>>n;

    map<string, int> m; //정답 - <단어, 인덱스>로 저장 - 나중에 인덱스로 순서 맞는지 비교
    vector<pair<string, string>> res; //쌍으로 저장
    vector<string> v2(n); //작성한 답
    int whole = n*(n-1)/2;

    //정답
    for(int i=0; i<n; i++){ 
        string str;
        cin>>str;
        m[str]=i;
    }

    //작성한 답
    for(int i=0; i<n; i++){
        cin>>v2[i];
    }

    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(m[v2[i]]<m[v2[j]]){
                cnt++;
            }
        }
    }
    
    cout<<cnt<<"/"<<whole;
}

//map<string, string>을 사용하려고 하였으나 중복 허용 안 되어 사용하지 않았음.
//vector와 pair를 사용했더니 메모리 초과
//map을 써야될 것 같다고 다시 생각함.
//map<string, int> 즉 문자열을 쌍으로 저장하는 것이 아니라 문자열과 해당 인덱스를 저장하여
//순서가 맞는지 확인할 때 인덱스로만 비교하도록 하면 된다.
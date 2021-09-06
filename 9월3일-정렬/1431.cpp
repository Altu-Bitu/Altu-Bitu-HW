#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 문자에 숫자가 있을 때 int로 변환 */
//char ch = '9';
//cout << ch-'0';  // 9

int sum(string s){
    int result = 0;
    for(int i=0; i<s.length(); i++){
        if (s[i]-'0' >= 0 && s[i]-'0' <= 9) {
            result += s[i]-'0';
        }
    }
    return result;
}

bool cmp(string a, string b){
    if(a.length()!=b.length())
        return a.length()<b.length();
    else {
        int result1 = sum(a);
        int result2 = sum(b);

        if(result1 != result2){
            return result1<result2;
        }
        else
            return a < b;
    }
}

int main(){
    int N;
    vector<string> v;
    cin>>N;

    for(int i=0; i<N; i++){
        string word;
        cin>>word;
        v.push_back(word);
    }

    sort(v.begin(), v.end(), cmp);

    for(int i=0; i<N; i++){
        cout<<v[i]<<'\n';
    }
}

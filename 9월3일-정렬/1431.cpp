#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype> //isdigit함수 사용하기 위한 헤더

using namespace std;

/* 문자에 숫자가 있을 때 int로 변환 */
//char ch = '9';
//cout << ch-'0';  // 9

int sumNum(string s){
    int result = 0;
    for(int i=0; i<s.length(); i++){
//        if (s[i]-'0' >= 0 && s[i]-'0' <= 9) {
//            result += s[i]-'0';
//        }

        //같은 기능 다르게 구현 - isdigit함수 이용

        //isdigit함수: cctype헤더 사용
        //char형 인자가 숫자이면 0이 아닌 수 반환, 숫자가 아니면 0 qksghks
        //result에 더할 때는 s[i]-'0'형태로 더하기
        if(isdigit(s[i])!=0){
            result += s[i]-'0';
        }
    }
    return result;
}

bool cmp(string a, string b){
    if(a.length()!=b.length())
        return a.length()<b.length();
    else {
        int result1 = sumNum(a);
        int result2 = sumNum(b);

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

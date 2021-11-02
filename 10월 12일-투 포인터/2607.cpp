#include <iostream>
#include <vector>
#include <map>

using namespace std;
//실패
//비교 기준 문자열의 알파벳 - 비교 대상 문자열의 알파벳 이 1일 때 비슷하다.
//아닌가?

vector<int> alphabet; //비교 기준 알파벳 저장할 배열 (문자의 등장 횟수)

int similar(int n, string str){
    vector<int> newAlphabet;
    int cnt=0;
    int answer=0;

    for(int t=0; t<26; t++){
        //char a = 'A'+t;
        newAlphabet.push_back(0);
    }

    for(int i=0; i<str.length(); i++){
        //alphabet[str[i]-65].second++;
        alphabet[str[i]-65]++;
        //for(int j=0; j<26; j++)
        //    cout<<alphabet[j].second<< ' ';
    }


    for(int i=0; i<n-1; i++){
        cnt=0;
        for(int t=0; t<26; t++){
            //newAlphabet[t].second=0; //초기화
            newAlphabet[t]=0;
        }

        string s;
        cin>>s;
        for(int j=0; j<s.length(); j++){
            //newAlphabet[s[j]-65].second++;
            newAlphabet[s[j]-65]++;
        }

        for(int p=0; p<26; p++){
            //cnt += newAlphabet[p].second - alphabet[p].second;
            cnt += abs(newAlphabet[p]-alphabet[p]);
        }
        //cout<<"cnt: "<<cnt<<'\n';
        
        /**
    * 단어가 같은 구성일 조건
    * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
    * 2. 같은 문자는 같은 개수만큼 있음
    *
    * 비슷한 단어의 조건
    * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
    *    -> 두 단어에서 다른 문자의 개수가 총 1개
    * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
    *    -> 두 단어에서 다른 문자의 개수가 총 2개
    *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
    */
        if(cnt==0 || cnt==1 || (cnt==2&&s.length()==str.length())){ //비슷한 단어의 조건 두 번째 것 추가해야함.
            answer++;
        }
       
    }
    return answer;
}

int main(){
    int n;
    int answer;

    cin>>n;

    string str; //비교 기준
    cin>>str;

    alphabet.assign(26,0);

    //for(int i=0; i<26; i++){
        //char a = 'A'+i;
        //alphabet.push_back(make_pair(a,0));
    //}

    answer = similar(n,str);
    cout<<answer;
   
}
#include <iostream>
#include <vector>
#include <map>

using namespace std;

//각 알파벳의 개수를 map으로 짝지어서 저장
//비교 기준 map의 알파벳과 그 개수와 입력 단어와 비교할까
//같은 단어는 판별 가능
//비슷한 단어는 판별 가능?

map<char, int> alphabet; //비교 기준 알파벳 저장할 map 배열

void similar(int n, string str){
    
    for(int i=0; i<n-1; i++){

    }
}

int main(){
    int n;
    cin>>n;

    string str; //비교 기준
    cin>>str;

    for(int i=0; i<26; i++){
        char a = 'A'+i;
        alphabet[a]=0;
    }

    for(int i=0; i<str.length(); i++){
        alphabet[str[i]]++;
    }
    

    
}
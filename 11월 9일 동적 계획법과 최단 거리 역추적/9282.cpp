#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> len;
    vector<int> path;

    string str1, str2; //긴 문자열, 짧은 문자열

    cin>>str1>>str2;

    if(str1.size()<str2.size()){
        swap(str1, str2);
    }

    len.assign(str2.size(),1);


    for(int i=0; i<str1.size(); i++){
        for(int j=0; j<str2.size(); j++){
            
        }
    }
    
}
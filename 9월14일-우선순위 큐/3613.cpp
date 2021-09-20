#include <iostream>

using namespace std;

//오류인 상황
//1. str[0]='_' or 대문자
//2. '-'가 연속으로 등장
//3. '-' 다음에 대문자 등장
//4. c++이라고 인식했는데 대문자 등장
//5. java라고 인식했는데 '-' 등장
//6. 마지막 문자가 '-'

int judging(string str) {
    if (!islower(str[0]) || str[str.length() - 1] == '_') //오류 1,6
        return -1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i - 1] == '_') { //c++로 판단
            //예외처리
            if(str[i]=='_') //오류2
                return -1;
            for(int j=i; j<str.length(); j++){
                if(isupper(str[j])) //오류3,4
                    return -1;
            }
            return 0;

        }
        else {
            if (isupper(str[i])) {//java라고 판단
                for(int j=i+1; j<str.length(); j++){//오류5
                    if(str[j]=='_')
                        return -1;
                }

                return 1;
            }
        }
    }
    return 0;//c++이라고 판단

}

string cppToJava(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            result.append(1, toupper(str[++i]));
        }
        else {
            result.append(1, str[i]);
        }
    }
    return result;
}

string javaToCpp(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (isupper(str[i])) {
            result.append(1, '_');
            result.append(1, tolower(str[i]));
        }
        else {
            result.append(1, str[i]);
        }
    }
    return result;
}

int main() {
    string val;
    string answer;
    cin >> val;

    int result = judging(val);

    if (result == 1) { //java로 판단
        answer = javaToCpp(val);
    } else if (result == 0) //c++로 판단
        answer = cppToJava(val);
    else //오류로 판단
        answer = "Error!";

    cout << answer;
}


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
        if (str[i - 1] == '_') { //오류 2,3
            if(str[i]=='_')
                return -1;
            for(int j=i; j<str.length(); j++){
                if(isupper(str[j])) //대문자나오면 java로 판단
                    return -1;
            }
            return 0;

        }
        else {
            if (isupper(str[i])) {//java라고 판단
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
        } else if (isupper(str[i]))//오류 4
            return "Error!";
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
        } else if (str[i] == '_')//오류 5
            return "Error!";
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


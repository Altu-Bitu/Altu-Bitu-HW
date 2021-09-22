#include <iostream>

using namespace std;

//알게된 점
//하나의 함수로 문자열을 하나하나 조사하며 이것이 cpp인지 java인지 조사하는 것보다
//cpp이라고 가정하고 아닌 것 찾기, java라고 가정하고 아닌 것 찾기 함수를 따로 만들어서 하는 것이 더 효율적이다.
//기존 judging함수에서 이중for문이 2번 사용되었는데 find함수를 사용한다면 1번으로 줄일 수 있을 것 같다.

//오류인 상황
//1. str[0]='_' or 대문자
//2. '-'가 연속으로 등장
//3. '-' 다음에 대문자 등장
//4. c++이라고 인식했는데 대문자 등장
//5. java라고 인식했는데 '-' 등장
//6. 마지막 문자가 '-'

//cpp형식이라고 가정하고 cpp형식이 아니면 false 반환
bool isCpp(string str) { //c++ 형식인가?
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //대문자가 있으면 안됨
            return false;
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) //첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
            return false;
    }
    return true;
}

//java형식이라고 가정하고 java형식이 아니면 false 반환
bool isJava(string str) { //java 형식인가?
    return !isupper(str[0]) && str.find('_') == string::npos; //첫 글자가 대문자거나, '_'가 있으면 안됨
    //find함수가 찾는 대상이 문자열에 없다면 string::npos를 반환한다.
    //문자열에서 찾고싶은 문자(열)이 있다면 find함수 사용하기
}

string toCpp(string str) { //java 형식을 c++로
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //대문자라면 앞에 '_' 삽입
            result += '_';
        result += tolower(str[i]); //소문자로 바꿔서 넣기
    }
    return result;
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

    bool is_cpp = isCpp(val);
    bool is_java = isJava(val);


    if(is_cpp && is_java)
        answer = val;
    else if (is_java)  //java로 판단
        answer = javaToCpp(val);
    else if (is_cpp) //c++로 판단
        answer = cppToJava(val);
    else //오류로 판단
        answer = "Error!";

    cout << answer;
}


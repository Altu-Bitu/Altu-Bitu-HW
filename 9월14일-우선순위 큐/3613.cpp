#include <iostream>

using namespace std;

//�˰Ե� ��
//�ϳ��� �Լ��� ���ڿ��� �ϳ��ϳ� �����ϸ� �̰��� cpp���� java���� �����ϴ� �ͺ���
//cpp�̶�� �����ϰ� �ƴ� �� ã��, java��� �����ϰ� �ƴ� �� ã�� �Լ��� ���� ���� �ϴ� ���� �� ȿ�����̴�.
//���� judging�Լ����� ����for���� 2�� ���Ǿ��µ� find�Լ��� ����Ѵٸ� 1������ ���� �� ���� �� ����.

//������ ��Ȳ
//1. str[0]='_' or �빮��
//2. '-'�� �������� ����
//3. '-' ������ �빮�� ����
//4. c++�̶�� �ν��ߴµ� �빮�� ����
//5. java��� �ν��ߴµ� '-' ����
//6. ������ ���ڰ� '-'

//cpp�����̶�� �����ϰ� cpp������ �ƴϸ� false ��ȯ
bool isCpp(string str) { //c++ �����ΰ�?
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //�빮�ڰ� ������ �ȵ�
            return false;
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) //ù or ������ ���ڰ� '_' �Ǵ� '_'�� ���� ����
            return false;
    }
    return true;
}

//java�����̶�� �����ϰ� java������ �ƴϸ� false ��ȯ
bool isJava(string str) { //java �����ΰ�?
    return !isupper(str[0]) && str.find('_') == string::npos; //ù ���ڰ� �빮�ڰų�, '_'�� ������ �ȵ�
    //find�Լ��� ã�� ����� ���ڿ��� ���ٸ� string::npos�� ��ȯ�Ѵ�.
    //���ڿ����� ã����� ����(��)�� �ִٸ� find�Լ� ����ϱ�
}

string toCpp(string str) { //java ������ c++��
    string result;
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) //�빮�ڶ�� �տ� '_' ����
            result += '_';
        result += tolower(str[i]); //�ҹ��ڷ� �ٲ㼭 �ֱ�
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
    else if (is_java)  //java�� �Ǵ�
        answer = javaToCpp(val);
    else if (is_cpp) //c++�� �Ǵ�
        answer = cppToJava(val);
    else //������ �Ǵ�
        answer = "Error!";

    cout << answer;
}


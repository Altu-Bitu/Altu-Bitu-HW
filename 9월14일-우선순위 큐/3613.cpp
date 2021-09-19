#include <iostream>

using namespace std;

//������ ��Ȳ
//1. str[0]='_' or �빮��
//2. '-'�� �������� ����
//3. '-' ������ �빮�� ����
//4. c++�̶�� �ν��ߴµ� �빮�� ����
//5. java��� �ν��ߴµ� '-' ����
//6. ������ ���ڰ� '-'

int judging(string str) {
    if (!islower(str[0]) || str[str.length() - 1] == '_') //���� 1,6
        return -1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i - 1] == '_') { //���� 2,3
            if(str[i]=='_')
                return -1;
            for(int j=i; j<str.length(); j++){
                if(isupper(str[j])) //�빮�ڳ����� java�� �Ǵ�
                    return -1;
            }
            return 0;

        }
        else {
            if (isupper(str[i])) {//java��� �Ǵ�
                return 1;
            }
        }
    }
    return 0;//c++�̶�� �Ǵ�

}

string cppToJava(string str) {
    string result = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '_') {
            result.append(1, toupper(str[++i]));
        } else if (isupper(str[i]))//���� 4
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
        } else if (str[i] == '_')//���� 5
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

    if (result == 1) { //java�� �Ǵ�
        answer = javaToCpp(val);
    } else if (result == 0) //c++�� �Ǵ�
        answer = cppToJava(val);
    else //������ �Ǵ�
        answer = "Error!";

    cout << answer;
}


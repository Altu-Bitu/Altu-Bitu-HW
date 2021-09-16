#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

double operating(int n, string str){
    stack<double> st;
    double result=0;
    int arr[n];

    //알파벳에 대응하는 숫자 입력
    for(int i=0; i<n; i++)
        cin>>arr[i];

    //스택 이용- 문자열을 돌면서 알파벳일때는 스택에 알파벳에 대응하는 숫자 push
    //아니면 두 개의 숫자 pop하고 계산해서 다시 push하기
    for(int i=0; i<str.length(); i++){
        if(isalpha(str[i])){
            int asc = str[i]-'0';
            asc = asc-17;
            st.push(arr[asc]);
        }
        else {
            if (str[i] == '*') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();

                result = b * a;
                st.push(result);
            } else if (str[i] == '/') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();

                result = b / a;
                st.push(result);
            } else if (str[i] == '+') {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();

                result = b + a;
                st.push(result);
            } else {
                double a = st.top();
                st.pop();
                double b = st.top();
                st.pop();

                result = b - a;
                st.push(result);
            }
            //cout<<"mid: "<<result<<'\n';
        }
    }
    return result;
}

int main(){
    int n;
    string str;
    double result=0;
    cin>>n;
    cin>>str;

    result=operating(n, str);

    //소수점이하 둘째자리까지 나타내기 위한 코드
   cout.setf(ios::fixed);
    cout.precision(2);
    cout<<result;

}


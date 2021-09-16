#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

double operating(int n, string str){
    stack<double> st;
    double result=0;
    int arr[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

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
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<result;

}


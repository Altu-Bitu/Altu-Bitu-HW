#include <iostream>
#include <stack>

using namespace std;

string postfix(stack<char> &st, string str){
    string answer="";
     
    for(int i=0; i<str.length(); i++){
        if(str[i]>='A' && str[i]<='Z'){
            answer += str[i];
        }
        else{
            switch(str[i]){
                case '(':
                    st.push(str[i]);
                    break;

                case '*': case '/':
                    while(!st.empty() && (st.top()== '*' || st.top()=='/')){
                        answer += st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                    break;

                case '+': case '-':
                    while(!st.empty() && st.top()!='('){
                        answer += st.top();
                        st.pop();
                    }
                    st.push(str[i]);
                    break;
                
                case ')':
                    while(!st.empty() && st.top()!='('){
                        answer += st.top();
                        st.pop();
                    }
                    st.pop();
                    break;
            }
        }
    }
    while(!st.empty()){
        answer += st.top();
        st.pop();
    }

    return answer;
}

int main(){
    stack<char> st;
    string str, answer="";

    cin>>str;

    answer = postfix(st, str);

    cout<<answer;

}

//후위 표기식 a+b*c -> abc*+ 
//연산자의 우선순위 지키기
//우선순위 낮은 연산자가 우선순위 높은 연산자 위에 들어오려고 하면 스택에 있는 모든 것들을 pop
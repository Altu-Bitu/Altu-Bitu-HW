#include <iostream>
#include <stack>

using namespace std;

int main(){
    pair<int, int> pa;
    stack<pair<int, int>> st;
    int cnt=0;
    int n,p;

    //���� �� , ���� ����- �����⸸ �ϸ� ��
    //���� �� , ���� ���� - �̹� �ִ� ���� �ƴϸ� ���� ��������. ���� �� ������
    //�ٸ� �� - ������

    cin>>n>>p;

    for(int i=0; i<n; i++){
        int l,p;
        cin>>l>>p;
        auto pa1 = make_pair(l,p);
        st.push(pa1);
        cnt++;
    }
}

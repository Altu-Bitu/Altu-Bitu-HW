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
        if(st.empty()){
            st.push(pa1);
            cnt++;
        }
        else if(pa1.first==st.top().first){//���� ��
            if(pa1.second>st.top().second) {
                st.push(pa1);
                cnt++; //�������ϱ�
            }

            else{
                while(true){
                    if((st.top()).second<pa1.second){
                        st.push(pa1);
                        cnt++;//����
                        break;
                    }
                    else if(st.top().second==pa1.second){
                        //cnt++;//��
                        break;
                    }
                    else{
                        st.pop();
                        cnt++;//��
                        if(st.empty()){
                            st.push(pa1);
                            cnt++;//����
                            break;
                        }
                    }
                }
            }

        }
        else{//�ٸ� ��
            st.push(pa1);
            cnt++;
        }

        cout<<st.top().first<<" "<<st.top().second<<'\n';
        cout<<"cnt: "<<cnt<<"\n";
    }

    cout<<cnt;
}

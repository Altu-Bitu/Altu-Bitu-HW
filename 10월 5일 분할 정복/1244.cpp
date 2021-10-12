#include <iostream>
#include <vector>

using namespace std;

void switching(vector<int> &v, int sex, int num){
    if(sex==1){//���л��̸� �ڱ� ��ȣ�� ����� ����ġ ���¸� �ٲ۴�.
        for(int i=num; i<v.size(); i+=num){
            (v[i]==1)?v[i]=0:v[i]=1;
        }
    }
    else{ //���л��̸� �ڱ� ���� ��Ī�� �ִ� ��� ã�Ƽ� ��� ���� �ٲ����
        if(num==1 || num==v.size()-1){ //���� ����ġ�� �� ���� ���, �ڱ� �ڽŸ� �ٲ�
            (v[num]==1)?v[num]=0:v[num]=1;
        }
        else{//���� ����ġ�� �� ���� �ƴ� ���, �� ������ �˻�
            int left = num; //num ���� ���� ǥ���� ��
            int right = num; //num ���� ������ ǥ���� ��

            while(left>=1 && right<=v.size()-1){//����
                if(v[left]!=v[right]) {
                    break;
                }
                left--;
                right++;
            }

            for(int i=left+1; i<right; i++){ //���� ���� �� ���� ���� �ٲٱ�
                (v[i]==1)?v[i]=0:v[i]=1;
            }
        }
    }
}

int main(){
    int n,s;
    cin>>n;
    vector<int> v(n+1);

    v[0]=-1;
    for(int i=1; i<n+1; i++)
        cin>>v[i];

    cin>>s;
    vector<pair<int,int>> sv(s);
    for(int i=0; i<s; i++){
        int sex, num;
        cin>>sex>>num;
        sv[i]=(make_pair(sex,num));
    }

    for(int i=0; i<s; i++){
        switching(v, sv[i].first, sv[i].second);
    }

    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<' ';
        if(i%20==0)
            cout<<'\n';
    }
}
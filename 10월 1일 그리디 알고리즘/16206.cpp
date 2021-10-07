#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� 10�� ������ �ִ� ���� ���ϴ� �Լ�
int rollcake(vector<int> &v, int n, int m){
    int cnt=0; //������ ����
    sort(v.begin(), v.end()); //�ϴ� ����

    //10�� ����� ���ʿ� �������� ������ �Ǿ��־�� �ִ� ������ ���´�.
    for(int i=0; i<n;i++){
        for(int j=i+1; j<n; j++){
            if(v[j]%10==0 && v[i]%10!=0)
                swap(v[i],v[j]);
        }
    }

    for(int i=0; i<n; i++){
        while(m>0 && v[i]>10){ //�ڸ� �� �ִ� Ƚ�� �����ְ� �������� ���̰� 10 �ʰ��� ��
            v[i]=v[i]-10;
            cnt++;
            m--;
        }
        if(v[i]==10) //���̰� 10�̶�� �ڸ��� �ʰ� ������ ������ ����
            cnt++;
        if(m==0) //�ڸ� �� �ִ� Ƚ���� 0�̶�� �� �̻� ������ ���ʿ��ϹǷ� break
            break;
    }
    return cnt; //cnt ����
}

int main(){
    vector<int> v;
    int n,m;
    cin>>n>>m;
    v.assign(n,0);

    //�Է�
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //���
    int answer = rollcake(v,n,m);
    cout<<answer;
}

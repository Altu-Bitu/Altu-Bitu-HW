#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt=0;
    cin>>n;

    map<string, int> m; //���� - <�ܾ�, �ε���>�� ���� - ���߿� �ε����� ���� �´��� ��
    vector<pair<string, string>> res; //������ ����
    vector<string> v2(n); //�ۼ��� ��
    int whole = n*(n-1)/2;

    //����
    for(int i=0; i<n; i++){ 
        string str;
        cin>>str;
        m[str]=i;
    }

    //�ۼ��� ��
    for(int i=0; i<n; i++){
        cin>>v2[i];
    }

    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(m[v2[i]]<m[v2[j]]){
                cnt++;
            }
        }
    }
    
    cout<<cnt<<"/"<<whole;
}

//map<string, string>�� ����Ϸ��� �Ͽ����� �ߺ� ��� �� �Ǿ� ������� �ʾ���.
//vector�� pair�� ����ߴ��� �޸� �ʰ�
//map�� ��ߵ� �� ���ٰ� �ٽ� ������.
//map<string, int> �� ���ڿ��� ������ �����ϴ� ���� �ƴ϶� ���ڿ��� �ش� �ε����� �����Ͽ�
//������ �´��� Ȯ���� �� �ε����θ� ���ϵ��� �ϸ� �ȴ�.
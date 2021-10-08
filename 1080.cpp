#include <iostream>
#include <vector>
#include <string>

using namespace std;

//�������� �� �������� Ȯ���ϴ� �Լ�
 int isPossible(vector<string> &v1, vector<string> &v2, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(v1[i][j]!=v2[i][j])
                return false;
        }
    }
    return true;
}

//�ٸ� �� 3*3 ������ �Լ�
void convert(vector<string> &v, int r, int c){
    for(int i=r; i<r+3; i++){ //���� �Ǽ� ���� �ʱ�
        for(int j=c; j<c+3; j++){
            if (v[i][j] == '1')
                v[i][j] = '0';
            else
                v[i][j] = '1';
        }
    }
}
//����
int matrix(vector<string> &v1, vector<string> &v2, int n, int m){
    int cnt=0;
    for (int i = 0; i <= n-3; i++) {
        for (int j = 0; j <= m-3; j++) {
            if(v1[i][j]!=v2[i][j]){
                convert(v1, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}


int main(){
    //������ string�� �ε����� �� ���ھ� ������ �� �����Ƿ� ���� char�� 2���� ���ͷ� �������� �ʰ�
    //string�� 1���� ���ͷ� �����Ѵ�.

    int n,m;
    cin>>n>>m;
    vector<string> v1(n);
    vector<string> v2(n);
    //�Է�
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }

    for(int i=0; i<n; i++){
        cin>>v2[i];
    }

    int answer = matrix(v1,v2,n,m);
    //�� ������ �������� �� �������� Ȯ��
    if(!isPossible(v1,v2,n,m))
        answer=-1;
    cout<<answer;

}
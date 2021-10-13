#include <iostream>
#include <vector>

using namespace std;

long long findingMinTime(vector<long long> &v, int n, int m){
    //�̺� Ž������ �ּ� �ð� ã��
    long long answer=0;
    long long left = 1; //1��*1��
    long long right = 1e9*1e9; //1e9��*1e9��
    long long mid;
    while(left<=right){
        mid = (left+right)/2; //���� �� �ð�
        long long cnt=0;
        for(int i=0; i<n; i++){
            //�� �ð� -> ��� ���� �����غ��� (�� �Ա��ɻ�� �ð����� ������)
            cnt += mid/v[i]; //���� �� �ð����� �� �Ա��ɻ�뿡�� �ɻ��� �� �ִ� ��� ���� �� ���ϱ�
            if(cnt>=m)//m�̻��� �Ǹ� break
                break;
        }

        if(cnt>=m){
            answer = mid; //�ϴ� ���信 mid �����س���
            right = mid-1; //�ּ� �ð� ���ϴ� ���̹Ƿ� �� ���� �ð������� �����ϴ��� Ȯ�� �ʿ�
        }
        else{
            left = mid+1;
        }
    }
    return answer;
}

int main(){
    //������
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v; //�� �Ա��ɻ�뿡�� �ɸ��� �ð� ����
    int n,m;
    cin>>n>>m;
    v.assign(n,0);
    //�Է�
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //���
    long long answer = findingMinTime(v,n,m);
    cout<<answer;
}

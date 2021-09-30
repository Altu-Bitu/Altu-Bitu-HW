#include <iostream>
#include <algorithm>

using namespace std;

const int SIZE = 7;

int n,m;
int arr[SIZE], result[SIZE];

void backtracking(int cnt){ //��Ʈ��ŷ �Լ�
    if(cnt==m){ //cnt�� m ��, result�迭�� ũ�Ⱑ m�� �Ǹ� m���� ���ڰ� �� ���̹Ƿ� ����ϰ� ����
        for(int i=0; i<cnt; i++)
            cout<<result[i]<<' ';
        cout<<'\n';
        return;
    }

    //������ ����� ���� ���ؼ� �ߺ��� ���ؾ��Ѵ�.
    int pre = -1; //������ ����� �� ������ ����

    for(int i=0; i<n; i++){
        if(pre != arr[i]){ //������ ����� ���� ���� ���� ���� �ٸ��ٸ�
            result[cnt] = arr[i]; //result�迭�� �ְ�
            pre = arr[i]; //���� ���� ���� �� �� �����ϰ�
            backtracking(cnt+1); //���� cnt�� �Ѿ�� ����Լ�
        }
    }
}

int main(){
    //�Է�
    cin>>n>>m;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    sort(arr, arr+n);

    backtracking(0);
}

/* 4 2
 * 9 7 9 1
 * �Է� �޴� ���
 *
 * arr={1,7,9,9}
 *
 * backtracking(0)
 * pre=-1
 * -1 != 1
 * result[0] = 1
 * pre = 1
 *
 * backtracking(1)
 * pre = -1
 * -1 != 1
 * result[1] = 1
 * pre = 1
 *
 * backtracking(2)
 * �������ǿ� �ɸ��Ƿ� (result[0], result[1])=(1,1) ����ϰ� return
 *
 * backtracking(1)
 * pre = 1
 * 1 != 7
 * result[1] = 7
 * pre = 7
 * backtracking(2)
 * �������ǿ� �ɸ��Ƿ� (1,7) ����ϰ� return
 *
 * backtracking(1)
 * pre = 7
 * 7 != 9
 * result[1] = 9
 * pre = 9
 * backtracking(2)
 * (1,9) ����ϰ� return
 *
 * backtracking(1)
 * pre = 9
 * 9 == 9
 * �Ѿ
 *
 * => arr[0](= 1)�� ù ��° ���� ��,
 * (1,1), (1,7), (1,9)
 * ������ arr[1](= 7)�� ù ��° ������ �ܰ�� �Ѿ.
 *
 */

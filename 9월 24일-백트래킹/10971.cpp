#include <iostream>

using namespace std;

const int SIZE = 10;
int n;
int w[SIZE][SIZE];
bool check[SIZE]={false};

int result=0;
int k,j;

/* 4
 * 0 10 15 20
 * 5 0 9 10
 * 6 13 0 12
 * 8 8 9 0
 *
 * �̶�� �־��� ��
 * check[0][1][2][3]
 * 0��
 * check[0]=true �ϰ�
 * 10, 15, 20 ������� Ž���Ѵ�.
 * 10 - 0�� 1���̹Ƿ� check[1]=true�ϰ� result + 10, 1������ �̵�
 *      1�࿡�� check true�� 0��, 1�� ���� 2��(9) Ž��
 *      9 - 2���̹Ƿ� check[2]=true�ϰ� result + 9, 2������ �̵�
 *          2�࿡�� check true�� 0,1,2�� ���� 3��(12)�� Ž��
 *          12 -3�����Ƿ� check[3]=true�ϰ� result + 12, 3������ �̵�
 *          (3,0) ��ǥ�� ����. result + 8 =>��� 1=39(10,9,12,8)
 *          check[3]=false
 *      10 ���� - 3���� �̵�
 *      9����
 */

void backtracking(int cnt, int r){//��Ʈ��ŷ �Լ�
    if(cnt==n) {
        k = j;
        //cout<<"k: "<<k<<' '<<w[k][0]<<'\n';
        result += w[k][0];
        cout<<"result: "<<result<<'\n';
        return;
    }
    for(j=0; j<n; j++){

        if(r!=j && !check[j]){
            //cout<<"cnt: "<<cnt<<'\n';
            check[j]=true;
            result += w[r][j];
            //cout<<"Result: "<<result<<'\n';
            backtracking(cnt+1, j);
        }
    }

}

int main(){
    cin>>n;
    for(int i=0; i<n; i++) {
        for (int j = 0; j < n; j++)
            cin >> w[i][j];
    }

    for(int i=0; i<n; i++) {
        result=0;
        check[i] = true;
        backtracking(1, i);

    }
    cout<<result;


}
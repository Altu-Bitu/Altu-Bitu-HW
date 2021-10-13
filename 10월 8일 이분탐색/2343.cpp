#include <iostream>
#include <vector>

using namespace std;

int findingMinSize(vector<int> &v, int n, int m){
    //��緹���� ���̿� ����
    //���� ������ ���պ��� ��緹�� ũ�Ⱑ ũ�� ��緹�� �ϳ�
    //��緹���� ũ�⸦ ���ϼ��� ��緹�� ������ ������ ��
    //���� ��緹�� ������ m���� �Ǵ°�
    //���� ��緹�� ������ m+1���� �Ǵ°�
    /* 9 3
     * 1 2 3 4 5 6 7 8 9
     * ��緹�� ũ�� 45 -> ��緹�� ���� 1
     * ��緹�� ũ�� 44 -> ��緹�� ���� 2 -��緹�� ���� 2���� �� �ִ� ��緹�� ũ��
     * ��緹�� ũ�� 36 -> ��緹�� ���� 2 -��緹�� ���� 2���� �� �ּ� ��緹�� ũ��
     * ��緹�� ũ�� 35 -> ��緹�� ���� 3 -��緹�� ���� 2���� �� �ִ� ��緹�� ũ��
     * ��緹�� ũ�� 17 -> ��緹�� ���� 3 -��緹�� ���� 3���� �� �ּ� ��緹�� ũ��
     */

    //��緹�� �ϳ��� �ִ� ũ��: ���� �� ��, �ּ� ũ��: ���� ���� �� ���� �� ���� ����
    //���Ǹ� �ϳ��� ��ƺ��鼭 mid������ Ŀ���� ��緹�� ������ �ϳ� ������Ų��.
    //cnt�� m���� Ŀ���� ���� ���̸� ũ�� �ؾ��� left=mid+1
    //�ƴϸ� ���� ���̸� �۰� �ؾ��� right=mid-1
    int maxSize=0;
    int lectureSum=0;
    for(int i=0; i<n; i++){
        if(maxSize<v[i])
            maxSize=v[i];
        lectureSum += v[i];
    }

    int left = maxSize;
    int right = lectureSum;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        int cnt=0; //��緹�� ����
        int partSum=0; //�κ���
        for(int i=0; i<n; i++){
            partSum+=v[i];
            if(partSum>mid) { //�κ����� mid���� Ŀ���ٸ�
                cnt++;  //cnt ����
                partSum=v[i];
            }
        }
        if(partSum!=0) //���� ���� ���� �ִ°�
            cnt++; //�ִٸ� cnt ����

        if(cnt>m){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left; //��緹�� ũ���� �ּڰ� ���ؾ��ϹǷ� left�� ����
}

int main(){
    ios::sync_with_stdio(false); //������
    cin.tie(NULL);
    vector<int> v;
    int n, m;
    cin>>n>>m;

    v.assign(n,0);
    //�Է�
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //���
    int answer=findingMinSize(v,n,m);
    cout<<answer;
}

#include <iostream>
#include <array>

using namespace std;

int main(){
    //�ð� ������
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    bool arr[21]={0};
    cin>>n;

    //num�� �Է� �޴� ��ɾ �ְ� �ƴ� ��ɾ �ְ� �ڵ� ���̰� ª�Ƽ� main�� �׳� �ۼ��Ͽ���.
    for(int i=0; i<n; i++){
        string op;
        int num;
        cin>>op;

        if(op=="add") {
            cin>>num;
            arr[num] = 1;//true
        }
        else if(op=="remove") {
            cin>>num;
            arr[num] = 0;
        }
        else if(op=="check"){
            cin>>num;
            cout<<arr[num]<<"\n";
        }
        else if(op=="toggle"){
            cin>>num;
            if(arr[num]==1)
                arr[num]=0;
            else
                arr[num]=1;
        }
        else if(op=="all")
            fill_n(arr,21,1); //�迭 �ʱ�ȭ�� ���� arr[21]={0}�� ó�� ������ ������ �ʱ�ȭ�� ���Ǵ� ���ϴ�.
        else
            fill_n(arr,21,0);
    }
}


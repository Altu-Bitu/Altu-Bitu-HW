#include <iostream>

using namespace std;

int main(){
    int r,b; //�������� �����ڸ�, ������ ������
    int l,w; //ū ��: l, ���� ��: w
    cin>>r>>b;
    //r = 2*l+2*w-4
    //r+b = l*w

    int s = r+b;

    for(int i=3; i<=s; i++){
        if(s%i==0){
            l=s/i;
            w=i;

            if(2*l+2*w-4==r){
                break;
            }
        }
    }

    cout<<l<<' '<<w;

}

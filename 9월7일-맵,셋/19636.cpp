#include <iostream>
#include <cmath>
#include <map>

using namespace std;

//w: 체중, l0: 다이어트 전 일일에너지 섭취량, 일일 기초 대사량, t: 기초 대사량 변화 역치
//d: 다이어트 기간, l: 다이어트 기간 일일 에너지 섭취량, a: 다이어트 기간 일일 활동 대사량
//일일 에너지 섭취량: l, 일일 에너지 소비량: l0+a > t -> 일일 기초대사량: floor((일일 에너지 섭취량-일일 에너지 소비량)/2)+일일 기초대사량

void func1(int w, int l0, int d, int l, int a){ //첫 번째 줄 출력할 함수 - 일일 기초 대사량 변화 고려X
    int w1 = w+(l-(l0+a))*d;
    int l1 = l0;
    bool dd1 = false;
    if(w1<=0 || l1<=0)
        dd1=true;
    if(dd1)
        cout<<"Danger Diet"<<'\n';
    else
        cout<<w1<<' '<<l1<<'\n';
}

void func2(int w, int l0, int t, int d, int l, int a){//두 번째 줄 출력할 함수 - 일일 기초 대사량 변화 고려O
    int w2=w;
    int l2 = l0;

    bool dd2 = false;

    for(int i=0; i<d; i++) {
        w2 = w2 + (l - (l2 + a));
        if (abs(l - (l2 + a)) > t) {
            l2 = l2 + floor(((double)(l - (l2 + a)) / 2));
        }

        if (w2 <= 0 || l2 <= 0)
            dd2 = true;
    }
    if(!dd2) {
        cout << w2 << ' ' << l2 << ' ';
        if(l0-l2>0)
            cout<<"YOYO";
        else
            cout<<"NO";
    }
    else
        cout<<"Danger Diet";

}

int main(){

    int W, L0, T;
    int D, L, A;

    cin>>W>>L0>>T;
    cin>>D>>L>>A;

    func1(W,L0,D,L,A);
    func2(W,L0,T,D,L,A);


}

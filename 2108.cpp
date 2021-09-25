#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool cmp(pair<int,int> p1, pair<int, int>p2){ //���� Ƚ���� ���ٸ� first���� ������������ ����
  if(p1.second==p2.second)
      return p1.first<p2.first;
  return p1.second>p2.second;
}

int main(){
    int n;
    vector<pair<int, int>> v;
    pair<int, int>pa;

    int avg; //������
    int mid; //�߾Ӱ�
    int fre; //�ֺ�
    int range; //����
    double s=0;

    cin>>n;
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        pa = make_pair(num, 1); //<����, Ƚ��>
        v.push_back(pa);
        s+=num;
    }

    sort(v.begin(), v.end()); //���ڰ� ���� ����

    avg = floor((double)s/n+0.5);
    mid = v[n/2].first;
    range = v[n-1].first-v[0].first;

    for(int i=1; i<n; i++){
        if(v[i-1].first == v[i].first){
            v[i-1].second++;
            v[i].second++;
        }
    }

    sort(v.begin(), v.end(), cmp); //����Ƚ�� ���� ����


    if(v[0].second==v[v[0].second].second) //����Ƚ���� ���� ���ڰ��� �ִٴ� ��
        fre=v[v[0].second].first;
    else
        fre=v[0].first;

    cout<<avg<<'\n';
    cout<<mid<<'\n';
    cout<<fre<<'\n';
    cout<<range<<'\n';

    /*for(int i=0; i<n; i++){
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }*/
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���� 3���� ����
//��� ���� �� �� ���� �������� ���� �ִ��� �� ã��
//�ִ��� �������� ���� ���ٸ� ��� ������ �������� ���� ���� �� ã��
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    if(p1.first==p2.first) { //������ ���� ���� ���� ��� ��� ���� ���� ���� ���� ������
        return p1.second < p2.second;
    }
    return p1.first>p2.first; //������ ���� �� ���� ��������
}

int main(){
    vector<int>v;
    vector<pair<int, int>> e; //������ ���� ��, x��
    int n;
    cin>>n;
    int answer=0;

    for(int i=0; i<n; i++){
        int w;
        cin>>w;
        v.push_back(w);
    }

    //�ݷ�:
    /* 5
     * 3 1 2 4 5
     * ����: 33, ���: 31
     * 1->2->3 ������ ���� �����ؾ��ϴµ� �� �ڵ忡���� 4->1->2 �̷��� �����Ѵ�
     * e���� ���� ���� ���� ����� ���� �ƴ϶� e�� �ִ� ��� ��츦 �� �غ����ϴ� ���ϱ�?
     */
    while(v.size()>=3) {
        for (int i = 1; i < v.size() - 1; i++) {
            e.emplace_back(make_pair(v[i - 1] * v[i + 1], v[i]));
            //pair�� ���� e�� ����
        }

        sort(e.begin(), e.end(), cmp); //e����

        //for (int i = 0; i < e.size(); i++) {
        //    cout << e[i].first << ' ' << e[i].second << '\n';
        //}

        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i] == e[0].second) { //e���� ���� �տ� �ִ� ���� v���� �����Ѵ�.
                v.erase(v.begin() + i);
                //cout<<"vsize: "<<v.size()<<'\n';
                break;
            }
        }

        answer += e[0].first;

        e.clear();
    }

    cout<<answer;

}


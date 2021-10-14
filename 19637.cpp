#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<pair<int, string>> v;
map<int, string> map1; //string�� int�� ��� �����ϹǷ� map �ڷᱸ���� �����ϴ�.

void finding(){ //�̺� Ž�� �̿��ؼ� Īȣ ã�� �Լ�
    for (int i = 0; i < m; i++) {
        int power;
        cin >> power;

        int left = 0;
        int right = n-1;
        int mid;
        while (left < right) { //�������̹Ƿ� right�� ��������
            mid = (left+right)/2;

            if(power <= v[mid].first){ //~���� ~�ʰ� ������ �����Ƿ� right=mid -1�� �ƴ� right=mid�� �ۼ��Ѵ�.
                right = mid;
            }
            else if(power > v[mid].first){
                left = mid + 1;
            }
        }
        cout<<v[right].second<<'\n'; //right�� string���� �������.

    }
}

int main() {
    ios::sync_with_stdio(false); //�� 2�� �ڵ�
    cin.tie(NULL); //�� ���� �ð��ʰ� ���.

    cin >> n >> m;
    v.assign(n,pair<int, string> (-1, ""));
    for (int i = 0; i < n; i++) {
        //cin >> v[i].second >> v[i].first;

        //map�� ����
        int num;
        string level;
        cin>>level>>num;
        //map1[num]=level;
        map1.insert(make_pair(num, level)); //pair�� ���� map�� insert�� �Է��ؾ� ���� �۵�
        //cf) map[key] = value;�δ� key�� �ش��ϴ� value�� ���� �����������, ���� ���� �ٲ���� �˾Ƴ� ����� �����ϴ�.
        //map::insert()������ ���� ������ �� �ִ�

    }

    //�񳻸����� ����: ������ ���Ұ� �ٷ� �տ� �ִ� ���Һ��� ũ�ų� ���� ���

    //finding(); //���͸� ����ϴ� ���

    //map����ϴ� ���
    //map�Լ��� iterator ����ؼ� lower_bound �޼ҵ带 ����Ѵ�.
    //�ԷµǴ� ���� ���ų� ū �� �� ���� ���ʿ� �ִ� ������ iterator���� �����Ѵ�.
    //��Ī�� ����ؾ��ϹǷ� iterator->second�� ����Ѵ�.
    //����� upper_bound �޼ҵ�� ���� ������ ū �� �߿� ���� ���ʿ� �ִ� ������ iterator���� �����Ѵٰ� �Ѵ�.
    map<int, string>::iterator it;
    for(int i=0; i<m; i++){
        int input;
        cin>>input;
        it = map1.lower_bound(input); //lower_bound�Լ�
        cout<<it->second<<'\n';
    }

    //map�� �Է� ���� https://hashcode.co.kr/questions/1245/mapinsert%EB%9E%91-%EC%A4%91%EC%97%90-%EC%96%B4%EB%8A%90%EA%B1%B8-%EC%93%B0%EB%8A%94%EA%B2%8C-%EB%A7%9E%EB%8A%94%EA%B1%B4%EA%B0%80%EC%9A%94
    //map�� lower_bound ���� https://velog.io/@doontagi/C-map-%ED%81%B4%EB%9E%98%EC%8A%A4%EC%99%80-upperbound-lowerbound-%EB%A9%94%EC%84%9C%EB%93%9C
}


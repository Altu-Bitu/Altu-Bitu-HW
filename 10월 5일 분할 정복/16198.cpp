#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//구슬 3개씩 묶기
//가운데 기준 양 옆 구슬 에너지의 곱이 최대인 것 찾기
//최대인 에너지의 곱이 같다면 가운데 구슬의 에너지가 가장 작은 것 찾기
bool cmp(const pair<int, int> &p1, const pair<int, int> &p2){
    if(p1.first==p2.first) { //에너지 곱한 값이 같은 경우 가운데 값이 작은 것이 먼저 오도록
        return p1.second < p2.second;
    }
    return p1.first>p2.first; //에너지 곱한 값 기준 내림차순
}

int main(){
    vector<int>v;
    vector<pair<int, int>> e; //에너지 곱한 값, x값
    int n;
    cin>>n;
    int answer=0;

    for(int i=0; i<n; i++){
        int w;
        cin>>w;
        v.push_back(w);
    }

    //반례:
    /* 5
     * 3 1 2 4 5
     * 정답: 33, 결과: 31
     * 1->2->3 순서로 공을 제거해야하는데 내 코드에서는 4->1->2 이렇게 제거한다
     * e에서 가장 앞의 값을 지우는 것이 아니라 e에 있는 모든 경우를 다 해봐야하는 것일까?
     */
    while(v.size()>=3) {
        for (int i = 1; i < v.size() - 1; i++) {
            e.emplace_back(make_pair(v[i - 1] * v[i + 1], v[i]));
            //pair로 만들어서 e에 저장
        }

        sort(e.begin(), e.end(), cmp); //e정렬

        //for (int i = 0; i < e.size(); i++) {
        //    cout << e[i].first << ' ' << e[i].second << '\n';
        //}

        for (int i = 1; i < v.size() - 1; i++) {
            if (v[i] == e[0].second) { //e에서 가장 앞에 있는 값을 v에서 삭제한다.
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


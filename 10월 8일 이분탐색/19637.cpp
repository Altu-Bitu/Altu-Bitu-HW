#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<pair<int, string>> v;

void finding(){ //이분 탐색 이용해서 칭호 찾는 함수
    for (int i = 0; i < m; i++) {
        int power;
        cin >> power;

        int left = 0;
        int right = n-1;
        int mid;
        while (left < right) { //범위값이므로 right에 집중하자
            mid = (left+right)/2;

            if(power <= v[mid].first){ //~이하 ~초과 범위를 가지므로 right=mid -1이 아닌 right=mid로 작성한다.
                right = mid;
            }
            else if(power > v[mid].first){
                left = mid + 1;
            }
        }
        cout<<v[right].second<<'\n'; //right의 string값을 출력하자.

    }
}

int main() {
    ios::sync_with_stdio(false); //이 2개 코드
    cin.tie(NULL); //안 쓰면 시간초과 뜬다.

    cin >> n >> m;
    v.assign(n,pair<int, string> (-1, ""));
    for (int i = 0; i < n; i++) {
        cin >> v[i].second >> v[i].first;
    }

    //비내림차순 정렬: 각각의 원소가 바로 앞에 있는 원소보다 크거나 같을 경우

    finding();

}


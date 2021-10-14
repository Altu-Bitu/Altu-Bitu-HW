#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, m;
vector<pair<int, string>> v;
map<int, string> map1; //string과 int를 묶어서 저장하므로 map 자료구조가 적합하다.

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
        //cin >> v[i].second >> v[i].first;

        //map에 저장
        int num;
        string level;
        cin>>level>>num;
        //map1[num]=level;
        map1.insert(make_pair(num, level)); //pair로 만들어서 map에 insert로 입력해야 정상 작동
        //cf) map[key] = value;로는 key에 해당하는 value가 새로 만들어진건지, 기존 값이 바뀐건지 알아낼 방법이 없습니다.
        //map::insert()에서는 둘을 구분할 수 있다

    }

    //비내림차순 정렬: 각각의 원소가 바로 앞에 있는 원소보다 크거나 같을 경우

    //finding(); //벡터만 사용하는 방법

    //map사용하는 방법
    //map함수에 iterator 사용해서 lower_bound 메소드를 사용한다.
    //입력되는 값과 같거나 큰 값 중 가장 왼쪽에 있는 원소의 iterator값을 리턴한다.
    //명칭을 출력해야하므로 iterator->second를 출력한다.
    //참고로 upper_bound 메소드는 기준 값보다 큰 값 중에 가장 왼쪽에 있는 원소의 iterator값을 리턴한다고 한다.
    map<int, string>::iterator it;
    for(int i=0; i<m; i++){
        int input;
        cin>>input;
        it = map1.lower_bound(input); //lower_bound함수
        cout<<it->second<<'\n';
    }
}


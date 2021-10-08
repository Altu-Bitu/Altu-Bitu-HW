#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct info { //구조체로 출발지, 도착지, 박스 개수를 저장할 수 있도록한다.
    int source, dest, amount;
};

//연산
int greedyBox(int n, int m, int c, vector<info> &box){
    vector<int> truck(n, 0); //각 마을을 지날 때 트럭에 박스가 몇 개 있나
    int ans = 0; //싣게되는 박스의 총 개수

    for (int i = 0; i < m; i++) {
        int max_loaded = 0;
        //현재 박스의 이동 구간에서 가장 많이 실린 박스의 수
        for (int j = box[i].source; j < box[i].dest; j++)
            max_loaded = max(max_loaded, truck[j]); //max_loaded와 j일때의 트럭에 박스가 몇 개있는지 비교, 최댓값 저장

        //이번에 실을 수 있는 박스의 수는 트럭의 용량에서 max_loaded를 뺀 값과, 이번 박스의 개수 중 최솟값
        int loaded = min(box[i].amount, c - max_loaded); //박스 정보 하나에서 박스를 모두 실을 것인가, 일부만 실을 것인가
        ans += loaded; //정답 + 이번에 실을 수 있는 박스의 수

        //트럭에 박스 실음
        for (int j = box[i].source; j < box[i].dest; j++)
            truck[j] += loaded; //현재 싣고 다니는 박스 수 + 이번에 실을 수 있는 박스의 수
    }
    return ans; //정답 리턴
}

/**
 * 그리디 알고리즘인 이유
 * 조건 3: 박스들 중 '일부'만 배송할 수도 있다.
 *
 * 1. 트럭은 1번 마을부터 출발
 * 2. 트럭에 여유 공간이 많아야 박스를 많이 실을 수 있음
 * -> 도착지가 1번 마을에서 가까운 박스 먼저 싣는다
 * -> 도착지 기준 오름차순 정렬
 *
 * 도착지 기준 오름차순 정렬을 해야 하는 이유
 * 1. 시작지 기준 오름차순 정렬을 할 경우, 내리는 마을이 멀어지면 트럭이 오래 박스를 싣게 되어 비효율적
 * 2. 도착지 기준 오름차순 정렬을 할 경우, 박스를 빨리 내리게 되어 효율적
 * 3. 시작지-도착지의 거리를 기준으로 정렬을 할 경우, 사이 거리는 짧지만 도착지가 먼 경우를 처리하지 못함
 */
int main() {
    int n, c, m;

    //입력
    cin >> n >> c >> m; //마을 수, 트럭 용량, 박스 정보의 개수
    vector<info> box(m); //box 정보 저장할 벡터
    for (int i = 0; i < m; i++) //각 박스 정보에 대한 데이터를 저장한다.
        cin >> box[i].source >> box[i].dest >> box[i].amount;

    //연산
    sort(box.begin(), box.end(),
         [](const info &i1, const info &i2) { //익명 함수로 sort함수 안에 compare 정의
             return i1.dest < i2.dest; //도착지가 빠른 순서대로 정렬한다.
         });

    //연산 & 출력
    cout<<greedyBox(n, m, c, box);
}
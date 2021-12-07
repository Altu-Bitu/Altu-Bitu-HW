#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> tp;

vector<int> parent;

//Find 연산
int findParent(int node) { //어느 집합에 속해 있는가
    if (parent[node] < 0) //값이 음수면 루트 정점
        return node;
    return parent[node] = findParent(parent[node]); //그래프 압축하며 루트 정점 찾기
}

//Union 연산
bool unionInput(int x, int y) {
    int xp = findParent(x); //x의 루트 노드 
    int yp = findParent(y); //y의 루트 노드

    if (xp == yp) //같은 집합에 있다면 유니온 할 수 없음
        return false; //같은 집합이다.
    //다른 집합에 있다면 더 작은 노드를 루트로 union
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp]; //집합 크기 증가
        parent[yp] = xp; //yp의 루트 노드 바꾸기
    } else { //새로운 루트 yp
        parent[yp] += parent[xp]; //집합 크기 증가
        parent[xp] = yp; //xp의 루트 노드 바꾸기
    }
    return true; //다른 집합이다.
}

int kruskal(int n, int idx, vector<tp> &edges) {//크루스칼
    int cnt = 0, sum = 0;
    for (int i = idx; i < edges.size(); i++) {
        if (cnt == n - 1) //n-1개의 간선을 모두 연결함
            break;
        int dist = get<0>(edges[i]);
        int x = get<1>(edges[i]);
        int y = get<2>(edges[i]);

        if (unionInput(x, y)) { //union 수행
            cnt++; //union 횟수 증가
            sum += dist; //가중치 총합 증가
        }
    }
    if (cnt < n - 1) //mst를 만들 수 없음
        return 0; //0리턴
    return sum; //mst 만들 수 있으면 가중치 총합 리턴
}

/**
 * MST 알고리즘을 여러 번 실행해도 될까?
 * 1. 크루스칼 알고리즘의 시간 복잡도는 O(ElogE)
 *    이는 오직 간선을 정렬하는 연산의 시간 복잡도!
 *    즉, 모든 간선을 한 번 정렬해서 저장해두면 이후 몇 번의 알고리즘을 수행하여도 연산 시간에 큰 영향이 없음
 * 2. 간선 재사용을 위해 우선순위 큐가 아닌 벡터에 저장하고 크루스칼 알고리즘 k번 실행
 * 3. 매번 크루스칼을 수행할 때마다 제일 먼저 추가한 간선을 제외함
 *    -> 제외될 간선은 배열의 0번째 간선부터 1, 2, 3번째 간선으로 순차적 제외
 * 4. 만약 한 번 MST를 만들 수 없다는게 확인됐다면 이후에도 MST를 만들 수 없으므로 flag 변수로 불필요한 연산 절약
 */
int main() {
    int n, m, k, x, y; //정점 개수, 간선 개수, 턴의 수

    cin >> n >> m >> k;
    vector<tp> edges; //재사용할거라 우선순위 큐가 아닌 벡터에 저장
    for (int i = 1; i <= m; i++) {
        cin >> x >> y; //간선 정보 - 두 정점의 번호
        edges.emplace_back(i, x, y); //간선 가중치: i
    } 

    bool flag = false; //flag는 false로 초기화 - mst 만들 수 있다. 의미
    for (int i = 0; i < k; i++) { //k번의 턴
        if (flag) { //더이상 mst를 만들 수 없음
            cout << 0 << ' '; //0 출력
            continue;
        }
        parent.assign(n + 1, -1); //초기화
        int ans = kruskal(n, i, edges); //kruskal함수에서 가중치 총합 또는 0을 받음
        if (ans == 0) //mst를 만들 수 없어 0을 리턴 받으면
            flag = true; //flag를 true로 만든다.
        cout << ans << ' '; //mst를 만들 수 있다면 가중치 총합 리턴
    }
}
#include <iostream>
#include <queue>

using namespace std;
const int SIZE = 100000;

int zeroOneBfs(int n, int k) {
    vector<int> check(SIZE + 1, 0); //정점에 도착한 시간
    deque<int> dq; //덱 이용
    int ans = 0; //수빈이가 동생을 찾는 가장 빠른 시간

    //시작 위치 초기화
    check[n] = 1; //시작 위치를 1초로 초기화
    dq.push_back(n); //덱에 push

    while (!dq.empty()) {
        int x = dq.front(); //현재 탐색하려는 위치
        dq.pop_front(); //덱에서 pop

        if (x == k) { //동생 찾으면 탐색 종료. 시작 위치를 1로 초기화 했기 때문에 1을 빼줌
            ans = check[x] - 1; //리턴할 ans
            break; //목적지 도달했으므로 종료
        }

        int next = x * 2; //순간이동 먼저 검사
        if (next <= SIZE && !check[next]) { //순간이동한 위치가 전체 범위 내에 있고 방문하지 않은 위치라면 이동
            check[next] = check[x]; //next에 도착한 시간을 x에 도착한 시간으로 바꿔주고 (순간이동이므로 시간에 변화x)
            dq.push_front(next); //덱의 front에 next를 push
        }

        next = x - 1; //뒤로 걷기
        if (next >= 0 && !check[next]) { //뒤로 걸은 위치가 전체 범위 내에 있고 방문하지 않은 위치라면
            check[next] = check[x] + 1; //걸었으므로 x에 도착한 시간 +1초
            dq.push_back(next); //덱의 back에 next를 push
        }

        next = x + 1; //앞으로 걷기
        if (next <= SIZE && !check[next]) { //앞으로 걸은 위치가 전체 범위 내에 있고 방문하지 않은 위치라면
            check[next] = check[x] + 1; //걸었으므로 x에 도착한 시간 +1초
            dq.push_back(next); //덱의 back에 next를 push
        }
    }
    return ans; //ans 리턴
}

/**
 * x좌표 위에서 2*x, x-1, x+1의 위치로 계속 이동하며 탐색
 * 이동에 대한 가중치는 0, 1 두 가지이므로 다익스트라가 아니라 덱으로 풀 수 있음 (0-1 BFS)
 *
 * !주의!
 * 순간이동으로 이동하는 경우를 걸어서 이동하는 경우보다 먼저 고려해야 함
 * -> 어차피 순간이동은 push_front 되는데 왜?
 * -> 1에서 2로 이동할 땐 걷는 것도 가능하고 순간이동도 가능함
 *    걷는 방법을 먼저 고려하면 check 배열이 갱신되어 순간이동을 고려할 수 없음
 */
int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //연산 & 출력
    cout << zeroOneBfs(n, k) << '\n';
}
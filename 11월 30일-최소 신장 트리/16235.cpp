#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;
typedef vector<vector<int>> matrix; //2차원 벡터
typedef tuple<int, int, int> tp; //나무 나이, 행 좌표, 열 좌표 저장 

queue<tp> spring(matrix &land, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) { //봄: 자신의 나이만큼 양분을 먹고 나이 1 증가
    queue<tp> dead_tree; //죽은 나무 담을 큐
    int size = tree.size();
    while (size--) { //모든 나무 검사
        int age = get<0>(tree.front()); //나이
        int row = get<1>(tree.front()); //행
        int col = get<2>(tree.front()); //열
        tree.pop_front(); //맨 앞에서 pop

        if (land[row][col] < age) { //자신의 나이만큼 양분을 먹을 수 없다면
            dead_tree.push({age, row, col}); //나무가 죽는다. -> dead_tree 큐에 push
            continue; //나무가 죽으면 다음 연산 할 필요 없으므로 continue
        }

        //자신의 나이만큼 양분을 먹었으면
        land[row][col] -= age; //현재 땅의 양분에서 자신의 나이만큼 빼기
        tree.emplace_back(age + 1, row, col); //나이는 1증가, 행/열 좌표는 그대로해서 tree 덱의 맨 뒤에 넣기
        if ((age + 1) % 5 == 0) //나이가 5의 배수라면 인접한 8개의 칸에 나무 번식
            breeding_tree.push({row, col}); //번식할 나무 담는 큐에 넣기
    }
    return dead_tree; //죽은 나무 큐 리턴
}

void summer(queue<tp> &dead_tree, matrix &land) { //여름: 죽은 나무의 나이의 1/2이 양분이 된다.
    while (!dead_tree.empty()) {
        int age = get<0>(dead_tree.front()); //죽은 나무의 나이
        int row = get<1>(dead_tree.front()); //죽은 나무의 행 위치
        int col = get<2>(dead_tree.front()); //죽은 나무의 열 위치
        dead_tree.pop(); //pop
        land[row][col] += (age / 2); //죽은 나무의 나이의 1/2이 양분이 된다.
    }
}

void fall(int n, deque<tp> &tree, queue<pair<int, int>> &breeding_tree) { //가을: 나무 나이가 5의 배수이면 인접한 8개의 칸에 나무 번식
    //인접한 8개의 칸의 좌표
    int dr[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dc[8] = {0, 0, -1, 1, -1, 1, -1, 1};

    while (!breeding_tree.empty()) { //번식할 나무의 큐 이용
        int row = breeding_tree.front().first; //번식할 나무의 행
        int col = breeding_tree.front().second; //번식할 나무의 열
        breeding_tree.pop(); //pop

        for (int j = 0; j < 8; j++) { //인접한 8개 칸을 순회한다.
            int nr = row + dr[j]; //인접 칸의 행 좌표
            int nc = col + dc[j]; //인접 칸의 열 좌표
            if (nr < 0 || nr >= n || nc < 0 || nc >= n) //칸 좌표 범위 체크
                continue;
            tree.push_front({1, nr, nc}); //새로 생긴 나무 tree에 push
        }
    }
}

void winter(int n, matrix &a, matrix &land) { //겨울: 로봇이 땅에 양분 추가
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            land[i][j] += a[i][j]; //land의 각 좌표별로 a의 양분을 더한다.
}

/**
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * a: 로봇(S2D2)가 겨울에 주는 양분의 양
 * land: 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */

int main() {
    int n, m, k, x, y, z; //땅 한 변의 길이, 나무 정보 개수, k년 후, 나무위치 x좌표, 나무위치 y좌표, 나무 나이

    //입력
    cin >> n >> m >> k;
    matrix a(n, vector<int>(n, 0)); //양분
    matrix land(n, vector<int>(n, 5)); //처음 양분 모든 칸에 5로 초기화
    queue<pair<int, int>> breeding_tree; //번식할 나무 큐
    deque<tp> tree; //나무 덱

    //양분 입력
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    //트리 정보 입력
    while (m--) {
        cin >> x >> y >> z;
        tree.emplace_back(z, x - 1, y - 1); //(0, 0)부터 시작하도록 구현하기위해 1을 빼준 인덱스에 접근
    }

    //연산
    sort(tree.begin(), tree.end()); //어린 나이 순으로 정렬
    while (k--) { //k년
        queue<tp> dead_tree = spring(land, tree, breeding_tree); //봄이 지나고 죽은 나무
        summer(dead_tree, land); //죽은 나무-> 양분
        fall(n, tree, breeding_tree); //번식
        winter(n, a, land); //양분 추가
    }

    //출력
    cout << tree.size(); //k년 후, 살아있는 나무 개수 출력
}
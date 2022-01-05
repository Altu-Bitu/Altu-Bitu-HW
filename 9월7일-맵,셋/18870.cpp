#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int left, int right, int target, vector<int> &sorted){
    while (left <= right) { //left, right 위치가 반전되면 break
        int mid = (left + right) / 2; //중앙값
        if (target == sorted[mid]) //target의 인덱스를 찾음
            return mid;
        if (target > sorted[mid]) //target이 오른쪽에 있음
            left = mid + 1;
        else if (target < sorted[mid]) //target이 왼쪽에 있음
            right = mid - 1;
    }
    return -1; //target을 찾지 못함
}

int main(){
    set<int> s;
    vector<int> v, sorted;
    int n;
    cin>>n;

    v.assign(n,0);
    for(int i=0; i<n; i++){
        cin>>v[i];
        s.insert(v[i]);
    }

    for(auto iter: s){
        sorted.push_back(iter);
    }

    for (int i = 0; i < n; i++){
        cout << binarySearch(0, sorted.size() - 1, v[i], sorted) << ' ';
    }
}

/*
Xi를 좌표 압축한 결과 X'i의 값은 Xi > Xj를 만족하는 서로 다른 좌표의 개수와 같아야 한다.
라고 주어졌으므로 즉, 중복이 없는 상태에서 Xi>Xj를 만족하는 좌표의 개수를 세면 된다.
1-1. 중복이 없고 크기를 비교해야하므로 set를 사용한다. 출력할 때 입력한 순서에 맞춰 출력해야하므로 vector에도 저장을 한다.
1-2. set에서 target의 인덱스를 구하기 위해 set의 원소를 vector에 옮기고 시간을 줄이기 위해 이분탐색으로 target을 찾는다.
(인덱스가 0부터 시작하므로 순서대로 정렬한 벡터에서 target의 인덱스가 X'i가 된다.) 

*/
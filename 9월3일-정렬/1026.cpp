#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int func(int n, vector <int> v1, vector<int> v2){
    int num;
    int result = 0;
    for (int i = 0; i < n; i++) {

        cin >> num;
        v1.push_back(num);
    }

    for (int i = 0; i < n; i++) {

        cin >> num;
        v2.push_back(num);
    }

    //A 오름차순 정렬, B 내림차순 정렬해서 곱해야 최솟값을 구할 수 있음.
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<>());

    for (int i = 0; i < n; i++) {
        result += v1[i] * v2[i];
    }

    return result;
}

int main() {
    int N;
    vector<int> A;
    vector<int> B;

    cin >> N;

    int answer = func(N, A, B);

    cout << answer;
}

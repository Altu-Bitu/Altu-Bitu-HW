#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int N;
    vector<int> A;
    vector<int> B;
    int result = 0;
    int num;
    cin >> N;

    for (int i = 0; i < N; i++) {

        cin >> num;
        A.push_back(num);
    }

    for (int i = 0; i < N; i++) {

        cin >> num;
        B.push_back(num);
    }

    //A 오름차순 정렬, B 내림차순 정렬해서 곱해야 최솟값을 구할 수 있음.
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<>());

    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }
    cout << result;
}

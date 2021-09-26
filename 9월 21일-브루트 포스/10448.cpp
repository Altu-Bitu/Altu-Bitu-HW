#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool triangularSum(vector<int> v, int num) //모든 경우의 삼각수 합을 계산
{
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v.size(); j++) {
            for (int k = 0; k < v.size(); k++) {
                if (v[i] + v[j] + v[k] == num)
                    return true;
            }
        }
    }
    return false;
}


int main() {
    vector<int> v;
    int t, k;

    cin >> t;

    for (int i = 1; i <= 44; i++) {
        v.push_back(i * (i + 1) / 2);
    }

    for (int i = 0; i < t; i++) {
        cin >> k;

        bool result = triangularSum(v, k);
        if (result)
            cout << "1\n";
        else
            cout << "0\n";
    }
}
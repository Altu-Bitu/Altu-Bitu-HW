#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeTriangularNum(vector<int> v){//삼각수 만들어서 벡터에 저장
    for (int i = 1; i <= 44; i++) {
        v.push_back(i * (i + 1) / 2);
    }
}

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

    makeTriangularNum(v); //삼각수를 만들어서 저장
    for (int i = 0; i < t; i++) {
        cin >> k;

        bool result = triangularSum(v, k);
        cout<<result<<'\n';
        //result값이 true이면 1로, false이면 0으로 출력됨. 숫자로 바꿀 필요 없음.
    }
}
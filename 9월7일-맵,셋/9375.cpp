#include <iostream>
#include <map>

using namespace std;

/**
 * 같은 종류의 옷이 각각 몇 벌 있는지만 알면 됨
 */
int main() {
    int t, n;
    string outfit, kind;

    cin >> t;
    while (t--) {
        map<string, int> m;

        //입력
        cin >> n;
        while (n--) {
            cin >> outfit >> kind;
            m[kind]++;
        }

        //연산
        int result = 1;
        for (auto iter = m.begin(); iter != m.end(); iter++)
            result *= (iter->second + 1); //해당 종류의 옷을 입기(iter->second) + 안 입기(1)
            //테스트 케이스에서 headgear: hat 쓰기, turban 쓰기, 둘 다 안 쓰기
            //eyewear: sunglass 쓰기, 안 쓰기
            //전체 경우의 수: 3*2 - 1(알몸인 경우) = 5

        //출력
        //알몸인 경우 제외
        cout << result - 1 << '\n';
    }
}
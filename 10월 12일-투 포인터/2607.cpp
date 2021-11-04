#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 26; //전체 알파벳 개수: 26개

//알파벳별 등장횟수 저장
vector<int> alphaMap(string str) {
    vector<int> result(SIZE, 0);
    for (int i = 0; i < str.size(); i++)
        result[str[i] - 'A']++; //str의 각 문자별 등장 횟수 저장, 인덱스: str[i] - 'A'
    return result; //result 벡터 리턴
}

/**
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */
int main() {
    int n, ans = 0;
    string source, target;

    //입력
    cin >> n >> source; //개수, 기준 문자열

    //연산
    vector<int> source_alpha = alphaMap(source); //기준 문자열에서의 알파벳별 등장횟수 저장 배열
    while (--n) {
        cin >> target; //비교 대상 문자열

        int diff = 0; 
        vector<int> target_alpha = alphaMap(target); //비교 대상 문자열에서의 알파벳별 등장횟수 저장 배열
        for (int i = 0; i < SIZE; i++) //두 단어의 차이 계산
            diff += abs(source_alpha[i] - target_alpha[i]); //절댓값으로 해야함. 절댓값 안 하면 음수가 계산될 수 있어서 문제 발생
        if (diff <= 1 || (diff == 2 && source.size() == target.size())) //문자를 더하거나, 빼거나, 바꾸거나(+비교 기준 문자열과 비교 대상 문자열 크기 같아야함.)
            ans++; //정답 개수 증가
    }

    //출력
    cout << ans;
}
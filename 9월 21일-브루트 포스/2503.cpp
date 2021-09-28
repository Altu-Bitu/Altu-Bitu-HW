#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //typedef로 pair를 ci로 부르기로 하자.
//<스트라이크 개수, 볼 개수>

//구조체 이용
struct baseball {
    string num;       //서로 다른 세 자리 수 - string으로 저장해여 연산하기 편함.
    int strike, ball; //스트라이크 개수, 볼 개수
};

ci cntStrikeBall(string &s1, string &s2) { //& 이용-참조
    int strike_cnt = 0; //s1과 s2사이의 strike 개수
    int ball_cnt = 0;   //s1과 s2사이의 ball 개수

    for (int i = 0; i < 3; i++) {//세 자리 수
        if (s1[i] == s2[i]) //위치+수 정확히 일치 -> 스트라이크
            strike_cnt++; //스트라이크 개수 증가
        else if (s1.find(s2[i]) != s1.npos) //위치 다른데 수가 존재 -> 볼
            ball_cnt++; //볼 개수 증가
    }

    return ci(strike_cnt, ball_cnt); //스트라이크 개수, 볼 개수 정보 담은 ci 리턴
}

int game(int n, vector<baseball> &question) { //& 이용 - 참조
    int ans = 0; //정답 개수

    //i와 j 각각의 스트라이크 개수, 볼 개수를 구해서 일일이 다 비교해본다.
    for (int i = 123; i <= 987; i++) {//각 자리수 서로 다름 -> i는 123부터 시작, 987까지 검사
        bool check = true; //정답인지 확인할 지표 check - true로 초기화해놓음.
        string s1 = to_string(i);  //정답인지 확인할 수

        if (s1[0] == '0' || s1[1] == '0' || s1[2] == '0') //0이 하나라도 있다면
            continue; //문제 조건에 해당하지 않음
        if (s1[0] == s1[1] || s1[0] == s1[2] || s1[1] == s1[2]) //서로 같은 수 하나라도 있다면
            continue; //문제 조건에 해당하지 않음

        for (int j = 0; j < n; j++) {
            string s2 = question[j].num; //질문으로 들어온 수
            ci cnt = cntStrikeBall(s1, s2); //s1과 s2사이의 스트라이크와 볼 개수
            if (cnt.first != question[j].strike || cnt.second != question[j].ball) { //스트라이크와 볼 개수 하나라도 다르면
                check = false; //정답 아니다.
                break; //정답 아니므로 break하고 나가서 i 증가 -> 다른 수 검사
            }
        }

        if (check) //정답일 수 있다.
            ans++; //정답 가능성 있는 숫자 개수 증가
    }

    return ans;
}

/**
 * [숫자 야구]
 * 서로 다른 세 자리 수에서 위치+수 같으면 스트라이크, 위치는 다르고 수가 존재하면 볼
 * n개의 질문으로 수와 스트라이크와 볼 개수가 주어질 때, 이를 모두 만족하는 서로 다른 세 자리 정답 수의 개수
 *
 * [풀이]
 * 서로 다른 세 자리수는 123 ~ 987이 가능하다. 이는 총 865가지
 * 질문 n의 범위는 최대 100
 * 따라서 123부터 하나씩 증가시키며 정답이 되는지 검사해도 865 * 100 * 3(자릿수)으로 접근 충분히 가능!
 */

int main() {
    int n;

    //입력
    cin >> n;

    vector<baseball> question(n); //물어보는 질문들 저장, 자료형은: baseball 구조체
    //질문할 숫자, 스트라이크 개수, 볼 개수 입력
    for (int i = 0; i < n; i++) {
        cin >> question[i].num >> question[i].strike >> question[i].ball;
    }

    //연산 + 출력
    cout << game(n, question); //정답 가능성 있는 숫자 개수 출력

    return 0;
}
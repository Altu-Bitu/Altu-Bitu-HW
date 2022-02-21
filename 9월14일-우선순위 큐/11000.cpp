#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> ci;

/**
 * [필요 강의실이 최소가 되도록 수업 배치]
 * 1. 먼저 시작시간을 기준으로 오름차순 정렬 (정렬)
 * 2. 종료 시간이 가장 빠른 수업과 현재 수업의 시작시간 비교해서 같은 강의실 배치 가능한지 검사 (우선순위 큐)
 */

int arrayRoom(int n, vector<ci> lecture){
    priority_queue<int, vector<int>, greater<>> pq; //종료 시간 오름차순 정렬 저장
    int answer = 0; //강의실 개수

    pq.push(lecture[0].second);
    answer++;

    for(int i=1; i<n; i++){
        if(lecture[i].first >= pq.top()){ //시작시간이 앞에 강의 종료 시간 이후 => 연속 배치 가능한 경우
            pq.pop();
        }
        else{ //아니면 새 강의실 필요
            answer++;
        }
        pq.push(lecture[i].second); //종료시간 pq에 넣기 => pop되고 들어가면 기존 강의실 정보 갱신 아니면 새로운 강의실 정보 저장되는 형태
    } 
    return answer; //만들어진 강의실 개수 리턴
}

int main(){
    int n;
    
    cin>>n;
    vector<ci> lecture(n, ci(0,0));
    for(int i=0; i<n; i++){
        cin>>lecture[i].first>>lecture[i].second;
    }

    sort(lecture.begin(), lecture.end());

    cout<<arrayRoom(n, lecture)<<'\n';

    return 0;
}
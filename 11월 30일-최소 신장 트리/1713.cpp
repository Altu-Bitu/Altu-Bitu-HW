#include <iostream>
#include <map>

using namespace std;

typedef pair<int, int> ci;
map<int, ci> stu; //사진틀 - 학생, 추천횟수, 들어간 시점 - 학생으로 바로 찾기 위해 map 사용

//사진틀이 꽉 찬 경우 - 제거
int deleteStu(){
    pair<int, int> pr; //map의 처음 것 정보 저장
    int idx = stu.begin()->first; //처음 - 학생
    pr = stu.begin()->second; //처음 - 추천횟수, 들어간 시점 

    for(auto item : stu){ //map 순회
        if(item.second.first < pr.first){ //1. 추천횟수가 적은 것 삭제 대상
            idx = item.first;
            pr = item.second;
        }
        if(item.second.first == pr.first){
            if(item.second.second<pr.second){ //2. 추천횟수가 같다면 들어간 시점이 작은 것 삭제 대상
                idx = item.first;
                pr = item.second;
                    
            }
        }
    }
    return idx;
}

//사진틀에 추천한 학생이 없는 경우 - 학생 넣기
void insertStu(int n, int num, int time){
    if(stu.size()<n){ //현재 사진틀 개수가 n보다 작은 경우 그냥 추가- 정상
        stu[num].first=1; //추천 횟수
        stu[num].second=time; //들어간 시점
    }
    else{ //예외 - 사진틀이 꽉 차서 기존의 것 지워야 되는 경우
        int idx = deleteStu();
        stu.erase(idx); //1,2 조건에 따라 map에서 idx 삭제
        //num 정보 추가
        stu[num].first=1;
        stu[num].second=time;
    }
}

//학생 추천
void recomStu(int n, int m){
    for(int i=0; i<m; i++){
        int num;
        cin>>num;

        if(stu.find(num)==stu.end()){ //stu에 num학생이 없는 경우 - 추가해야함
            insertStu(n, num, i);           
        }
        else{//map에 있다면 추천횟수만 증가
            stu[num].first++;
        }

    }
}

int main(){
    int n, m;
    cin>>n>>m;

    recomStu(n,m); //학생 추천

    //사진틀에 있는 학생 출력
    for(auto item: stu){
        cout<<item.first<<' ';
    }
}

//참고: https://steady-life.tistory.com/m/61
//학생 번호를 바로바로 사용하면 효율적일 것 같아 map을 쓰기로 결정했지만 구현을 하기가 어려워 도움을 받았습니다.
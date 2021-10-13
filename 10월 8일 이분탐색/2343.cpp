#include <iostream>
#include <vector>

using namespace std;

int findingMinSize(vector<int> &v, int n, int m){
    //블루레이의 길이에 집중
    //강의 길의의 총합보다 블루레이 크기가 크면 블루레이 하나
    //블루레이의 크기를 줄일수록 블루레이 개수는 증가할 것
    //언제 블루레이 개수가 m개가 되는가
    //언제 블루레이 개수가 m+1개가 되는가
    /* 9 3
     * 1 2 3 4 5 6 7 8 9
     * 블루레이 크기 45 -> 블루레이 개수 1
     * 블루레이 크기 44 -> 블루레이 개수 2 -블루레이 개수 2개일 때 최대 블루레이 크기
     * 블루레이 크기 36 -> 블루레이 개수 2 -블루레이 개수 2개일 때 최소 블루레이 크기
     * 블루레이 크기 35 -> 블루레이 개수 3 -블루레이 개수 2개일 때 최대 블루레이 크기
     * 블루레이 크기 17 -> 블루레이 개수 3 -블루레이 개수 3개일 때 최소 블루레이 크기
     */

    //블루레이 하나의 최대 크기: 강의 총 합, 최소 크기: 단일 강의 중 가장 긴 것의 길이
    //강의를 하나씩 담아보면서 mid값보다 커지면 블루레이 개수를 하나 증가시킨다.
    //cnt가 m보다 커지면 강의 길이를 크게 해야함 left=mid+1
    //아니면 강의 길이를 작게 해야함 right=mid-1
    int maxSize=0;
    int lectureSum=0;
    for(int i=0; i<n; i++){
        if(maxSize<v[i])
            maxSize=v[i];
        lectureSum += v[i];
    }

    int left = maxSize;
    int right = lectureSum;
    int mid;
    while(left<=right){
        mid=(left+right)/2;
        int cnt=0; //블루레이 개수
        int partSum=0; //부분합
        for(int i=0; i<n; i++){
            partSum+=v[i];
            if(partSum>mid) { //부분합이 mid보다 커진다면
                cnt++;  //cnt 증가
                partSum=v[i];
            }
        }
        if(partSum!=0) //끝에 남은 것이 있는가
            cnt++; //있다면 cnt 증가

        if(cnt>m){
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return left; //블루레이 크기의 최솟값 구해야하므로 left를 리턴
}

int main(){
    ios::sync_with_stdio(false); //빠르게
    cin.tie(NULL);
    vector<int> v;
    int n, m;
    cin>>n>>m;

    v.assign(n,0);
    //입력
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    //출력
    int answer=findingMinSize(v,n,m);
    cout<<answer;
}

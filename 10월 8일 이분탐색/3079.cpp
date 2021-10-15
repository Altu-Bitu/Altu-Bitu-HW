#include <iostream>
#include <vector>

using namespace std;

long long findingMinTime(vector<long long> &v, int n, int m){
    //이분 탐색으로 최소 시간 찾기
    long long answer=0;
    long long left = 1; //1명*1초
    long long right = 1e9*1e9; //1e9명*1e9초
    long long mid;
    while(left<=right){
        mid = (left+right)/2; //예상 총 시간
        long long cnt=0;
        for(int i=0; i<n; i++){
            //총 시간 -> 사람 수로 생각해보기 (각 입국심사대 시간으로 나누기)
            cnt += mid/v[i]; //예상 총 시간동안 각 입국심사대에서 심사할 수 있는 사람 수의 합 구하기
            if(cnt>=m)//m이상이 되면 break
                break;
        }

        if(cnt>=m){
            answer = mid; //일단 정답에 mid 저장해놓고
            right = mid-1; //최소 시간 구하는 것이므로 더 작은 시간에서도 성립하는지 확인 필요
        }
        else{
            left = mid+1;
        }
    }
    return answer;
}

int main(){
    //빠르게
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> v; //각 입국심사대에서 걸리는 시간 저장
    int n,m;
    cin>>n>>m;
    v.assign(n,0);
    //입력
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    //출력
    long long answer = findingMinTime(v,n,m);
    cout<<answer;
}

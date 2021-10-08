#include <iostream>
#include <vector>

using namespace std;

void switching(vector<int> &v, int sex, int num){
    if(sex==1){//남학생이면 자기 번호의 배수의 스위치 상태를 바꾼다.
        for(int i=num; i<v.size(); i+=num){
             if(v[i]==1)
                 v[i]=0;
             else
                 v[i]=1;
         }
    }
    else{ //여학생이면 자기 기준 대칭인 최대 경우 찾아서 모두 상태 바꿔버림
        if(num==1 || num==v.size()-1){ //받은 스위치가 맨 끝인 경우, 자기 자신만 바꿈
            if(v[num]==1)
                v[num]=0;
            else
                v[num]=1;
        }
        else{//받은 스위치가 맨 끝이 아닌 경우, 양 옆부터 검사
            int left = num; //num 기준 왼쪽 표시할 것
            int right = num; //num 기준 오른쪽 표시할 것

            while(left>=1 && right<=v.size()-1){//조건-양 끝까지 비교해야하므로 이렇게 범위를 정한다.
                if(v[left]!=v[right]) {
                    break;
                }
                left--;
                right++;
            }
            //결과: left는 대칭 범위의 왼쪽 끝보다 하나 더 왼쪽으로, right는 오른쪽 끝보다 하나 더 오른쪽으로 간 것

            //범위 내의 수 전부 상태 바꾸기
            for(int i=left+1; i<right; i++){ //범위 주의! ->대칭 범위: left+1 ~ right-1
                if(v[i]==1)
                    v[i]=0;
                else
                    v[i]=1;
            }
        }

    }
}

int main(){
    int n,s;
    cin>>n;
    vector<int> v(n+1);

    //스위치 상태를 인덱스 1번부터 저장
    v[0]=-1;
    for(int i=1; i<n+1; i++)
        cin>>v[i];

    cin>>s; //학생 정보를 pair로 vector에 저장
    vector<pair<int,int>> sv(s);
    for(int i=0; i<s; i++){
        int sex, num;
        cin>>sex>>num;
        sv[i]=(make_pair(sex,num));
    }

    //학생 정보를 돌면서 스위치 상태 바꾸기
    for(int i=0; i<s; i++){
        switching(v, sv[i].first, sv[i].second);
    }
    //출력 - 20개씩-조건 필요
    for(int i=1; i<v.size(); i++){
        cout<<v[i]<<' ';
        if(i>=20 && i%20==0)
            cout<<'\n';
    }
}
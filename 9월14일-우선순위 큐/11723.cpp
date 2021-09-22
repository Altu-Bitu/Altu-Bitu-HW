#include <iostream>
#include <array>

using namespace std;

int main(){
    //시간 빠르게
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    bool arr[21]={0};
    cin>>n;

    //num을 입력 받는 명령어도 있고 아닌 명령어도 있고 코드 길이가 짧아서 main에 그냥 작성하였다.
    for(int i=0; i<n; i++){
        string op;
        int num;
        cin>>op;

        if(op=="add") {
            cin>>num;
            arr[num] = 1;//true
        }
        else if(op=="remove") {
            cin>>num;
            arr[num] = 0;
        }
        else if(op=="check"){
            cin>>num;
            cout<<arr[num]<<"\n";
        }
        else if(op=="toggle"){
            cin>>num;
            if(arr[num]==1)
                arr[num]=0;
            else
                arr[num]=1;
        }
        else if(op=="all")
            fill_n(arr,21,1); //배열 초기화에 쓰기 arr[21]={0}은 처음 선언할 때에만 초기화로 사용되는 듯하다.
        else
            fill_n(arr,21,0);
    }
}


#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int bigger(vector<string> &v, int n, int m){
    int diff=999999, i;
     for(i=n; i>=0; i--){
        bool flag=true;
        string str = to_string(i);

        for(int j=0; j<m; j++){
            if(str.find(v[j],0)!=string::npos){
                flag=false;
                break;
            }
        }
        if(!flag){
            continue;
        }

        if(diff>=abs(n-i)){
            diff = abs(n-i);
            //cout<<"bigger- i: "<<i<<" diff: "<<diff<<'\n';  
            break;
        }
        // else{
        //     break;
        // }
        if(i==0){
            break;
        }
    }
    string str = to_string(i);
    int cnt = str.size();
    //cout<<"i: "<<i<<" cnt: "<<cnt<<'\n';
    return cnt+diff;
}

int smaller(vector<string> &v, int n, int m){
     int diff=999999, i;
     for(i=n; i<=999999; i++){
        bool flag=true;
        string str = to_string(i);

        for(int j=0; j<m; j++){
            if(str.find(v[j],0)!=string::npos){
                flag=false;
                break;
            }
        }
        if(!flag){
            continue;
        }

        if(diff>=abs(n-i)){
            diff = abs(n-i); 
            break;
        }
        if(i=999999){
            break;
        }
    }
    string str = to_string(i);
    int cnt = str.size();
    return cnt+diff;
}

int main(){
    vector<string> exclude;
    int n, m, res, res1, res2;
    cin>>n>>m;

    exclude.assign(m,"");
    
    for(int i=0; i<m; i++){
        cin>>exclude[i];
    }

    if(n==100){
        cout<<"0";
        return 0;
    }

    if(m==0){
        string str = to_string(n);
        int cnt = str.size();
        if(abs(n-100)<cnt){
            cnt=abs(n-100);
        }
        cout<<cnt;
        return 0;
    }

    res1 = bigger(exclude, n, m);
    res2 = smaller(exclude, n, m);
    res = min(res1, res2);
    if(abs(n-100)<res){
        res = abs(n-100);
    }
    cout<<res;
}

//고려해야할 사항이 정말 많은 문제였다..
//브루트포스 문제였는데 배열에 숫자를 담고 인덱스를 활용할까 싶었지만 너무 비효율적인 것 같아 그냥 0부터 500000까지의 수가 있다고 가정하고 풀었다.
//풀이 방법
//고장나지 않은 버튼으로 만들 수 있는 숫자 중에 n에 가까운 숫자를 찾고 해당 숫자와 n의 값의 차이를 구한다.
//답: n에 가까운 숫자로 이동할 때 버튼 누르는 횟수 + (+,-)버튼 누르는 횟수
//n의 범위는 0부터 500000까지이지만 리모컨으로 누를 수 있는 숫자는 500000보다 클 수 있다.
//n에 가장 가까운 수가 n보다 클 수도 있고 n보다 작을 수도 있다. 찾은 숫자가 n보다 클 때는 bigger 메소드를 이용하고 n보다 작을 때는 smaller 메소드를 이용한다.
//따로 코드를 작성해야할 부분은 m이 0인 경우 - 그냥 숫자 길이만큼 버튼 누르면 됨. n이 100인 경우 - 이동하지 않아도 됨.
//특히, 100에서 시작하므로 n과 100의 값의 차이가 가장 가까운 수와 n의 값의 차이보다 작은 경우 n과 100의 값의 차이가 답이 된다.
#include <iostream>
#include <vector>

using namespace std;

int baseballGame(vector<string>v, int n){
    char num[3];
    int strike;
    int ball;
    for(int i=0; i<n; i++){
        cin>>num>>strike>>ball;

        int sbSum = strike + ball; //스트라이크와 볼의 총 개수
        //3개의 수 중에 몇 개의 경우의 수 계산할지

        if(sbSum==0){ //스트라이크 0개 & 볼 0개
        }
        else if(sbSum==1){ //스트라이크 1개 || 볼 1개
            if(strike==1){
                vector<char> result;
                for(int i=0; i<3; i++){
                    result.push_back(num[i]);
                    for(int j=0; j<10; j++){
                        result.push_back(j-'0');
                        for(int k=0; k<10; k++){
                            result.push_back(k-'0');
                            string str;
                            for(int q=0; q<3; q++){
                                str += result[q];
                            }
                            v.push_back(str);
                            result.erase(result.begin()+2);
                        }
                        result.erase(result.begin()+1);
                    }
                    result.erase(result.begin());
                }
            }
            else{ //볼 1개

            }
        }

        else if(sbSum==2){ //스트라이크 2개 || 스트라이크 1개&볼1개 || 볼 2개

        }

        else{ //sbSum==3 //스트라이크 3개 || 볼 3개

        }



    }
}

int main(){
    vector<string> v;


    int n;
    cin>>n;


}
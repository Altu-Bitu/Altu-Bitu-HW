#include <iostream>
#include <vector>

using namespace std;

int baseballGame(vector<string>v, int n){
    char num[3];
    int strike;
    int ball;
    for(int i=0; i<n; i++){
        cin>>num>>strike>>ball;

        int sbSum = strike + ball; //��Ʈ����ũ�� ���� �� ����
        //3���� �� �߿� �� ���� ����� �� �������

        if(sbSum==0){ //��Ʈ����ũ 0�� & �� 0��
        }
        else if(sbSum==1){ //��Ʈ����ũ 1�� || �� 1��
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
            else{ //�� 1��

            }
        }

        else if(sbSum==2){ //��Ʈ����ũ 2�� || ��Ʈ����ũ 1��&��1�� || �� 2��

        }

        else{ //sbSum==3 //��Ʈ����ũ 3�� || �� 3��

        }



    }
}

int main(){
    vector<string> v;


    int n;
    cin>>n;


}
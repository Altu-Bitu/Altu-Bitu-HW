#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int idx=0;
int baseball(){
    vector<int> v; //�ش� �̴� ���� ����
    vector<bool> pos; //Ȩ, 1��, 2��, 3�翡 ������ �ִ��� ���� ����
    int score=0; //�̹� ���������� ����
    int outcnt=0; //�ƿ��Ǵ� ���� �� ������ - 3���̸� break
    v.assign(9,0);


    for(int i=0; i<9; i++){
        cin>>v[i];
    }
    sort(v.begin()+1, v.end()); //next_permutation�� ��� ����� ���� ������ �̸� �������� ������ ���־����.
    while (next_permutation(v.begin()+1, v.end())){ //v[1]~v[8]�� ���� ������ ��� ����� �� Ȯ��
        score=0; //�̹� ������ ����
        pos.assign(4, false); //Ȩ, 1��, 2��, 3�� false�� �ʱ�ȭ

        while(true){

            int i = idx%8+1; //v[1]~v[8]���� ���ư����ϹǷ� idx�� �̷��� ����
            pos[0]=true;
            if(v[i]==0) {
                outcnt++;
                pos[0]=false;
            }
            if(outcnt==3) {
                idx=i+1;
                break;
            }

            if(v[i]==1){ //1��Ÿ
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                        if(j==3){//3�翡 ���ڰ� �ִٸ�
                            pos[j]=false;
                            score++; //3�� ���� Ȩ�� -> ���� ����
                        }
                        else{
                            pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                            pos[j+1]=true; //�� ĭ ������ �پ�
                        }
                    }
                }
            }
            else if(v[i]==2){//2��Ÿ
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                        if(j==3 || j==2){
                            pos[j]=false;
                            score++; //3,2�� ���� Ȩ�� -> ���� ����
                        }
                        else{
                            pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                            pos[j+2]=true; //�� ĭ ������ �پ�
                        }
                    }
                }
            }
            else if(v[i]==3){//3��Ÿ
                for(int j=3; j>=0; j--){
                    if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                        if(j==3 || j==2 || j==1){
                            pos[j]=false;
                            score++; //3,2,1�� ���� Ȩ�� -> ���� ����
                        }
                        else{
                            pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                            pos[j+3]=true; //�� ĭ ������ �پ�
                        }
                    }
                }
            }
            else{ //Ȩ��
                for(int j=3; j>=0; j--){
                    if(pos[j]) {
                        pos[j] = false;
                        score++;
                    }
                }
            }
            if(i==3){ //3�� Ÿ�ڱ��� ���� �� 4�� Ÿ���� 1�� ���� ���
                if(v[0]==1){ //1��Ÿ
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                            if(j==3){//3�翡 ���ڰ� �ִٸ�
                                pos[j]=false;
                                score++; //3�� ���� Ȩ�� -> ���� ����
                            }
                            else{
                                pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                                pos[j+1]=true; //�� ĭ ������ �پ�
                            }
                        }
                    }
                }
                else if(v[0]==2){//2��Ÿ
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                            if(j==3 || j==2){
                                pos[j]=false;
                                score++; //3,2�� ���� Ȩ�� -> ���� ����
                            }
                            else{
                                pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                                pos[j+2]=true; //�� ĭ ������ �پ�
                            }
                        }
                    }
                }
                else if(v[0]==3){//3��Ÿ
                    for(int j=3; j>=0; j--){
                        if(pos[j]){ //�ش� ���̽��� ���ڰ� �ִٸ�
                            if(j==3 || j==2 || j==1){
                                pos[j]=false;
                                score++; //3,2,1�� ���� Ȩ�� -> ���� ����
                            }
                            else{
                                pos[j]=false; //���� �ڸ� �� �ڸ��� �����
                                pos[j+3]=true; //�� ĭ ������ �پ�
                            }
                        }
                    }
                }
                else{ //Ȩ��
                    for(int j=3; j>=0; j--){
                        if(pos[j]) {
                            pos[j] = false;
                            score++;
                        }
                    }
                }
            }
            idx++;
        }
    };

    return score;
}

int main(){
    int maxScore=0;
    int n;
    cin>>n;

    for(int i=0; i<n; i++) {
        maxScore= max(maxScore, baseball());
    }

    cout<<maxScore;
}
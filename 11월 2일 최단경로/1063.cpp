#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> board;
string kingpos;
string stonepos;
vector<string>command;
int n;

//범위 판단
//이동
//가로축 위치 파악 필요, 세로축 위치 파악 필요
//코드가 길어서 실수하지 않도록 주의!

bool valid(int x, int y){ //범위 판단
    if(x>8 || x<1 || y>8 || y<1){
        //cout<<"!";
        return false;
    }
    return true;
}

void move(){
    for(int i=0; i<n; i++){
        int kfirst = kingpos[0]-'A'+1; //킹 자리-알파벳 (char->int)
        int ksecond = kingpos[1]-'0'; //킹 자리-숫자 (char->int)
        string nkingpos=kingpos; //다음 킹 자리
        int sfirst = stonepos[0]-'A'+1; //돌 자리-알파벳 (char->int)
        int ssecond = stonepos[1]-'0'; //돌 자리-숫자 (char->int)
        string nstonepos=stonepos; //다음 킹 자리
        
        //cout<<"킹: "<<kfirst<<'\n';
        //cout<<"돌: "<<sfirst<<'\n';

        if(command[i]=="R"){ //R 이동
            
            kfirst=kfirst+1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){ //이동한 킹 자리가 돌 자리와 같다면
                sfirst=sfirst+1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){ //이동한 킹 자리와 이동한 돌 자리가 범위 내에 들어온다면
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }

        else if(command[i]=="L"){ //L이동
            
            kfirst=kfirst-1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }
            
            if(nkingpos==stonepos){
                sfirst=sfirst-1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
                //cout<<"second: "<<sfirst<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }

        else if(command[i]=="B"){ //B이동
            
            //kfirst=kfirst+1;
            ksecond=ksecond-1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){
                //sfirst=sfirst+1;
                ssecond=ssecond-1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }

        else if(command[i]=="T"){ //T이동
            
            //kfirst=kfirst+1;
            ksecond=ksecond+1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){ 
                continue;
            }

            if(nkingpos==stonepos){
                //sfirst=sfirst+1;
                ssecond=ssecond+1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }
        else if(command[i]=="RT"){ //RT 이동
            
            kfirst=kfirst+1;
            ksecond=ksecond+1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){ 
                sfirst=sfirst+1;
                ssecond=ssecond+1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }

        else if(command[i]=="LT"){ //LT 이동
            
            kfirst=kfirst-1;
            ksecond=ksecond+1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){
                sfirst=sfirst-1;
                ssecond=ssecond+1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }
        else if(command[i]=="RB"){ //RB이동
            
            kfirst=kfirst+1;
            ksecond=ksecond-1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){
                sfirst=sfirst+1;
                ssecond=ssecond-1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }
        else if(command[i]=="LB"){ //LB이동
            
            kfirst=kfirst-1;
            ksecond=ksecond-1;
            nkingpos[0]=kfirst+'A'-1;
            nkingpos[1]=ksecond+'0';

            //cout<<"다음: " << nkingpos<<'\n';
            //cout<<"f: "<<kfirst<<"s: "<<ksecond<<'\n';

            if(!valid(kfirst, ksecond)){
                continue;
            }

            if(nkingpos==stonepos){
                sfirst=sfirst-1;
                ssecond=ssecond-1;
                nstonepos[0]=sfirst+'A'-1;
                nstonepos[1]=ssecond+'0';
                //cout<<"다음: "<<nstonepos<<'\n';
            }
            if(valid(sfirst, ssecond)){
                stonepos = nstonepos;
                kingpos = nkingpos;
            }
        }
    }
}

int main(){
    cin>>kingpos>>stonepos>>n;

    command.assign(n,"");
    for(int i=0; i<n; i++){
        cin>>command[i];
    }

    move();

    cout<<kingpos<<'\n'<<stonepos;

}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//ó���� �׳� �� ���� ���ϸ� �ȴٰ� ���������� long long �̾ ������ �ξ� �ʰ��Ǿ� �׳� string �迭�� �ޱ�� �Ѵ�.
//�迭�� �� �ε������� ���� ����
//���� ��� 10�̻��̸� ���� �ڸ����� +1
//�� ���߱� ���� ���� ���� �ʿ�


string func(string a, string b){
    int anum[10002]={0};
    int bnum[10002]={0};
    vector<int> cnum;
    string result;


    for(int i=0; i<a.length()/2; i++){
       swap(a[i], a[a.length()-1-i]);
    }

    for(int i=0; i<b.length()/2; i++){
        swap(b[i], b[b.length()-1-i]);
    }

    for(int i=0; i<a.length(); i++){
        anum[i] = a[i]-'0';
    }
    for(int i=0; i<b.length(); i++){
        bnum[i] = b[i]-'0';
    }

    for(int i=0; i<a.length(); i++){
        int isum=0;
        isum = anum[i]+bnum[i];

        if(isum>9){

            anum[i+1] += 1;
            isum=isum%10;
        }
        cnum.push_back(isum);

        //cout<<"a: "<<anum[i]<<" b: "<<bnum[i]<<" c: "<<cnum[i]<<'\n';
    }

    if(anum[a.length()]==1)
        cnum.push_back(1);


    for (int i = cnum.size()-1; i >= 0; i--) {
            result += to_string(cnum[i]);
    }
    return result;

}

int main(){
   string A, B;
   string answer;

   cin>>A>>B;
   if(A.length()<B.length()){
        swap(A,B);
   }
   answer = func(A,B);

   cout<<answer;

}
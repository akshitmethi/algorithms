#include<bits/stdc++.h>
using namespace std;



int bitwiseComplement(int N) {
        if(N==0)
            return 1;
        else if(N==1)
            return 0;
        else if(N&1 ==0){
            int a= (bitwiseComplement(N>>1)<<1)|1;
            cout<<a<<endl;
            return a;
        }
        else if(N&1 == 1){
            int a =  bitwiseComplement(N>>1)<<1;
            cout<<a<<endl;
            return a;
        }
        else
        {
            cout<<N;
            return N;
        }
    }


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<"Bitwise Complement is: "<<bitwiseComplement(n)<<endl;
    }
}
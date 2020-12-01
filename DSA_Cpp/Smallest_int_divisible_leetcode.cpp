#include<bits/stdc++.h>
#include<string>
using namespace std;


int smallestRepunitDivByK(int K) {
	vector<int> rem(K,0);
	int sol=1;
	int currem=0;
	while(rem[currem] < 1){
		rem[currem]++;
		currem = (currem*10+1)%K;
		if(currem==0)
			return sol;
		sol+=1;
	} 
	return -1;  
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		cout<<smallestRepunitDivByK(k)<<endl;
	}
}
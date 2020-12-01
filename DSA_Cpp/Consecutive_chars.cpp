#include<bits/stdc++.h>
using namespace std;
int max(int a,int b){
	return a>b?a:b;
}

int getPower(string s){
	int l=0,r=0,power=0;
	while(r<s.size()){
		r++;
		if(s[l]!= s[r]){
			power = max(power,r-l);
			l=r;
		}
	}
	return power;
}


int main(){
	string s;
	cin>>s;
	cin.clear();
	cout<<getPower(s);
}
#include<bits/stdc++.h>
using namespace std;

int replace5(int n){
	if(n==0){
		return 0;
	}
	if(n%10 == 0){
		return 5 + 10*replace5(n/10);
	}

	return n%10 + 10*replace5(n/10);
}

int main(){
	int num;
	cin>>num;
	cout<<replace5(num);
}
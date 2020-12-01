#include<bits/stdc++.h>
using namespace std;

int minCook(int *sec,int k,int l,int r){
	if(l>=r){
		return k;
	}
	int sum=0;
	for(int i=l;i<=r;i++){
		if(sec[i]>=k){
			sum += minCook(sec,k,l,i);
			sum += minCook(sec,k,i,r);
		}
	}
	int p=l;
	int leftarrer = 0;
	int rightarrer;
	for(int i=l+1;i<r;i++)
		rightarrer += (r-i)*sec[i];
	int currsum = rightarrer;
	for(int p=l+1;p<r;p++){
		leftarrer += (p-l)*sec[p];
		rightarrer -= (r-p)*sec[p];
		if(currsum > leftarrer + rightarrer)
			currsum = leftarrer + rightarrer;
	}
	return currsum+ sum+ k;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int sec[n];
		for(int i=0;i<n;i++)
			cin>>sec[i];
		cout<<minCook(sec,k,0,n-1)<<endl;
	}
}
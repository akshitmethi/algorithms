#include<bits/stdc++.h>
using namespace std;

string checkcoins(int *arr, int s){
	int dp[3];
	for(int i=0;i<3;i++)
		dp[i]=0;
	for(int i=0;i<s;i++){
		if(arr[i]==5){
			dp[0]++;
		}
		if(arr[i] == 10){
			if(dp[0]>0)
				dp[0]--;
			else return "NO";
			dp[1]++;
		}
		if(arr[i]==15){
			if(dp[1]>0)
				dp[1]--;
			else if(dp[0]>1)
				dp[0] -= 2;
			else
				return "NO";
			dp[2]++;
		}

	}
	return "YES";
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int s;
		cin>>s;
		int arr[s];
		for(int i=0;i<s;i++){
			cin>>arr[i];
		}
		cout<<checkcoins(arr,s);
	}
	return 0;
}
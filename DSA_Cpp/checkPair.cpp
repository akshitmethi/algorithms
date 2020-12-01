#include<bits/stdc++.h>
using namespace std;

void printPair(int * arr, int s, int sum){
	unordered_map<int,int> umap;
	for(int i=0;i<s;i++){
		if(umap.find(sum-arr[i]) != umap.end()){
			cout<<arr[i]<<","<<sum-arr[i]<<endl;
			return ;
		} else
			umap[arr[i]] = 1;
	}
	cout<<-1;
}

int main(){
	int s;
	cin>>s;
	int arr[s];
	for(int i=0;i<s;i++)
		cin>>arr[i];
	int sum;
	cin>>sum;
	printPair(arr,s,sum);
}

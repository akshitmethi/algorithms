#include<bits/stdc++.h>
using namespace std;

int get_cost(int *arr, int s){
	int i,j;
	unsigned long long int tc=0;
	priority_queue <int, vector<int>, greater<int>> pq;
	for(i=s-1; i>=0;i--){
		pq.push(arr[i]);
	}
	while(pq.size()>=2){
		i = pq.top();
		pq.pop();
		j=pq.top();
		pq.pop();
		pq.push(i+j);
		tc += i+j;
	}

	return tc;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int s;
		cin>>s;
		int arr[s];
		for(int i=0; i<s;i++)
			cin>>arr[i];
		cout<<get_cost(arr,s)<<endl;
	}
	return 0;
}
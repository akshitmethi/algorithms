#include<bits/stdc++.h>
using namespace std;

// int maxby(int i,int j, int k){
// 	if(i>j)
// 		if(i>k)
// 			return i;
// 		return k;
// 	else
// 		if(j>k)
// 			return j;
// 		return k;
// }

int path(int * arr[],int m,int n,int i,int j,int *sol[]){
	if(sol[i][j] != INT_MIN){
		return sol[i][j];
	}
	int max = INT_MIN;
	if(i+1<m){
		sol[i+1][j] = path(arr,m,n,i+1,j,sol);
		if(sol[i+1][j]>max)
			max = sol[i+1][j];
	}
	if(j+1<n){
		sol[i][j+1] = path(arr,m,n,i,j+1,sol);
		if(sol[i][j+1]>max)
			max = sol[i][j+1];
	}
	if(i+1<m && j+1<n){
		sol[i+1][j+1] = path(arr,m,n,i+1,j+1,sol);
		if(sol[i+1][j+1]>max){
			max = sol[i+1][j+1];
		}
	}

	return arr[i][j] + max;
}

int main(){
	int m,n;
	cin>>m>>n;
	int arr[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			cin>>arr[i][j];
	int sol[m][n];
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			sol[i][j] = INT_MIN;
	cout<<path(arr,m,n,0,0,sol);
}
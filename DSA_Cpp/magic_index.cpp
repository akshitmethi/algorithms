#include<bits/stdc++.h>
using namespace std;


bool magic_index_check(int * arr,int i,int target,int * visited,int size){
	cout<<i+1<<"-->";
	int next = (i+arr[i]+1)%size;
	if(visited[next]){
		if(next == target){
			cout<<next+1<<endl;
			return true;
		}
		cout<<next+1<<"..."<<endl;
		return false;
	}
	else{
		visited[next] = 1;
	if(magic_index_check(arr,next,target,visited,size)){
		return true;
	}
	else {
		return false;
	}
	}
}

int main(){
	int arr[] = {1,1,1,1};
	int size  = sizeof(arr)/sizeof(arr[0]);
	int count = 0;
	for(int i=0;i<size;i++){
		int visited[size] = {0}; 
		visited[i] = 1;
		cout<<i+1<<"-->";
		if(magic_index_check(arr,((i+arr[i]+1)%size),i,visited,size))
			count++;
		
	}
	cout<<count;
}
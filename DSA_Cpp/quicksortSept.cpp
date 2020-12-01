#include<bits/stdc++.h>
using namespace std;

void swap(int *a,int *b){
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}


void printarr(vector<int>& arr){
	for(auto i:arr){
		cout<<i<<" ";
	}
	cout<<endl;
} 

int getPivot(vector<int>& arr, int s, int e){
	int piv = s;
	int i= s+1;
	for(int j=i;j<e;j++){
		if(arr[j]<arr[piv]){
			swap(&arr[j],&arr[i]);
			i++;
		}
	}
	swap(&arr[piv],&arr[i-1]);
	return i-1; 
}

void quicksort(vector<int>& arr,int s, int e){
	if(s<e){
		int piv = getPivot(arr, s,e);
		//cout<<piv<<endl;
		quicksort(arr,s,piv-1);
		quicksort(arr,piv+1,e);
	}
}


int main(){
	vector<int> arr {9,2,3,1,4,7,6,5};
	cout<<"before sort\n";
	printarr(arr);
	cout<<"after sort";
	quicksort(arr,0,8);
	printarr(arr);
}
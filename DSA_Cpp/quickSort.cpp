 #include<bits/stdc++.h>
using namespace std;


int partition(int *arr,int low,int high){
	int i = low-1;
	int j = low;
	int pivot = high;
	while(j<pivot){
		if(arr[j]<arr[pivot]){
			i++;
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
		}
		j++;
	}
	int tmp = arr[j];
	arr[j] = arr[i+1];
	arr[i+1] = tmp; 
	
	return i+1;
}

void quicksort(int *arr,int low, int high){

	int pi = partition(arr,low,high);

	quicksort(arr,low,pi-1);
	quicksort(arr,pi+1,high);
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];
		quicksort(arr,0,n-1);
		for(int i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
	}
	return 0;
}
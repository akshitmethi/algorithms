#include<bits/stdc++.h>
using namespace std;

void print_pair(int *arr1,int *arr2,int s1,int i, int j){
	for(int k=s1-1;k>=i;k--)
		cout<<"("<<arr2[j]<<","<<arr1[k]<<")  ";
	cout<<endl;
}

void print_arrs(int *arr,int *arr1, int *arr2, int l, int r){
	int mid = (l+r)/2;
	int s1 = mid-l+1;
	int s2 = r-mid;
	cout<<"arr1->(";
	for(int i=0;i<s1;i++)
		cout<<arr1[i]<<",";
	cout<<")  arr2->(";
	for(int i=0;i<s2;i++)
		cout<<arr2[i]<<",";
	cout<<")  arr->(";
	for(int i=l; i<=r; i++)
		cout<<arr[i]<<",";
	cout<<")\n";

}

int merge(int *arr,int l,int mid,int r){
	int s1 = mid-l+1;
	int s2 = r-mid;
	int arr1[s1],arr2[s2];
	int i=0;
	while(i<s1){
		arr1[i] = arr[i+l];
		i++;
	}
	i=0;
	while(i<s2){
		arr2[i] = arr[s1+i+l];
		i++;
	}

	print_arrs(arr,arr1,arr2,l,r);
	i=0;
	int j=0,k=l,count=0;
	while(i<s1 && j<s2){
		if(arr1[i] > arr2[j]){
			arr[k] = arr2[j];
			count += s1-i;
			print_pair(arr1,arr2,s1,i,j);
			j++;
		} else {
			arr[k] = arr1[i];
			i++;
		}
		k++;
	}
	while(i<s1){
		arr[k] = arr1[i];
		i++; k++;
	}
	while(j<s2){
		arr[k] = arr2[j];
		j++; k++;
	}
	return count;
}

int find_inversion(int *arr, int l, int r){
	int count =0;
	if(l<r){
		int mid = (l+r)/2;
		count += find_inversion(arr,l,mid);
		count += find_inversion(arr,mid+1,r);
		count += merge(arr,l,mid,r);
	}
	return count;
}


int main(){
	int s;
	cin>>s;
	int arr[s];
	for(int i=0;i<s;i++)
		cin>>arr[i];
	cout<<find_inversion(arr,0,s-1);
}
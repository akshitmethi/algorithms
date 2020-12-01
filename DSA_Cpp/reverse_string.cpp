#include<bits/stdc++.h>
using namespace std;


class node {
public:
	int val;
	node * left;
	node * right;
	node(int value){
		this->val = value;
	}
};


void swap(int *a, int *b){
	*a = *a+*b;
	*b = *a-*b;
	*a = *a - *b;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9};
	int siz = 9;
	int k=6;
	int s=0,e=k-1;
	while(s<siz){
		int i=s,j=e;
		while(i<j){
			swap(&arr[i],&arr[j]);
			i++; j--;
		}
		s=e+1;
		if(s+k-1<siz)
			e = s+k-1;
		else e=siz-1;
	}
	for(int i=0;i<siz;i++)
		cout<<arr[i]<<" ";

	return 0;
}
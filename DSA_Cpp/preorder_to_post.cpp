#include<iostream>
using namespace std;

void printPost(int *pre,int n,int min,int max){
	for(int i=0;i<n;i++){
		if(pre[i]>=min && pre[i]<=max){
			temp = pre[i];
			printPost(pre,n,min,temp);

			printPost(pre,n,temp,max);
			temp
		}
	}
}

int main(){
	int pre[] = {10,5,1,7,40,50};
	int n = sizeof(pre)/sizeof(pre[0]);
	printPost(pre,n,INT_MIN,INT_MAX);
	return 0;
}
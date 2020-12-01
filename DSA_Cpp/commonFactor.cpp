#include<iostream>
#include<cmath>
using namespace std;

int commonFactor(int a,int b){
	int count=0;
	int temp =a;
	while(temp>b){
		temp=temp-b;
	}
	for(int i=1;i<=temp;i++){
		if(a%i==0 && b%i==0){
			count++;
		}
	}
	return count;
}

int main(){
	int num1=40000,num2=-518468;
	cout<<"enter both numbers"<<endl;
	//cin>>num1>>num2;
	if(num1>num2){
	cout<<endl<<commonFactor(abs(num1),abs(num2));
	}
	else{
		cout<<endl<<commonFactor(abs(num2),abs(num1));
	}
}
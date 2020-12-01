#include<iostream>
using namespace std;

char string_reversal(char * arr){
	if(arr[0]=='\0'){
		return '\0'; 
	}

	cout<<string_reversal(&arr[1]);
	return arr[0];
}

int main(){
	char * arr;
	cout<<"enter a string"<<endl;
	cin>>arr;
	cout<<endl<<"reversed string: ";
	cout<<string_reversal(arr);
}
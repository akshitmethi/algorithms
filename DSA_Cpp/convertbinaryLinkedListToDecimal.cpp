#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int val;
	node(int v){
		val = v;
	}
	node* next=NULL;
};

int convertDecimal(node* head){
	node* curr = head;
	int value=0;
	while(curr){
		value = (value|curr->val)<<1;
		curr = curr->next;
	}
	return value>>1;
}

int main(){
	int s;
	cin>>s;
	if(s<=0){
		cout<<"invalid input";
		return 0;
	}
	int v;
	cin>>v;
	node* head = new node(v);
	node* curr = head;
	for(int i=1;i<s;i++){
		cin>>v;
		curr->next = new node(v);
		curr = curr->next;
	}
	cout<<convertDecimal(head);
	return 0;
}
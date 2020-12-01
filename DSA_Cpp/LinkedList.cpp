//linked list implemetation
#include<iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
class node{
	public:
		int val;
		node* next=0;
		node(int value='\0'){
			val = value;
		}
} ;

class LinkedList{
	public:
		node * head = 0;
		void insertLast(int val){
			if(! this->head){
				this->head = new node(val);
			}
			else{
				node * curr = head;
				while(curr->next){
					curr = curr->next;
				}
				curr->next = new node(val);
			}
		}
		void insertFirst(int val){
			if(! head){
				head = new node(val);
			}
			else{
				node * new_node = new node(val);
				new_node->next=head;
				this->head=new_node;
			}
		}
		void printList(){
			node * curr = head;
			while(curr){
				cout<<"-->"<<curr->val;
				curr = curr->next;
			}
		}
		void reverse(){
			node * f,*c,*p;
			p= head;
			c = head->next;
			while(c){
				f = c->next;
				c->next = p;
				p=c;
				c= f;
			}
			head->next=NULL;
			head = p;


		}
		void swap_index(int i, int j){
			if(i==j){
				cout<<"no swap needed"<<endl;
			}
			if(i>j){
				i = i+j;
				j = i-j;
				i = i - j;
			}
			node *ii,*i1,*ji,*j1;
			int ci=0,cj=0;
			node *past=NULL,* curr = head;
			while(curr){
				if(ci == i){
					ii = past;
					i1= curr;
					//il = curr->next;
				}
				if(cj == j){
					ji = past;
					j1= curr;
					//jl = curr->next;
					break;
				}
				ci++; cj++;
				past = curr;
				curr = curr->next;
			}

			//cout<<"ii="<<endl<<"il="<<il->val<<endl<<"ji="<<ji->val<<endl<<"jl="<<jl->val<<endl;
			node *temp;
			if(!ii){
			temp = ii->next->next;
			ii->next = j1;
			j1->next = temp;
		} else{
			j1->next = this->head;
			this->head = j1;
		}
			temp = ji->next->next;
			ji->next = i1;
			i1->next = temp;
		}

};

int main(){
	
	node n;
	n.val= 5;
	cout<<"adress of n is "<<n.val<<endl;
	cout<<"getting new node ";
	node * n1 = new node(3);
	n.next = n1;
	cout<<endl<<"new next node val is "<<n.next->val<<endl<<endl;
	LinkedList l;
	l.insertLast(1);
	l.insertLast(2);
	l.insertLast(3);
	l.insertFirst(0);
	l.printList();
	
	l.reverse();
	cout<<endl<<"reversing the list"<<endl;
	l.printList();
	cout<<endl<<"---------------------swaping 0th index with 2nd--------------------"<<endl;
	l.swap_index(1,2);
	l.printList();
	return 0;
}
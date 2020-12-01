//tree concepts

#include<iostream>
#include<list>
using namespace std;

class node {
public:
	int val;
	node * left=NULL;
	node * right=NULL;
	node(int i){
		this->val = i;
	}
};

class tree{
	
	public:
		node * root=NULL;	
		tree(){
		cout<<endl<<"--------------"<<endl<<"tree created"<<endl<<"------------------"<<endl;
		}
	node * insert_util(int value,node * curr){
		if(curr == NULL){
			node * new_node = new node(value);
			return new_node;
		}
		if(value > curr->val){
			curr->right = insert_util(value,curr->right);
		}
		else {
			curr->left = insert_util(value,curr->left);
		}
	}

	void insert(int value){
		if(root == NULL){
			node * new_node = new node(value);
			root =  new_node;
		}
		if(value>root->val){
			root->right = insert_util(value,root->right);
		}
		if(value<root->val){
			root->left = insert_util(value,root->left);
		}
	}


	void print_order(node *curr){
		if(curr){
			print_order(curr->left);
			cout<<"->"<<curr->val;
			print_order(curr->right);
		}
	}
	

};

int main(){
	tree t;
	t.insert(4);
	t.insert(1);
	t.insert(3);
	t.insert(2);
	t.insert(5);
	t.insert(6);
	t.print_order(t.root);
	cout<<endl<<"printing Morris_Traversal\n";
	t.Morris_Traversal();
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int val;
	node *left;
	node *right;
	node(int val){
		this->val=val;
	}
};

void inTraversal(node * root){
	if(root){
		inTraversal(root->left);
		cout<<root->val<<" ";
		inTraversal(root->right);
	}
}

node * consTree(int* in,int* level,int siz,int s,int e,int* visited){
	  if(s==e){
	  	for(int i=0;i<siz;i++){
	  		if(!visited[i] && level[i] == in[s])
	  			visited[i]=1;
	  	}
	  	return new node(in[s]);
	  } else if(s>e) return NULL;
	  int i=s;
	  int f=0;
	  int pos=0;
	  while(pos<siz){
		  while(!visited[pos] && i<=e){
		  	if(in[i] == level[pos] ){
		  		f=1;
		  		break;
		  	}
		  	i++;
	  		}
	  		if(f)
	  			break;
	  		pos++;
	  		i=s;
		}
		visited[pos] = 1;
		node * curr= new node(in[i]);
		curr->left = consTree(in,level,siz,s,i-1,visited);
		cout<<"l:"<<curr->left->val<<endl;
		curr->right = consTree(in,level,siz,i+1,e,visited);
		cout<<"R:"<<curr->right->val<<endl;
		return curr;

}

int main(){
	int in[] = {4, 8, 10, 12, 14, 20, 22};
	int level[] = {20, 8, 22, 4, 12, 10, 14};
	int siz = 7;
	int visited[siz];
	for(int i=0;i<siz;i++)
		visited[i]=0;

	node * root =  consTree(in,level,siz,0,siz-1,visited);
	cout<<root->val<<endl;
	cout<<"completed"<<endl;
	inTraversal(root);
	cout<<"printed"<<endl;
	return 0;
}
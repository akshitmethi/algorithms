#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode * left=NULL;
	TreeNode* right=NULL;
	TreeNode(int value){
		this->val = value;
	}
};


void LOTraversal(TreeNode* root){
	queue<TreeNode*> q;
	q.push(root);
	TreeNode* curr;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		cout<<curr->val<<" -> ";
		if(curr->left)
			q.push(curr->left);
		if(curr->right)
			q.push(curr->right);
	}
	cout<<endl;
}

void inorderTraversal(TreeNode* root){
	if(root){
		inorderTraversal(root->left);
		cout<<root->val<<"->";
		inorderTraversal(root->right);
	}
}

void LOinsert(TreeNode* root, int value){
	queue<TreeNode*> q;
	q.push(root);
	TreeNode * curr;
	while(!q.empty()){
		curr = q.front();
		q.pop();
		if(curr->left)
			q.push(curr->left);
		else {
			curr->left = new TreeNode(value);
			break;
		}
		if(curr->right)
			q.push(curr->right);
		else{
			curr->right = new TreeNode(value);
			break;
		}
	}
}

// pair<int,int> longestPath(TreeNode* root){
// 	if(root){
// 		if(!(root->right || root->left))
// 			return make_pair(1,1);
// 		int longLeft = longestPath(root->left);
// 		int longRight = longestPath(root->right);
// 		max(longLeft.)

// 	}

// }

int main(){
	TreeNode* root = new TreeNode(5);
	root->left = new TreeNode(1);
	root->right = new TreeNode(1);
	root->right->right = new TreeNode(2);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(10);
	LOTraversal(root);
	LOinsert(root,15);
	LOTraversal(root);
	inorderTraversal(root);
	cout<<endl;
	return 0;
}
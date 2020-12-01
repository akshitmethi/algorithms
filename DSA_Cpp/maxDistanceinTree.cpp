#include<bits/stdc++.h>
using namespace std;

class TreeNode {
public:
	int val;
	TreeNode(int value){
		this->val = value;
	}
	TreeNode* left=NULL;
	TreeNode* right=NULL;
};

int maxdist=0;

int getMax(int a,int b){
	return a>b?a:b;
}

int findMaxDistance(TreeNode* root){
	if(!root)
		return 0;
	int left = findMaxDistance(root->left);
	int right = findMaxDistance(root->right);
	maxdist = getMax(maxdist,left+right+1);
	return getMax(left+1,right+1);
}

int main(){
	TreeNode* root= new TreeNode(0);
	root->left = new TreeNode(1);
	root->left->left = new TreeNode(2);
	root->left->left->right = new TreeNode(3);
	root->left->left->left = new TreeNode(4);
	root->left->left->left->right = new TreeNode(5);
	root->left->right = new TreeNode(6);
	root->left->right->right = new TreeNode(8);
	root->left->right->left = new TreeNode(7);
	root->left->right->left->right = new TreeNode(9);
	cout<<findMaxDistance(root)<<endl;
	cout<<"max distance:"<<maxdist-1;
	return 0;
}
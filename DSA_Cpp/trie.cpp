#include<bits/stdc++.h>
using namespace std;

class tnode{
public:
	char val;
	tnode * childs[26];
	bool isEnd=true;
	tnode(char v){
		val = v;
	}
};

tnode * create_node_utils(tnode *root,string s, int i){
	if(s[i] == '\0'){
		tnode * newNode = new tnode(s[i]);
		return newNode;
	}
	if()
	tnode * new_node = new tnode(s[i]);
	new_node->isEnd = false;
	new_node->childs[get_int(s[i])] = create_node_utils(s,i+1)
}

int get_int(char c){
	return c-'a';
}

tnode * create_node(root,string s,int i){
	tnode *root = new tnode(NULL);
	root->childs[get_int(s[i])] = create_node_utils(s,1);
}

int main(){
	string s;
	cin>>s;
	tnode * root = create_node(s,0);
}

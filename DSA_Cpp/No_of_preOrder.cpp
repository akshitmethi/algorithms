//Preorder to a tree

#include<iostream>
#include<climits>
using namespace std;


class Node{
	int val;
	Node *left;
	Node *right;
	Node(int value){
		this->val=value;
	}
};

void Preorder_val(int * list,int size,int root,bool* visited,int min, int max){
	cout<<"->"<<list[root];
	for(int i=0;i<size;i++){
		if(!visited[i]){
			visited[i] = true;
			if(list[i]<list[root] && list[i]>min && list[i] < max){
				Preorder_val(list,size,i,visited,min,list[i]);
			}
			if(list[i]>list[root] && list[i]>min && list[i] < max)
				Preorder_val(list,size,i,visited,list[i],max);
			visited[i] = false;
			}
			
			
		}
	}


int main(){
	int min = INT_MIN;
	int max = INT_MAX;
	int list[] = {4,5,3,7};
	int size = 4;
	bool visited[size] = {false};
	for(int i=0;i<size;i++){
		visited[i] = true;
		Preorder_val(list,size,i,visited,min,max);
		visited[i] = false;
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;

void printNodes(vector<vector<int>> adj, int curr ,int h, int ch){
	if(ch == h){
		cout<<curr<<" ";
		return ;
	}
	for(int node:adj[curr]){
		printNodes(adj,node,h,ch+1);
	}
}

void add_edge(vector<vector<int>>& adj,int x,int y){
	adj[x].push_back(y);
}

int main(){
	int s;
	cin>>s;
	vector<vector<int>> adj;
	adj.resize(s+1);
	adj[0].resize(s+1);
	add_edge(adj,1,2);
	add_edge(adj,1,3);
	add_edge(adj,2,4);
	add_edge(adj,2,5);
	add_edge(adj,3,8);
	int h;
	cin>>h;
	printNodes(adj,1,h,0);
}
#include<bits/stdc++.h>
using namespace std;

void showstack(stack <tuple<int,int>> s) 
{ 
	stack <tuple<int,int>> s_inv;
	while(!s.empty())
	{
		s_inv.push(s.top());
		s.pop();
	}
    while (!s_inv.empty()) 
    { 
    	int x = get<0>(s_inv.top());
    	int y = get<1>(s_inv.top());
        cout << "("<<x<<","<<y<<")"<<'\t'; 
        s_inv.pop(); 
    } 
    cout << '\n'; 
} 

int paths(vector<vector<int>> mat, int x, int y, stack<tuple<int,int>>& visited){
	int m = mat.size();
	int n = mat[0].size();
	visited.push(make_tuple(x,y));
	if(x == m-1 && y== n-1){
		showstack(visited);
		visited.pop();
		return 1;
	}
	int count = 0;
	if(x+1<m){
		count += paths(mat,x+1,y,visited);
	}
	if(y+1<n)
		count += paths(mat,x,y+1,visited);
	visited.pop();
	return count;
}

int main(){
	int n,m;
	cin>>n>>m;
	if(n<=0 || m<=0){
		cout<<0;
		return 0;
	}
	vector<vector<int>> mat(n,vector<int>(m,1));
	stack<tuple<int,int>> visited;
	cout<<paths(mat,0,0,visited);
	return 0;
}
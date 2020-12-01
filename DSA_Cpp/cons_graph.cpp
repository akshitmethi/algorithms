#include <bits/stdc++.h>
using namespace std;


int cons_graph_dp(vector<pair<int,int>> *adjlist,int *w_array){
	queue<int> s;
	s.push(0);
	w_array[0] = 0;
	while(!s.empty()){
		int i = s.front();
		s.pop();
		for(auto it = adjlist[i].begin(); it != adjlist[i].end(); it++){
			int next = get<0>(*it); //->first;
			int wt = get<1>(*it); //->second;

			if(w_array[next] == INT_MIN){
				w_array[next] = wt+w_array[i];
				s.push(next);
			}

			if(wt + w_array[i] == w_array[next]){
				continue;
			}
			else {
				return -1;
			}
		}
		
	}
	return 1;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<pair<int,int>> adjlist[n];
		int l,j,k;
		for(int i=0;i<m;i++){
			cin>>l>>j>>k;
			adjlist[l-1].push_back(make_pair(j-1,k));
			adjlist[j-1].push_back(make_pair(l-1,-k));
			//push_node(adjlist,i,j,k);
		}
		int weight[n];
		for(int i=0;i<n;i++)
			weight[i] = INT_MIN;
		if(cons_graph_dp(adjlist,weight)==1){
			cout<<"conservative"<<endl;
		} else
		cout<<"not conservative"<<endl;
	}
}
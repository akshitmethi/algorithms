#include<bits/stdc++.h>
using namespace std;


class ud_graph {
public:
	int N;
	list<int> * edg;
	ud_graph(int vert){
		this->N= vert;
		edg= new list<int>[N]; 
	}

	void add_edge(int a, int b){
		edg[a].push_front(b);
		//edg[b].push_front(a);
	}

	void print_graph(){
		for (int i = 0; i < N; ++i)
		{
			cout<<"head-> "<<i<<"-> ";
			for(auto j=edg[i].begin();j!=edg[i].end();j++)
				cout<<*j<<"-> ";
			cout<<endl;
		}
	}


	void bfs(int root){
		queue<int> q;
		q.push(root);
		int curr;
		vector<int> visit(N,0);
		while(!q.empty()){
			curr = q.front();
			q.pop();
			cout<<"-> "<<curr;
			visit[curr]=1;
			for(auto node = edg[curr].begin(); node != edg[curr].end();node++){
				if(!visit[*node])
					q.push(*node);
			}
		}
		cout<<endl;
	}
	int check_all_visit(vector<int>& visit, int root){
		int r=1;
		int tmp = visit[root];
		visit[root] = 1;
		for(int i:visit){
			r = r&i;
		}
		visit[root] = tmp;
		return r;
	}

	void mother_vertex_util(int root, vector<int>& visit){
		visit[root] =1;
		for(auto j=edg[root].begin(); j!= edg[root].end();j++){
					if(!visit[*j])
						mother_vertex_util(*j, visit);	
				}
	}

	int mother_vertex(){
		vector<int> visit(N,0);
		for(int i=0;i<N;i++){
			if(!visit[i]){
				for(auto j=edg[i].begin(); j!= edg[i].end();j++){
					if(!visit[*j])
						mother_vertex_util(*j, visit);	
				}

			}
			if(check_all_visit(visit,i)){
					return i;
			}
		}
		return -1;
		
	}

	void dfs_util(int root, vector<int>& visit){
		cout<<"->"<<root;
		visit[root] = 1;
		for(auto i=edg[root].begin();i!= edg[root].end(); i++){
			if(!visit[*i])
				dfs_util(*i,visit);
		}
	}

	void dfs(int root){
		vector<int> visit(N,0);
		dfs_util(root,visit);
	}

	int numPaths_util(int curr, vector<int>& visit, int target){
		visit[curr] =1;
		if(curr==target){
			return 1;
		}
		int res=0;
		for(auto i=edg[curr].begin();i!= edg[curr].end();i++){
			if(!visit[*i]){
				res += numPaths_util(*i,visit, target);
				visit[*i]= 0;
			}
		}
		return res;
	}

	int numPaths(int a, int b){
		int res = 0;
		vector<int> visit(N,0);
		for(auto i=edg[a].begin();i!= edg[a].end();i++){
			res += numPaths_util(*i,visit, b);
			visit[*i] = 0;
		}
		return res;
	}


};

int main(){
	ud_graph * g = new ud_graph(5);
	cout<<"Graph created\n";
	g->add_edge(1,0);
	g->add_edge(1,2);
	g->add_edge(2,4);
	g->add_edge(0,2);
	g->add_edge(2,3);
	g->add_edge(3,4);
	g->print_graph();
	g->bfs(0);
	g->dfs(0);
	cout<<endl;
	cout<<g->mother_vertex()<<endl;
	cout<<g->numPaths(1,4);
	return 0;
}
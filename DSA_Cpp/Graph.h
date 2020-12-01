#include<iostream>
#include<list>
using namespace std;

class Graph{
	int Vertex;
	public: 
		list <int> *edge;
		Graph(int V){
		this->Vertex = V;
		edge = new list <int> [V];
		}
		void add_edge(int src, int dest){
			edge[src].push_front(dest);
		}
		void BFS(int src){
			list <int> stack;
			int visited[Vertex] = {0};
			stack.push_front(src);
			while(!stack.empty()){
				int curr = stack.front();
				stack.pop_front();
				cout<<"->"<<curr;
				for (auto it = edge[curr].begin();it!=edge[curr].end();++it){
					if(visited[*it] == 0){
						stack.push_back(*it);
						visited[*it] = 1;
					}
				}
			}
		}
		void DFS_utils(int src, bool *visited){
			for(auto it=edge[src].begin();it != edge[src].end();++it){
			 	if(!visited[*it]){
			 		cout<<"->"<<*it;
			 		visited[*it] = true;
			 		this->DFS_utils(*it,visited);
			 }
			}
		}
		void DFS(int src){
			 bool visited[Vertex] = {false};
			 cout<<"->"<<src;
			 for(auto it=edge[src].begin();it != edge[src].end();++it){
			 	if(!visited[*it]){
			 	cout<<"->"<<*it;
			 	visited[*it] = true;
			 	this->DFS_utils(*it,visited);
			 }
			 }
		}
};

int main(){
	Graph *g;
	g = new Graph(5);
	g->add_edge(0,1);
	g->add_edge(0,2);
	g->add_edge(2,3);
	g->add_edge(3,4);
	cout<<"BFS here-----------"<<endl;
	g->BFS(0);
	cout<<endl<<"DFS here---------"<<endl;
	g->DFS(0);
	cout<<endl<<"code without errors";
	return 0;
}
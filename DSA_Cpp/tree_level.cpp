#include<iostream>
#include<list>
using namespace std;


class Graph{
	int v;
	list <int> *adj;
public:
	Graph(int vertex){
		this->v = vertex;
		 adj = new list <int>[vertex];
	}
	void add(int src, int dest){
		adj[src].push_back(dest);
		//adj[dest].push_back(src);
	}
	void DFS_utils(int src, bool *visited){
			for(auto it=adj[src].begin();it != adj[src].end();++it){
			 	if(!visited[*it]){
			 		cout<<"->"<<*it;
			 		visited[*it] = true;
			 		this->DFS_utils(*it,visited);
			 }
			}
		}
		void DFS(int src){
			 bool visited[v] = {false};
			 visited[src] = true;
			 cout<<"->"<<src;
			 for(auto it=adj[src].begin();it != adj[src].end();++it){
			 	if(!visited[*it]){
			 	cout<<"->"<<*it;
			 	visited[*it] = true;
			 	this->DFS_utils(*it,visited);
			 }
			 }
		}


	void BFS(int src){
		list <int> stack;
		list <int> level;
		stack.push_back(src);
		int lvl=0;
		level.push_back(0);
		list <int> L_queue;
		L_queue.push_back(0);
		bool visited[v] = {false};
		cout<<endl<<"-->"<<src;
		while(!stack.empty()){
			src = stack.front();
			stack.pop_front();
			lvl = level.front();
			level.pop_front();
			visited[src] = true;
			for(auto it = adj[src].begin(); it != adj[src].end() ; it++ ){
				//cout<<endl<<*it<<"check if visited : "<<!visited[*it];
				if(!visited[*it]){
					cout<<"-->"<<*it;
					visited[*it] = true;
					stack.push_back(*it);
					level.push_back(lvl+1);
					L_queue.push_back(lvl+1);
				}
			}



		}
		cout<<endl<<"level:"<<endl;
		for(auto it = L_queue.begin();it != L_queue.end(); it++){
			cout<<"-->"<<*it;
		}
	}



	bool check_if_cycle(){
		int curr = 0;
		return false; 
	}
};

int main(){
	Graph * G = new Graph(6);
	G->add(0,1);
	G->add(0,2);
	G->add(1,3);
	G->add(3,4);
	G->add(4,2);
	G->add(2,5);
	G->add(1,5);
	G->BFS(0);
	cout<<endl<<"DFS: "<<endl;
	G->DFS(0);
	return 0;
}
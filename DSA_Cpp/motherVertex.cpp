#include<iostream>
#include<list>
using namespace std;
class Graph_extend{
public:
	int v;
	list <int> *edge;
	Graph_extend(int vertex){
		this->v = vertex;
		edge= new list<int> [vertex];
	}
	void add_edge(int src, int dest){
			edge[src].push_front(dest);
		}


	void DFS_utils(int src, bool *visited){
			visited[src]  = true;
			for(auto it=edge[src].begin();it != edge[src].end();++it){
			 	if(!visited[*it]){
			 		cout<<"->"<<*it;
			 		this->DFS_utils(*it,visited);
			 }
			}
		}

	int motherVertex(){
		bool visited[] = {false};
		int mv;
		for (int i = 0; i < v; i++){ 
        	if (visited[i] == false) 
        	{ 
            	DFS_utils(i, visited); 
            	cout<<endl;
           		mv = i; 
        	} 
    }
    	cout<<"might be "<<mv<<endl;
		for(int i=0;i<v;i++){
			visited[i] = false;
		}
		DFS_utils(mv,visited);
		cout<<"visited: ";
		for(int i=0;i<v;i++){
			cout<<"->>"<<visited[i];
			if(visited[i] == false){
				return -1;
			}
		}
		return mv;
	}
};

int main(){
	Graph_extend * G = new Graph_extend(4);
	G->add_edge(0,2);
	G->add_edge(1,0);
	G->add_edge(0,3);
	int mv = G->motherVertex();
	cout<<endl<<"Mother vertex : "<<mv<<endl;

	return 0;
}
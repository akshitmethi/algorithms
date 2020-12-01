#include<bits/stdc++.h>
using namespace std;

//[2,1,1]
//[0,1,1]
//[1,0,1]
void printgrid(vector<vector<int>>& grid){
	for(int i=0; i<grid.size();i++){
		for(int j=0;j<grid[0].size();j++)
			cout<<grid[i][j]<<" ";
		cout<<endl;
	}
}

int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> que;
        int i=0,j=0;
        int im = grid.size(); int jm=grid[0].size();
        //finding first rotten orange
        while(i<grid.size()){
            while(j<grid[0].size()){
                if(grid[i][j]== 2)
                    que.push(make_pair(make_pair(i,j),0));            
                i++; j++;
            }
        }
        int time=0;
        //bfs using queue
        while(!que.empty()){
            int level = get<1>(que.front());
            time = max(level,time);
            i = get<0>(get<0>(que.front()));
            j = get<1>(get<0>(que.front()));
            que.pop();
            cout<<"("<<i<<","<<j<<")"<<"L-"<<level<<endl;
            //down
            if(i+1<im && grid[i+1][j] == 1){
                grid[i+1][j] =2;
                que.push(make_pair(make_pair(i+1,j),level+1));
            }
            //up
            if(i-1>=0 && grid[i-1][j]==1){
                grid[i-1][j] = 2;
                que.push(make_pair(make_pair(i-1,j),level+1));
            }
            //right
            if(j+1<jm && grid[i][j+1]==1){
                grid[i][j+1] = 2;
                que.push(make_pair(make_pair(i,j+1),level+1));
            }
            //left
            if(j-1>=0 && grid[i][j-1]==1){
                grid[i][j-1]=2;
                que.push(make_pair(make_pair(i,j-1),level +1));
            }
        }
        //checking if any fresh oranges left
        for(i=0; i<grid.size();i++){
			for(j=0;j<grid[0].size();j++){
				if(grid[i][j]==1)
					return -1;
			}
			cout<<endl;
		}
        return time;
    }

int main(){
	vector<vector<int>> grid {{2,1,1},{0,0,1},{1,0,1}};
	cout<<orangesRotting(grid);
}
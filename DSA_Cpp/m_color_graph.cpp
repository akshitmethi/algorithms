#include<bits/stdc++.h>
using namespace std;
int v=4;
int g[4][4];

bool find_color(int i,int *color){
	
	color[i]=1;
	int c[v];

	for(int j=0;j<v;j++){
		cout<<"finding color mat";
		if(g[i][j]==1){
			c[color[j]] = 1;
		} else 
			c[color[j]] = 0;
	}
	for(int k=0; k<v;k++){
		cout<<"getting color";
		if(c[color[i]]){
			color[i]++;
		} else {
			break;
		}
	}
	cout<<"at index "<<i<<endl;
	if(i==v-1){
		if(color[i]<v) 
			return true;
		else 
			return false;
	}
	cout<<color[i]<<" at index "<<i<<endl;
	if(find_color(i+1,color)){
		
		return true;
	}
	return false;
}

int main(){
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			cin>>g[i][j];
	int color[v];
	for(int i=0;i<v;i++)
		color[v]=0;
	color[0] = 1;
	if(!find_color(1,color)){
		cout<<"no solution";
	}
}
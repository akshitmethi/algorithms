#include<bits/stdc++.h>
using namespace std;


vector<int> collider(vector<int>& asteroids){
	stack<int> st;
	if(asteroids.size()==0){
		vector<int> res;
		return res;
	}
	int i=0;
	while(i<asteroids.size()){
		if(asteroids[i]>0)
			st.push(asteroids[i]);
		else{
			while(!st.empty() && st.top()>0 && -asteroids[i]>st.top())
				st.pop();
			if(st.empty() || st.top()<0)
				st.push(asteroids[i]);
			if(!st.empty() && -asteroids[i]==st.top())
				st.pop();
		}
		i++;
	}
	vector<int> res(st.size());
	for(int i=res.size()-1;i>=0;i--){
		res[i] = st.top();
		st.pop();
	}
	return res;
}

void printvector(vector<int> asteroids){
	for(int a:asteroids){
		cout<<a<<",";
	}
	cout<<endl;
}

int main(){
	int n;
	cin>>n;
	vector<int> asteroids(n);
	for(int i=0;i<n;i++){
		cin>>asteroids[i];
	}
	printvector(collider(asteroids));
}
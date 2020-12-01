#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> umap;
        int posx=0,posy=10;
        vector<string> res;
        if(s.size()<10){
        	//res.push_back(s);
            return res;
        }
        while(posx+posy<=s.size()){
        	string tmp = s.substr(posx,posy);
        	
        	if(umap.find(tmp) != umap.end()){
        		if(umap[tmp]==1){
	        		res.push_back(tmp);
	                umap[tmp]++;
            	}
        	}
        	else
        		umap[tmp]=1;
        	posx++;
        }
        return res;
    }

    void printfindRepeatedDnaSequences(string s){
    	vector<string> res = findRepeatedDnaSequences(s);
    	for(string s1:res){
    		cout<<s1<<",";
    	}
    	cout<<endl;
    }
};

int main(){
	int t;
	cin>>t;
	Solution* sol = new Solution();
	while(t--){
		string s;
		cin>>s;
		cin.clear();
		sol->printfindRepeatedDnaSequences(s);
	}
	return 0;
}
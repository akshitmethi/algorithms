#include<bits/stdc++.h>
using namespace std;


bool wordBreak_util(string s, int i, unordered_map<string,int> um){
        if(s.size()<=i)
            return true;
        string tochk = "";
        for(int j=i;j<s.size();j++){
            tochk += s[j];
            
            if(um.find(tochk) != um.end()){
                //cout<<tochk<<endl;
                if(wordBreak_util(s,j+1,um))
                    return true;
            }
        }
        return false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> umap;
        for(string i:wordDict){
            umap[i] = 1;
        }
        return wordBreak_util(s,0,umap);
    }

int main(){
    vector<string> wordDict {"leet","code"};
    string s = "leetcod";
    cout<<wordBreak(s,wordDict);
    return 0;
}
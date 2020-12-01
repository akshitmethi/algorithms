#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool StringEqual(string A, string B){
        int i=0;
        while(i<A.size() && i<B.size())
        {
            if(A[i] != B[i])
                return false;
            i++;
        }
        if(i<A.size() || i<B.size())
            return false;
        else
            return true;
    }
    
    bool containDuplicate(string A){
        int charmap[27];
        for(int i=0;i<26;i++)
            charmap[i]=0;
        int i=0;
        while(i<A.size()){
            if(charmap[A[i]-'a']==0)
                charmap[A[i]-'a']++;
            else
                return true;
            i++;
        }
        return false;
    }
    
    bool buddyStrings(string A, string B) {
        if(A.size() != B.size())
            return false;
        if(A.size()<2)
            return false;
        int i=-1;
        int j=-1;
        int k=0;
        if(StringEqual(A,B))
            return containDuplicate(A);
        else
        while(k<A.size()){
            if(A[k]!=B[k]){
                if(i==-1)
                    i=k;
                else if(j==-1)
                    j=k;
            }
            if(i!= -1 && j!= -1)
            {
                char tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
                return StringEqual(A,B);
            }
            k++;
        }
        return false;
    }
};



int main(){
	Solution* sol = new Solution();
	string A= "aa";
	string B= "aa";
	//cout<<sol->StringEqual(A,B)<<endl;
	//cout<<sol->containDuplicate(A)<<endl;
	cout<<sol->buddyStrings(A,B);
	return 0;
}
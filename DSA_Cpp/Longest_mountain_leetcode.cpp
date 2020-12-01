#include<bits/stdc++.h>
using namespace std;

    pair<int,int> isMountain(vector<int>& arr, int idx){
        int s=0;
        int i=idx;
        for(; i<arr.size()-1;i++){
            if(arr[i]>arr[i+1])
                s++;
            else
                break;
        }
        int j=idx;
        while(j>0){
            if(arr[j]>arr[j-1])
                s++;
            else
                break;
            j--;
        }
        return make_pair(s+1,i);
    }
    int takeMax(int a, int b){
        return a>b?a:b;
    }
    
    int longestMountain(vector<int>& arr) {
        int longest=0;
        for(int i=1;i<arr.size();i++){
            pair<int,int> resi = isMountain(arr,i);
            longest = takeMax(get<0>(resi),longest);
            i = get<1>(resi);
        }
        return longest;
    }

    int main(){
    	int s=0;
    	cin>>s;
    	vector<int>arr(s);
    	for(int i=0;i<s;i++)
    		cin>>arr[i];
    	cout<<"longestMountain: "<<longestMountain(arr)<<endl;
    	pair<int,int> res = isMountain(arr,3);
    	cout<<get<0>(res)<<endl;
    	cout<<get<1>(res);
    	return 0;
    }
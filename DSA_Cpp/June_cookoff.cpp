#include <bits/stdc++.h>
using namespace std;

void max_value(long long *arr, long long s){
    long long max_r,max_l,curr;
    long long index_l=0,index_r=s-1;
    //int st_idx = 0,end_idx=index_r,flg=1,flg_r=1;
    
    max_l=-1;
    max_r= -1;
    curr = 1;
    for(long long i=0;i<s;i++){
        curr *= arr[i];
        if(curr>max_l){
            index_l = i;
            max_l = curr;
        }
    }
    curr =1;
    for(long long i=s-1;i>=0;i--){
        curr *= arr[i];
        if(curr>max_r){
            index_r = i;
            max_r = curr;
        }
    }
    if(max_r == -1)
        max_r=0;
    if(max_r>=max_l){
        while(arr[s-1] == 1)
            s--;
        cout<<max_r<<" "<<index_r<<" "<<s-1;
    }
    else {
        s=0;
        while(arr[s]==1)
            s++;
        cout<<max_l<<" "<<s<<" "<<index_l;
    }
    
}


int main() {
	int t;
	cin>>t;
	while(t--){
	    long long s;
	    cin>>s;
	    long long arr[s];
	    for(long long i = 0; i<s; i++)
	        cin>>arr[i];
	    max_value(arr,s);
	}
	return 0;
}

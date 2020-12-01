#include<bits/stdc++.h>
using namespace std;

int check_long(string s){
	int i,j,max;
	int check[26];
	for(i=0;i<26;i++){
		check[i]=  0;
	}
	max=INT_MIN;
	i=j=0;
	while(s[j]!= '\0'){
		cout<<"i: "<<i<<" j: "<<j<<endl;
		if(check[s[j] - 'a'] == 0){
			check[s[j]-'a'] = 1;
			j++;
		}
		else {
			max = j-i;
			while(s[i] != s[j]){
				check[s[i] - 'a'] = 0;
				i++;
			}
			i++;
		}
	}
	return max;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		cout<<check_long(s);
	}
	return 0;
}

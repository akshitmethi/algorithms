#include<bits/stdc++.h>
#include<string>
using namespace std;

string replicate(string s,int times){
	string builder = "";
	while(times--)
		builder+= s;
	return builder;
}

string decodeString(string s){
	stack<char> st;
	string res= "";
	string num="";
	string sub="";
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num+= s[i];
		}
		if(s[i]>='a' && s[i]<='z'){
			res+= s[i];
		}
		if(s[i]=='['){
			st.push('[');
			while(!st.empty()){
				i++;
				if(i>=s.size())
					return "invalid string";
				if(s[i] == ']')
					st.pop();
				if(s[i]=='[')
					st.push('[');
				sub+= s[i];
			}
		}
		if(sub.size()>0){
			res += replicate(decodeString(sub),stoi(num));
			sub="";
			num="";
		}
	}
	return res;
}


int main(){
	string s;
	cin>>s;
	cin.clear();
	cout<<decodeString(s);
	return 0;
}
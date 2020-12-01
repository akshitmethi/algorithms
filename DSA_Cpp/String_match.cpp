#include <iostream>

using namespace std;

//search str 2 in str 1
bool Strmatch(char * str1,char * str2){
	int j=0;
	for(int i=0;str1[i]!= '\0';i++){
		if(str1[i] == str2[j])
			j++;
		else
			j=0;
		if(str2[j]=='\0'){
			return true;
		}
	}
	return false;
}


bool exactStrmatch(basic_string<char> str1,basic_string<char> str2){
    for(int i=0;str1[i]!= '\0';i++){
        
        if(str2[i]=='\0' && str1[i]=='\0'){
            return true;
        }
        else if(str1[i] == str2[i])
            continue;
        else
            return false;
    }
    return false;
}

// int main(){
// 	char str1[] = "akshitmethi";
// 	char str2[]  = "hi";
// 	if(Strmatch(str1,str2))
// 	cout<<"yes";
// 	else
// 		cout<<"no";
// 	return 0;
// }
int main(){
	int t;
	int n,k,pl;
	char pharase[5];
	cin>>t;
	int flg;
	while(t--){
		cin>>n>>k;
		int flags[n]= {0};
		
		char pastWord[n][5];
		for(int i=0;i<n;i++){
			cin >> pastWord[i];
		}
		//for sentences
		for(int i=0;i<k;i++){
			cin>>pl;
			int j=0;
			while(j<pl){
				cin>>pharase;
				for(int no=0;no<n;no++){
					if(flags[no]==1)
						continue;
					if(Strmatch(pharase,pastWord[no])){
						flags[no] = 1;
					}
				}
				j++;
			}
		}
		for(int i=0;i<n;i++){
			if(flags[i])
				cout<<"yes ";
			else
				cout<<"no ";
		}
		cout<<endl;

}
}
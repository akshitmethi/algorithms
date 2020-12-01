#include<bits/stdc++.h>
using namespace std;
int c[100][100];
int C(int n, int k)  
{  
    // Base Cases  
    if(c[n][k] != -1)
    	return c[n][k];
    if (k == 0 || k == n)  
        return 1;  
  
    // Recur  
    c[n][k] =  C(n - 1, k - 1) + C(n - 1, k); 
    return c[n][k]; 

}  


int cons(int s,int n1){
	if(n1 == 0){
		return 1;
	}
	int sum = C(s,n1);
	for(int i=n1-1;i>0;i--){
		sum -= C(s-n1+i,i);
	}
	return sum + cons(s,n1-1);
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<100;i++)
		for(int j=0;j<100;j++){
			c[i][j] = -1;
		}
	while(t--){
		int n;
		cin>>n;
		int n1 = (n+1)/2;
		cout<<cons(n,n1)<<endl;
	}
	return 0;
}
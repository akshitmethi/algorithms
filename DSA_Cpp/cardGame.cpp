#include <bits/stdc++.h>
using namespace std;

void create_seq(int s){
    queue<int> qu;
    int tracker=1,i=0,f=1;
    int arr[s];
    for(;i<s;i++){
        qu.push(i);
    }
    i=0;
    int front;
    while(tracker<=s){
        i=f;
        f++;
        //first operation completed
        while(i--){
            front = qu.front();
            qu.pop();
            qu.push(front);
        }
        front = qu.front();
        arr[front] = tracker;
        //cout<<"assign arr["<<front<<"] to "<<tracker<<endl;
        tracker++;
        qu.pop();
    }
    for(i=0;i<s;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int s;
	    cin>>s;
	    create_seq(s);
	}
	return 0;
}
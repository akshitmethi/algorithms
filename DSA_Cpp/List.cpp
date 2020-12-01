#include<iostream>
#include<list>
using namespace std;

void showList(list <int> g){
	for (auto it = g.begin(); it != g.end(); ++it){
		cout <<"->"<<*it;
	}
}

int main(){
	list <int> arg;
	arg.push_front(1);
	arg.push_back(2);
	auto it= arg.end();
	//cout<<*it;
	while(!arg.empty()){
		cout<<arg.front();
		arg.pop_front();
	}
	//showList(arg);
	return 0;
}
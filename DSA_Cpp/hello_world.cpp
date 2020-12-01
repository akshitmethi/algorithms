#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;
using std::setw;
int main(){
	srand(2);
	int a;
	cin >> a;
	while (a--){
		cout <<setw(10)<< rand()<<endl;
	}
	cout <<setw(5)<< "this is new program";
	return 0;
}
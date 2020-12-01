#include<iostream>
#include<list>
using namespace std;


bool check_in_board(int * corr,int size){
	if(corr[0]>=0 && corr[0]<size && corr[1]>=0 && corr[1]<size){
		return true;
	}
	else {
		return false;
	}
}

int ** get_moves(int * corr){
	
}

void knightMoves(int curr,bool ** visited){

}
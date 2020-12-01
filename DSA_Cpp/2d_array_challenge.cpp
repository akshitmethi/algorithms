#include <bits/stdc++.h>

using namespace std;

int sum(int ** arr,int i,int j){
    int sumval=0;
    for(int row=i;row<=i+2;row++){
        for(int col=j;col<=j+2;col++){
            if(row != i+1 || col != j || col != j+2)
                sumval += arr[row][col];
        }
    }
    return sumval;
}


void printglass(int ** arr, int i, int j){
    for(int row=i;row<=i+2;row++){
        for(int col=j;col<=j+2;col++){
            if(row != i+1 || col != j || col != j+2)
                cout<<arr[row][col];
            cout<<" ";
        }
        cout<<endl;
    }
}
// Complete the hourglassSum function below.
int hourglassSum(int ** arr,int size) {
    int rowsize = 6;
    int colsize = 6;
    int max_i =999, max_j=999;
    int max_sum=-1; 
    for(int i=0; i<rowsize-2;i++){
        for(int j=0;j<colsize-2;j++){
            int val = sum(arr,i,j);
            if(max_sum < val)
                max_sum=val;
                max_i=i;
                max_j=j;
        }
    }
    printglass(arr,max_i,max_j);
    return max_j;

}

int main()
{

    int * arr[6];
    cout<<"enter array"<<endl;
    for (int i = 0; i < 6; i++) {

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout<<"let's start\n";

    int result = hourglassSum(arr,6);

 	cout<<result;

    return 0;
}
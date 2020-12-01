#include<bits/stdc++.h>
using namespace std;


class NumArray {
	std::vector<int> v_sum;
	vector<int> v;
public:
    NumArray(vector<int>& nums) {
        v.resize(nums.size());
        v[0] = nums[0];
        v_sum[0] = v[0];
        for(int i=1;i<v.size();i++){
        	v_sum[i] = v_sum[i-1] + nums[i];
        	v[i] = nums[i];
        }
    		
    }
    
    void update(int i, int val) {
        int diff = val - v[i] ;
        v[i] = val;
        for(int j=i;j<v.size();j++){
        	v_sum[j] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        if(i=0)
        	return v_sum[j];
        return v_sum[j] - v_sum[i-1];
    }
};

int main(){
	std::vector<int> v = {1,2,3,4,5};
	NumArray * nm = new NumArray(v);
	cout<<nm->sumRange(1,3);
}

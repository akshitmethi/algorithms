/**
 * Hamming Distance is the distance between bits of two numbers
 * example: 
 *      4 -> 1 0 0
 *      1 -> 0 0 1
 *   diff -> ^   ^
 * 
 * So, there are two bits different.
 * Hamming distance between 4 and 1 is 2
 * */
class Solution {
    public int hammingDistance(int x, int y) {
        int diff = 0;
        while(x!=0 && y!= 0){
            diff += Math.abs(bitDistance(x) - bitDistance(y));
            x= x>>1;
            y=y>>1;
        }
        while(x!=0){
            diff += bitDistance(x);
            x= x>>1;
        }
        while(y!= 0){
            diff += bitDistance(y);
            y = y>>1;
        }
        return diff;
    }
    
    public int bitDistance(int x){
        System.out.print(x);
        if((x & 1) == 0){
            return 0;
        }
        if((x & 1) == 1){
            return 1;
        }
        return 0;
    }

    public static void main(String[] args){
        Solution sol = new Solution();
        System.out.println(sol.hammingDistance(4,2));
    }
}
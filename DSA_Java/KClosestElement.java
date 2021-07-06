import java.util.ArrayList;
import java.util.List;

/**
 * Find K closest elements from x  and return the list in sorted order.
 * Note: Input array is in sorted format. 
 * */
class KClosestElement {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        int sidx = 0;
        int[] difArr = new int[arr.length];
        for(int i=0;i<arr.length;i++){
            difArr[i] = Math.abs(arr[i] - x);
            sidx = difArr[i]<difArr[sidx]?i:sidx;
        }
        int left = sidx;
        int right = sidx;
        while(k>1){
            if(left>0 && right<(difArr.length-1)){
                if(difArr[left-1] <= difArr[right+1])
                    left--;
                else
                    right++;
            } else if(left>0)
                left--;
            else if(right<(difArr.length-1))
                right++;

            k--;
        }
        List<Integer> res = new ArrayList<>();
        for(int i=left;i<=right;i++)
            res.add(arr[i]);
        return res;
    }
}
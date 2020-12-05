class Solution {
    public int peakIndexInMountainArray(int[] A) {
        int maxHeight =0,idx = -1;
        for(int i=0;i<A.length;i++) {
            if(maxHeight<A[i])  {
                maxHeight = A[i];
                idx = i;
            }
        }
        return idx;
    }
}
class Solution {
    public int searchInsert(int[] nums, int target) {
        int idx = lowerbound(0,nums.length,target,nums);
        return idx;
    }
    private int lowerbound(int left,int right,int target,int[] arr) {
        while(left<right) {
            int mid=(left+right)/2;
            if(arr[mid]<target) left = mid+1;
            else right=mid;
        }
        return right;
    }
}
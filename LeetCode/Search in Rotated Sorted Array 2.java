class Solution {
    public boolean search(int[] nums, int target) {
        if(nums.length==0) return false;
        Arrays.sort(nums);
        int idx = lowerbound(0,nums.length-1,nums,target);
        if(nums[idx]!=target) return false;
        else return true;
    }
    private int lowerbound(int left,int right,int[] arr,int value) {
        while(left<right) {
            int mid = (left+right)/2;
            if(arr[mid]<value) left = mid+1;
            else right = mid;
        }
        return right;
    }
}
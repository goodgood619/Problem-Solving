class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] arr = new int[2];
        Arrays.fill(arr,-1);
        if(nums.length==0) {
            return arr;
        }
        int lidx = lowerbound(0,nums.length-1,nums,target);
        int uidx = upperbound(0,nums.length,nums,target);
        if(nums[lidx] != target) {
            return arr;
            }
        else {
            uidx--;
            arr[0]=lidx;
            arr[1]=uidx;
            return arr;
        }
    }
    private int lowerbound(int left,int right,int[] arr,int num) {
        while(left<right) {
            int mid =(left+right)/2;
            if(arr[mid]<num) left = mid+1;
            else right = mid;
        }
        return right;
    }
    private int upperbound(int left,int right,int[] arr,int num) {
        while(left<right) {
            int mid =(left+right)/2;
            if(arr[mid]<=num) left = mid+1;
            else right = mid;
        }
        return right;
    }
}
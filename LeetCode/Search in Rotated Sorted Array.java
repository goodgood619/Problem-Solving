class Solution {
    public int search(int[] nums, int target) {
        if(nums.length==0) return -1;
        int[] temp = new int[nums.length];
        for(int i=0;i<nums.length;i++) temp[i]=nums[i];
        Arrays.sort(nums);
        int idx = lowerbound(0,nums.length-1,nums,target);
        if(nums[idx]!=target) return -1;
        else {
            int idx2=0;
            for(int i=0;i<temp.length;i++) {
                if(target==temp[i]) {
                    idx2=i;
                    break;
                }
            }
            return idx2;
        }
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
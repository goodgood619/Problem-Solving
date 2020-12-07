class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int idx=0;
        for(int i=0;i<nums1.length;i++) {
            if(nums1[i]==0 && idx<nums2.length) {
                nums1[i] = nums2[idx++];
            }
        }
        Arrays.sort(nums1);
    }
}
class Solution {
    public String largestNumber(int[] nums) {
        String[] number = new String[nums.length];
        for(int i=0;i<nums.length;i++) {
            number[i] = String.valueOf(nums[i]);
        }
        Arrays.sort(number,(a,b)->compare(a,b));
        StringBuilder sb= new StringBuilder();
        for(int i=0;i<number.length;i++) {
            sb.append(number[i]);
        }
        if(sb.charAt(0)=='0' && sb.length()>=1) return "0";
        return sb.toString();
    }
    private int compare(String a,String b) {
        String first = a+b;
        String second = b+a;
        return second.compareTo(first);
    }
}
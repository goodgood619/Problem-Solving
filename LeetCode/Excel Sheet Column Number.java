class Solution {
    public int titleToNumber(String s) {
        int sum=0,idx=0;
        for(int i=s.length()-1;i>=0;i--) {
            char c= s.charAt(i);
            sum += (c-'A'+1)*Math.pow(26,idx++);
        }
        return sum;
    }
}
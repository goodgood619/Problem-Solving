class Solution {
    public boolean isPowerOfThree(int n) {
        if(n==0) return false;
        int p = n;
        while(p%3==0) {
            p/=3;   
        }
        if(p==1) return true;
        else return false;
    }
}
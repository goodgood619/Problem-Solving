class Solution {
    public long solution(int a, int b) {
        long a1 = (long)a;
        long b1 = (long)b;
        if(a1==b1) return a;
        else if(a1<b1) {
            return (b1*(b1+1)/2) - (a1*(a1-1)/2);
            
        }else{
            return a1*(a1+1)/2 - b1*(b1-1)/2;
        }
    
    }
}
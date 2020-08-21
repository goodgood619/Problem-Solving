class Solution {
    public boolean solution(int x) {
        int p = x;
        int num=0;
        while(p>0) {
            num += (p%10);
            p/=10;
        }
        if(x%num==0) return true;
        else return false;
    }
}
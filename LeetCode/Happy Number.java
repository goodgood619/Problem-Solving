class Solution {
    public boolean isHappy(int n) {
        Map<Integer,Integer> map = new HashMap<>();
        int p = n;
        while(map.get(p)==null) {
            map.put(p,1);
            int sum=0;
            while(p>0) {
                sum += (p%10)*(p%10);
                p/=10;
            }
            p = sum;
        }
        if(p==1) return true;
        else return false;
    }
}
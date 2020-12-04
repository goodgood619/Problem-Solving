class Solution {
    public int countPrimes(int n) {
        boolean[] notprime = new boolean[n+1];
        for(int i=2;i<=Math.sqrt(n);i++) {
            if(notprime[i]) continue;
            for(int j=i*i;j<=n;j+=i) {
                notprime[j]=true;
            }
        }
        int count=0;
        for(int i=2;i<n;i++) {
            if(!notprime[i]) {
                count++;
            }
        }
        return count;
    }
}
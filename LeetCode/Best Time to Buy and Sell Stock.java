class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int buy = (int)1e9,res=0;
        for(int i=0;i<prices.length;i++) {
            buy = Math.min(buy,prices[i]);
            res = Math.max(res,prices[i]-buy);
        }
        return res;
    }
}
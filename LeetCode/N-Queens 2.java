class Solution {
    int ans=0;
    public int totalNQueens(int n) {
        int[] arr = new int[n];
        go(0,n,arr);
        return ans;
    }
    private void go(int index,int depth,int[] arr) {
        if(index==depth) {
            ans++;
            return;
        }
        for(int i=1;i<=depth;i++) {
            arr[index] = i;
            if(check(index,arr)) {
                go(index+1,depth,arr);
            }
            else arr[index]=0;
        }
    }
    private boolean check(int index,int[] arr) {
        for(int i=0;i<index;i++) {
            if(arr[i]==arr[index] || Math.abs(i-index) == Math.abs(arr[i]-arr[index])) return false;
        }
        return true;
    }
}
class Solution {
    public List<List<String>> solveNQueens(int n) {
        int[] arr = new int[n];
        List<List<String>> ans = new ArrayList<>();
        go(0,n,arr,ans);
        return ans;
    }
    private void go(int index,int depth,int[] arr,List<List<String>> ans) {
        if(index==depth) {
            char[][] board = new char[depth][depth];
            for(int i=0;i<depth;i++) {
                for(int j=0;j<depth;j++) {
                    board[i][j]='.';
                }
            }
            for(int i=0;i<arr.length;i++) {
                board[i][arr[i]-1]='Q';
            }
            List<String> temp = new ArrayList<>();
            for(int i=0;i<depth;i++) {
                StringBuilder sb = new StringBuilder();
                for(int j=0;j<depth;j++) {
                    sb.append(board[i][j]);
                }
                temp.add(sb.toString());
            }
            ans.add(temp);
            return;
        }
        for(int i=1;i<=depth;i++) {
            arr[index] = i;
            if(check(index,arr)) {
                go(index+1,depth,arr,ans);
            }
            else arr[index]=0;
        }
        
    }
    private boolean check(int index,int[] arr) {
        for(int i=0;i<index;i++) {
            if(arr[i]==arr[index] || Math.abs(i-index)==Math.abs(arr[i]-arr[index])) return false;
        }
        return true;
    }
}
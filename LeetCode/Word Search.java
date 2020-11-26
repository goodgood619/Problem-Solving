class Solution {
    static int[] gox = {0,1,-1,0};
    static int[] goy={1,0,0,-1};
    static boolean ans = false;
    public boolean exist(char[][] board, String word) {
        ans = false;
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;i++) {
            for(int j=0;j<board[i].length;j++) {
                char c = word.charAt(0);
                if(board[i][j]==c) {
                    dfs(i,j,visited,board,board.length,board[0].length,word,1);
                    if(ans) return true;
                }
            }
        }
        return false;
    }
    private static void dfs(int x,int y,boolean[][] visited,char[][] board, int n,int m,String word,int idx) {
        if(ans) return;
        if(idx==word.length()){
            ans= true;
            return;
        }
        visited[x][y]=true;
        for(int i=0;i<4;i++) {
            int nx = x+gox[i], ny=y+goy[i];
            if(nx<0 || nx>=n || ny<0 ||ny>=m ||visited[nx][ny]|| word.charAt(idx)!=board[nx][ny]) continue;
            dfs(nx,ny,visited,board,n,m,word,idx+1);
        }
        visited[x][y]=false;
    }
}
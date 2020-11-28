class Solution {
    int[] gox = {0,1,-1,0};
    int[] goy = {1,0,0,-1};
    public int numIslands(char[][] grid) {
        if(grid.length==0) return 0;
        int count=0;
        boolean[][] visited = new boolean[grid.length][grid[0].length];
        for(int i=0;i<grid.length;i++) {
            for(int j=0;j<grid[i].length;j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    dfs(i,j,grid,visited,grid.length,grid[0].length);
                    count++;
                }
            }
        }
        return count;
    }
    private void dfs(int x,int y,char[][] board,boolean[][] visited,int n,int m) {
        visited[x][y]=true;
        for(int i=0;i<4;i++) {
            int nx = x+gox[i], ny=y+goy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny]=='0')continue;
            dfs(nx,ny,board,visited,n,m);
        }
    }
}
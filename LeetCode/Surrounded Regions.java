class Solution {
    int[] gox = {0,1,-1,0};
    int[] goy = {1,0,0,-1};
    public void solve(char[][] board) {
        if(board.length==0) return;
        boolean[][] visited = new boolean[board.length][board[0].length];
        for(int i=0;i<board.length;i++) {
            for(int j=0;j<board[i].length;j++) {
                if(!visited[i][j] && board[i][j]=='O') {
                    List<P> list =new ArrayList<>();
                    boolean ret =bfs(i,j,board,list,board.length,board[0].length,visited);
                    if(ret) {
                        for(P ele : list) {
                            board[ele.x][ele.y]='X';
                        }
                    }
                }
            }
        }
    }
    private boolean bfs(int sx,int sy,char[][] board, List<P> list,int n,int m,boolean[][] visited) {
        Deque<P> q= new ArrayDeque<>();
        q.add(new P(sx,sy));
        visited[sx][sy]=true;
        list.add(new P(sx,sy));
        boolean check = false;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            if(x==0 || x==n-1 || y==0 || y==m-1) {
                check = true;
            }
            q.poll();
            for(int i=0;i<4;i++) {
                int nx = x+gox[i], ny=y+goy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny]=='X') continue;
                list.add(new P(nx,ny));
                q.add(new P(nx,ny));
                visited[nx][ny]=true;
            }
        }
        if(check) return false;
        return true;
    }
}
class P {
    int x,y;
    P(int x,int y) {
        this.x = x;
        this.y = y;
    }
}
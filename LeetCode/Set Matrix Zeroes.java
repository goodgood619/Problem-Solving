class Solution {
    static int[] gox = {0,1,-1,0};
    static int[] goy=  {1,0,0,-1};
    public void setZeroes(int[][] board) {
        List<P> v = new ArrayList<>();
        int n= board.length;
        int m=board[0].length;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(board[i][j]==0) {
                    v.add(new P(i,j));
                }
            }
        }
        
        for(P p: v ) {
            int x= p.x;
            int y = p.y;
            int sx = x;
            int sy = y;
            for(int i=0;i<4;i++) {
                x = sx;
                y = sy;
                while(x+gox[i]<n && x+gox[i]>=0 && y+goy[i]<m && y+goy[i]>=0) {
                    x+=gox[i];
                    y+=goy[i];
                    board[x][y]=0;
                }
            }
        }
    }
    class P {
        int x,y;
        P(int x,int y){
            this.x = x;
            this.y = y;
        }
    }
}
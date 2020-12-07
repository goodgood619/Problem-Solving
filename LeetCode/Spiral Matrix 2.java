class Solution {
    static int[] gox = {0,1,0,-1};
    static int[] goy = {1,0,-1,0};
    public int[][] generateMatrix(int n) {
        int[][] matrix = new int[n][n];
        int sx = 0 ,sy = 0,cnt=0,dir=0;
        while(true) {
            if(cnt==n*n) break;
            matrix[sx][sy] = cnt+1;
            for(int i=dir;;i++) {
                if(i>=4) i=0;
                if(cnt==n*n-1) break;
                int nx = sx+gox[i],ny = sy+goy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n || matrix[nx][ny]!=0) continue;
                else {
                    sx = nx;
                    sy = ny;
                    dir = i;
                    break;
                }
            }
            cnt++;
        }
        
        return matrix;
    }
}
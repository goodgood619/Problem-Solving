import java.io.*;
import java.util.ArrayDeque;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int tc = 1;tc<=t;tc++) {
            String[] input = br.readLine().split(" ");
            int n = Integer.parseInt(input[1]);
            int m = Integer.parseInt(input[0]);
            int k = Integer.parseInt(input[2]);
            int[][] board = new int[n][m];
            boolean[][] visited = new boolean[n][m];
            for(int i=1;i<=k;i++) {
                String[] input2 = br.readLine().split(" ");
                int x = Integer.parseInt(input2[1]);
                int y = Integer.parseInt(input2[0]);
                board[x][y] = 1;
            }
            int cnt = 0;
            for(int i=0;i<n;i++) {
                for(int j=0;j<m;j++) {
                    if(!visited[i][j] && board[i][j] == 1) {
                        bfs(i,j,board,visited,n,m);
                        cnt++;
                    }
                }
            }
            bw.write(cnt+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static void bfs(int sx,int sy,int[][] board,boolean[][] visited,int n,int m) {
        ArrayDeque<p> q = new ArrayDeque<p>();
        q.add(new p(sx,sy));
        visited[sx][sy] = true;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for(int i=0;i<4;i++) {
                int nx = x + gox[i], ny = y+goy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.add(new p(nx,ny));
            }
        }
    }
    private static class p{
        int x,y;
        private p(int x,int y) {
            this.x = x;
            this.y = y;
        }
    }
}
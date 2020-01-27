import java.io.*;
import java.util.ArrayDeque;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[]gox = {0,1,-1,0};
    static int[]goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        char[][] board = new char[n][m];
        boolean[][] visited = new boolean[n][m];
        for(int i=0;i<n;i++) {
            String input2 = br.readLine();
            for(int j=0;j<input2.length();j++) {
                board[i][j] = input2.charAt(j);
                visited[i][j] = false;
            }
        }

        bw.write(String.valueOf(bfs(0,0,board,visited,n-1,m-1,n,m)));
        bw.flush();
        bw.close();
    }
    private static int bfs(int sx,int sy,char[][] board, boolean[][] visited,int ex,int ey,int n,int m) {
        ArrayDeque<p> q = new ArrayDeque<p>();
        q.add(new p(sx,sy,1));
        visited[sx][sy] = true;
        int ans = 0;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            if(x == ex && y == ey) {
                ans = dist;
                break;
            }
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = x+gox[i];
                int ny = y+goy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=m || visited[nx][ny] || board[nx][ny]=='0') continue;
                visited[nx][ny] = true;
                q.add(new p(nx,ny,dist+1));
            }
        }
        return ans;
    }
    private static class p{
        int x,y,dist;
        private p(int x,int y,int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}

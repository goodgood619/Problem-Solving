import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,-1,1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j] = s.charAt(j)-'0';
            }
        }
        int ans = bfs(0,0,n,m,board);
        System.out.println(ans==(int)1e9?-1:ans);
    }
    private static int bfs(int sx,int sy,int ex,int ey,int[][] board) {
        int temp = (int)1e9;
        ArrayDeque<p> q = new ArrayDeque<>();
        int[][][] dist = new int[ex][ey][2];
        boolean[][][] visited = new boolean[ex][ey][2];
        dist[sx][sy][0] = 1;
        visited[sx][sy][0] = true;
        q.add(new p(sx,sy,0));

        while(!q.isEmpty()) {
            int x= q.peek().x;
            int y = q.peek().y;
            int cost = q.peek().cost;
            if(x == ex-1 && y == ey-1) {
                temp = min(temp,dist[x][y][cost]);
                break;
            }
            q.poll();
            for(int i=0;i<4;i++) {
                int nx = x+gox[i], ny = y+goy[i];
                if(nx<0 || nx>=ex || ny<0 || ny>=ey) continue;
                if (cost < 1) {
                    if (board[nx][ny] == 0) {
                        if (!visited[nx][ny][cost]) {
                            visited[nx][ny][cost] = true;
                            q.add(new p(nx,ny,cost));
                            dist[nx][ny][cost] = dist[x][y][cost] + 1;
                        }
                    }
                    else {
                        if (!visited[nx][ny][cost + 1]) {
                            visited[nx][ny][cost + 1] = true;
                            q.add(new p(nx,ny,cost+1));
                            dist[nx][ny][cost + 1] = dist[x][y][cost] + 1;
                        }
                    }
                }
                else {
                    if (board[nx][ny] == 1) continue;
                    if (!visited[nx][ny][cost]) {
                        visited[nx][ny][cost] = true;
                        q.add(new p(nx,ny,cost));
                        dist[nx][ny][cost] = dist[x][y][cost] + 1;
                    }
                }
            }
        }
        return temp;
    }
    private static class p {
        int x,y,cost;
        private p(int x,int y,int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
}
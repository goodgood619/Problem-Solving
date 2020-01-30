import java.io.*;
import java.util.ArrayDeque;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int k = Integer.parseInt(input[2]);
        char[][] food = new char[n+1][m+1];
        boolean[][] visited = new boolean[n+1][m+1];
        for(int i=0;i<k;i++) {
            String[] input2 = br.readLine().split(" ");
            int u = Integer.parseInt(input2[0]);
            int v =Integer.parseInt(input2[1]);
            food[u][v]= '#';
        }
        int ans = 0;
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                if(!visited[i][j] && food[i][j]=='#') {
                    ans = max(ans,bfs(i,j,food,visited,n,m));
                }
            }
        }
        System.out.println(ans);
    }
    private static int bfs(int sx,int sy,char[][] food,boolean[][] visited, int n,int m) {
        int cnt = 1;
        int temp = 0;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx,sy));
        visited[sx][sy] =true;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for(int i=0;i<4;i++) {
                int nx = x +gox[i];
                int ny = y+goy[i];
                if(nx<1 || nx>n || ny<1 || ny>m || food[nx][ny]=='\0' || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.add(new p(nx,ny));
                cnt++;
                temp = max(temp,cnt);
            }
        }
        return temp;
    }
    private static class p {
        int x,y;
        private p(int x,int y) {
            this.x = x;
            this.y = y;
        }
    }
}
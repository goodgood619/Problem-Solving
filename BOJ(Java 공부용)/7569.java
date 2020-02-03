import java.io.*;
import java.util.ArrayDeque;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    static int[] goz = {1,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int m = Integer.parseInt(input[0]), n = Integer.parseInt(input[1]), h = Integer.parseInt(input[2]);
        int[][][] tomato = new int[h][n][m];
        boolean[][][] visited = new boolean[h][n][m];
        int zero = 0;
        ArrayDeque<p> q = new ArrayDeque<>();
        for(int i=0;i<h;i++) {
            for(int j=0;j<n;j++) {
                String[] input2 = br.readLine().split(" ");
                for(int k=0;k<input2.length;k++) {
                    int a = Integer.parseInt(input2[k]);
                    tomato[i][j][k] = a;
                    if(tomato[i][j][k] == 1) {
                        q.add(new p(i,j,k,0));
                        zero++;
                        visited[i][j][k] = true;
                    }
                    else if(tomato[i][j][k]== -1) zero++;
                }
            }
        }

        if(zero == n*m*h) System.out.println(0);
        else {
            int ans = bfs(q,visited,tomato,n,m,h);
            boolean check = false;
            for(int i=0;i<h;i++) {
                for(int j=0;j<n;j++) {
                    for(int k=0;k<m;k++) {
                        if(tomato[i][j][k] == 0) check = true;
                    }
                }
            }
            System.out.println(check?-1:ans);
        }
    }
    private static int bfs(ArrayDeque<p> q,boolean[][][] visited, int[][][] tomato,int n,int m,int h) {
        int max = 0;
        while(!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            int cnt = q.peek().cnt;
            max = max(max,cnt);
            q.poll();
            for(int i=0;i<4;i++) {
                int ny = y +gox[i], nz = z+goy[i];
                if(ny<0 || ny>=n || nz<0 || nz>=m || visited[x][ny][nz] || tomato[x][ny][nz] == -1) continue;
                else if(tomato[x][ny][nz] == 0) {
                    visited[x][ny][nz] = true;
                    tomato[x][ny][nz] = 1;
                    q.add(new p(x,ny,nz,cnt+1));
                }
            }
            for(int i=0;i<2;i++) {
                int nx = x+goz[i];
                if(nx<0 || nx>=h || visited[nx][y][z] || tomato[nx][y][z]== -1) continue;
                else if(tomato[nx][y][z] == 0) {
                    visited[nx][y][z] = true;
                    tomato[nx][y][z] = 1;
                    q.add(new p(nx,y,z,cnt+1));
                }
            }
        }
        return max;
    }
    private static class p {
        int x,y,z,cnt;
        private p(int x,int y,int z,int cnt) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.cnt = cnt;
        }
    }
}
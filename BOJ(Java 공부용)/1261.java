import java.io.*;
import java.util.PriorityQueue;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox  = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int m = Integer.parseInt(input[0]), n = Integer.parseInt(input[1]);
        char[][] board = new char[n][m];
        for(int i=0;i<n;i++) {
            String s = br.readLine();
            for(int j=0;j<s.length();j++) {
                board[i][j] = s.charAt(j);
            }
        }
        dijk(0,0,n-1,m-1,board);
    }
    private static void dijk(int sx,int sy,int ex,int ey,char[][] board) throws IOException {
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if(a.cost<b.cost) return -1;
            else if(a.cost>b.cost) return 1;
            else {
                if(a.x <b.x) return -1;
                else if(a.x>b.x) return 1;
                else {
                    if(a.y<b.y) return -1;
                    else if(a.y>b.y) return 1;
                    else return 0;
                }
            }
        });
        int[][] dist = new int[ex+1][ey+1];
        for(int i=0;i<ex+1;i++) {
            for(int j=0;j<ey+1;j++) {
                dist[i][j] = (int) 1e9;
            }
        }
        dist[0][0] = 0;
        pq.add(new p(0,sx,sy));
        while(!pq.isEmpty()) {
            assert pq.peek() != null;
            int cost = pq.peek().cost;
            int x = pq.peek().x;
            int y = pq.peek().y;
            pq.poll();
            if(cost > dist[x][y]) continue;
            for(int i=0;i<4;i++) {
                int nx = x+gox[i], ny = y+goy[i];
                if(nx<0 || nx>=ex+1 || ny<0 || ny>=ey+1) continue;
                if(board[nx][ny]=='1') {
                    if (dist[nx][ny] > dist[x][y] + 1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        pq.add(new p(dist[nx][ny],nx,ny));
                    }
                }
                else {
                    if(dist[nx][ny]>dist[x][y]) {
                        dist[nx][ny] = dist[x][y];
                        pq.add(new p(dist[nx][ny],nx,ny));
                    }
                }
            }
        }
        bw.write(dist[ex][ey]+"\n");
        bw.flush();
        bw.close();
    }
    private static class p {
        int cost,x,y;
        private p(int cost,int x,int y){
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
}
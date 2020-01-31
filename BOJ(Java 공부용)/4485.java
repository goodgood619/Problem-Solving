import java.io.*;
import java.util.PriorityQueue;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = 1;
        while(true) {
            int n = Integer.parseInt(br.readLine().split(" ")[0]);
            if(n==0) break;
             int[][] board = new int[n][n];
            int[][] dp = new int[n][n];
            for(int i=0;i<n;i++) {
                String[] input2 = br.readLine().split(" ");
                for(int j=0;j<input2.length;j++) {
                    board[i][j] = Integer.parseInt(input2[j]);
                }
            }
            dijk(board,dp,n);
            bw.write("Problem "+tc+": "+dp[n-1][n-1]+"\n");
            tc++;
        }
        bw.flush();
        bw.close();
    }
    private static void dijk(int[][] board,int[][] dp, int n) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                dp[i][j] = 1000000000;
            }
        }

        dp[0][0] = board[0][0];
        PriorityQueue<p> pq = new PriorityQueue<>((a,b)->{
            if(a.cost<b.cost) {
                return -1;
            }
            else if(a.cost > b.cost) return 1;
            else {
                if(a.x < b.x) return -1;
                else if(a.x>b.x) return 1;
                else {
                    if(a.y<b.y) return -1;
                    else if(a.y > b.y) return 1;
                    else return 0;
                }
            }
        });
        pq.add(new p(0,0,board[0][0]));
        while(!pq.isEmpty()) {
            int x = pq.peek().x;
            int y = pq.peek().y;
            int cost = pq.peek().cost;
            pq.poll();
            if(dp[x][y]<cost) continue;
            for(int i=0;i<4;i++) {
                int nx = x+gox[i], ny = y+goy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(dp[nx][ny]>dp[x][y]+board[nx][ny]) {
                    dp[nx][ny] = dp[x][y] + board[nx][ny];
                    pq.add(new p(nx,ny,cost));
                }
            }
        }
    }
    private static class p {
        int x,y,cost;
        private p(int x,int y, int cost) {
            this.x = x;
            this.y = y;
            this.cost = cost;
        }
    }
}
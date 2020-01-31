import java.io.*;
import java.util.ArrayDeque;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t = 0, total = 0;
    static ArrayDeque<Integer> st = new ArrayDeque<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int m = Integer.parseInt(br.readLine().split(" ")[0]);
        int[][] board = new int[n+1][n+1];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i!=j) board[i][j] = (int)1e9;
            }
        }
        for(int i=1;i<=m;i++) {
            String[] input2 = br.readLine().split(" ");
            int here = Integer.parseInt(input2[0]), next = Integer.parseInt(input2[1]), cost = Integer.parseInt(input2[2]);
            if(board[here][next]>cost) board[here][next] = cost;
        }

        for(int k=1;k<=n;k++) {
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    if(board[i][j]>board[i][k]+board[k][j]) board[i][j] = board[i][k]+board[k][j];
                }
            }
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                if(i == j || board[i][j] == (int)1e9) bw.write(0+" ");
                else bw.write(board[i][j]+" ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }
}
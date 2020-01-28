import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[][] board = new int[n][n];
        for(int i=0;i<n;i++) {
            String[] input = br.readLine().split(" ");
            for(int j=0;j<input.length;j++) {
                board[i][j] = Integer.parseInt(input[j]);
            }
        }

        for(int k=0;k<n;k++) {
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(board[i][k] == 1 && board[k][j] == 1) board[i][j] = 1;
                }
            }
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j] == 1) {
                    if(j == n-1) {
                        bw.write("1\n");
                    }else {
                        bw.write("1 ");
                    }
                }
                else {
                    if(j == n-1) {
                        bw.write("0\n");
                    }
                    else bw.write("0 ");
                }
            }
        }
        bw.flush();
        bw.close();
    }
}
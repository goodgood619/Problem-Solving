import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) System.out.println("*");
        else{
            char[][] board = new char[n+1][2*n];
            int x = 1;
            int y = n;
            for (int i = x,j=y;i <= n;i++,j--){
                board[i][j] = '*';
            }
            for (int i = x, j = y; i <= n; i++, j++) {
                board[i][j] = '*';
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n + i - 1; j++) {
                    if (board[i][j] == '*') bw.write("*");
                    else bw.write(" ");
                }
                bw.write("\n");
            }
        }
        bw.flush();
        bw.close();
    }
}
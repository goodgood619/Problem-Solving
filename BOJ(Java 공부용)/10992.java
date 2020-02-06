import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) System.out.println('*');
        else {
            char[][] board = new char[n + 1][2 * n];
            int herex = 1;
            int herey = n;
            // 왼쪽대각선
            for (int i = herex, j = n; i <= n && j >= 1; i++, j--) {
                board[i][j] = '*';
            }
            for (int i = herex, j = n; i <= n && j <= 2 * n - 1; i++, j++) {
                board[i][j] = '*';
            }
            for (int i = n, j = 1; j <= 2 * n - 1; j++) {
                board[i][j] = '*';
            }
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n + j - 1; k++) {
                    if (board[j][k] == '\0') bw.write(" ");
                    else bw.write(board[j][k]);
                }
                bw.write("\n");
            }
            bw.flush();
            bw.close();
        }
    }
}
import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if (n == 1) System.out.println('*');
        else {
            char[][] board = new char[n + 1][2 * n + 1];
            for (int i = 1; i <= n; i++) {
                int start = 0;
                int cnt = 1;
                if (i % 2 == 1) start = 1;
                else start = 2;
                for (int j = start; cnt <= n; j += 2) {
                    board[i][j] = '*';
                    cnt++;
                }
            }
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= 2 * n; k++) {
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
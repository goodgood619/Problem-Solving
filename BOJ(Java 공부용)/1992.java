import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j) - '0';
            }
        }
        go(0, 0, n, board, sb);
        bw.write(sb.toString());
        bw.flush();
        bw.close();
    }

    private static void go(int x, int y, int n, int[][] board, StringBuilder sb) {
        int one = 0, zero = 0;
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (board[i][j] == 1) one++;
                else zero++;
            }
        }
        if (one == n * n) {
            sb.append(1);
            return;
        }
        if (zero == n * n) {
            sb.append(0);
            return;
        }
        sb.append('(');
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                go(x + i * n / 2, y + j * n / 2, n / 2, board, sb);
            }
        }
        sb.append(')');
    }
}
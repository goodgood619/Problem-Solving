import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    static int a = 0, b = 0, c = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        go(0, 0, n, board);
        System.out.println(c + "\n" + a + "\n" + b);
    }

    private static void go(int x, int y, int n, int[][] board) {
        int zero = 0, one = 0, minusone = 0;
        for (int i = x; i < x + n; i++) {
            for (int j = y; j < y + n; j++) {
                if (board[i][j] == 0) zero++;
                if (board[i][j] == -1) minusone++;
                if (board[i][j] == 1) one++;
            }
        }

        if (zero == n * n || one == n * n || minusone == n * n) {
            if (zero == n * n) a++;
            if (one == n * n) b++;
            if (minusone == n * n) c++;
        } else {
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    go(x + i * n / 3, y + j * n / 3, n / 3, board);
                }
            }
        }
    }
}
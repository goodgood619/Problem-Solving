import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n + 1][n + 1];
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            board[first][second] = -1;
            board[second][first] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (board[i][k] == 1 && board[k][j] == 1) board[i][j] = 1;
                    if (board[i][k] == -1 && board[k][j] == -1) board[i][j] = -1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (i == j || board[i][j] == 0) continue;
                cnt++;
            }
            if (cnt == n - 1) ans++;
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }
}
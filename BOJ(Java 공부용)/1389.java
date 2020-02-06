import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != j) board[i][j] = (int) 1e9;
            }
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
            board[left][right] = 1;
            board[right][left] = 1;
        }
        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (board[i][j] > board[i][k] + board[k][j]) board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
        int ans = (int) 1e9;
        int[] num = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            int Max = 0;
            for (int j = 1; j <= n; j++) {
                if (i != j) Max += board[i][j];
            }
            ans = min(ans, Max);
            num[i] = Max;
        }
        for (int i = 1; i <= n; i++) {
            if (ans == num[i]) {
                bw.write(i + " ");
                break;
            }
        }
        bw.flush();
        bw.close();
    }
}
import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int sx = Integer.parseInt(st.nextToken()), sy = Integer.parseInt(st.nextToken()), ex = Integer.parseInt(st.nextToken()), ey = Integer.parseInt(st.nextToken());
            sx--;
            sy--;
            ex--;
            ey--;
            int sum = 0;
            for (int j = sx; j <= ex; j++) {
                for (int p = sy; p <= ey; p++) {
                    sum += board[j][p];
                }
            }
            bw.write(sum + "\n");
        }
        bw.flush();
        bw.close();
    }
}
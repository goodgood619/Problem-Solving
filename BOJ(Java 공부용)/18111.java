import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int min = (int) 1e9, max = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                min = min(min, board[i][j]);
                max = max(max, board[i][j]);
            }
        }
        int minTime = (int) 1e9, height = 0;
        for (int k = max; k >= min; k--) {
            int bcnt = 0, rcnt = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    int diff = board[i][j] - k;
                    if (diff < 0) bcnt = bcnt - diff;
                    else rcnt += diff;
                }
            }

            if (rcnt + b >= bcnt) {
                int time = rcnt * 2 + bcnt;
                if (time < minTime) {
                    minTime = time;
                    height = k;
                }
            }
        }
        bw.write(minTime + " " + height + "");
        bw.flush();
        bw.close();
    }
}
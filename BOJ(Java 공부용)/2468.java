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
        int n = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][n];
        int min = (int) 1e9, max = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                min = min(min, board[i][j]);
                max = max(max, board[i][j]);
            }
        }

        if (min == max) bw.write("1");
        else {
            int ans = 0;
            for (int i = min; i <= max; i++) {
                boolean[][] visited = new boolean[n][n];

                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (board[j][k] <= i) {
                            visited[j][k] = true;
                        }
                    }
                }
                int cnt = 0;
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (!visited[j][k]) {
                            dfs(j, k, n, visited);
                            cnt++;
                        }
                    }
                }

                ans = max(ans, cnt);
            }
            bw.write(ans + " ");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int x, int y, int n, boolean[][] visited) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
            dfs(nx, ny, n, visited);
        }
    }
}
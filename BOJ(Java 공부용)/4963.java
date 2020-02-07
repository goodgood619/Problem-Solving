import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            int[][] board = new int[n][m];
            boolean[][] visited = new boolean[n][m];
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                for (int j = 0; j < m; j++) {
                    board[i][j] = Integer.parseInt(st.nextToken());
                }
            }
            int land = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (!visited[i][j] && board[i][j] == 1) {
                        bfs(i, j, board, visited, n, m);
                        land++;
                    }
                }
            }
            bw.write(land + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void bfs(int sx, int sy, int[][] board, boolean[][] visited, int n, int m) {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        visited[sx][sy] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 8; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
            }
        }
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
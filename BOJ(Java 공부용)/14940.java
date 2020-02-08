import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int sx = 0, sy = 0;
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                if (board[i][j] == 2) {
                    sx = i;
                    sy = j;
                }
            }
        }

        bfs(sx, sy, board, n, m);

    }

    private static void bfs(int sx, int sy, int[][] board, int n, int m) throws IOException {
        int[][] dist = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 0) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 0) bw.write(0 + " ");
                else if (board[i][j] == 1 && dist[i][j] == 0) bw.write(-1 + " ");
                else bw.write(dist[i][j] + " ");
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
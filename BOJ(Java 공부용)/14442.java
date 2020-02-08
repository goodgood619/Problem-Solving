import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int[][][] dist = new int[n][m][k + 1];
        boolean[][][] visited = new boolean[n][m][k + 1];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j) - '0';
            }
        }
        bfs(0, 0, board, dist, visited, n, m, k);
    }

    private static void bfs(int sx, int sy, int[][] board, int[][][] dist, boolean[][][] visited, int n, int m, int k) throws IOException {
        visited[sx][sy][k] = true;
        dist[sx][sy][k] = 1;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, k));
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int cnt = q.peek().cnt;
            if (x == n - 1 && y == m - 1) {
                ans = min(ans, dist[x][y][cnt]);
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny][cnt]) continue;
                if (board[nx][ny] == 0) {
                    visited[nx][ny][cnt] = true;
                    q.add(new p(nx, ny, cnt));
                    dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
                } else if (board[nx][ny] == 1) {
                    if (cnt > 0) {
                        visited[nx][ny][cnt - 1] = true;
                        q.add(new p(nx, ny, cnt - 1));
                        dist[nx][ny][cnt - 1] = dist[x][y][cnt] + 1;
                    }
                }
            }
        }
        bw.write(ans == 1e9 ? "-1" : ans + " ");
        bw.flush();
        bw.close();
        //그냥가거나, 벽을뚫을수있다면 뚫어서 가던가

    }

    private static class p {
        int x, y, cnt;

        private p(int x, int y, int cnt) {
            this.x = x;
            this.y = y;
            this.cnt = cnt;
        }
    }
}
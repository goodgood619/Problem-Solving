import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
            if (m == 0 && n == 0) break;
            char[][] board = new char[n][m];
            int[][] dist = new int[11][11];
            int[][] dp = new int[10][(1 << 10)];

            ArrayList<p> v = new ArrayList<>();
            int start = 0, here = 0;

            for (int i = 0; i < n; i++) {
                String s = br.readLine();
                for (int j = 0; j < s.length(); j++) {
                    if (s.charAt(j) == ' ') break;
                    board[i][j] = s.charAt(j);
                    if (board[i][j] == 'o') {
                        start = here;
                        v.add(new p(i, j));
                        here++;
                    } else if (board[i][j] == '*') {
                        v.add(new p(i, j));
                        here++;
                    }
                }
            }

            boolean no = false;

            for (int i = 0; i < v.size(); i++) {
                for (int j = i + 1; j < v.size(); j++) {
                    int d = bfs(v.get(i).first, v.get(i).second, v.get(j).first, v.get(j).second, board, n, m);
                    if (d == 1e9) {
                        no = true;
                        break;
                    }
                    dist[i][j] = d;
                    dist[j][i] = d;
                }
                if (no) break;
            }
            if (no) {
                bw.write("-1\n");
                continue;
            }
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < (1 << 10); j++) {
                    dp[i][j] = -1;
                }
            }

            bw.write(go(start, (1 << start), dp, dist, here) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int start, int via, int[][] dp, int[][] dist, int total) {
        if (via == (1 << total) - 1) {
            return 0;
        }
        if (dp[start][via] != -1) return dp[start][via];
        dp[start][via] = (int) 1e9;
        for (int i = 0; i < total; i++) {
            if (i == start) continue;
            if ((via & (1 << i)) == 0) {
                dp[start][via] = min(dp[start][via], go(i, via | (1 << i), dp, dist, total) + dist[start][i]);
            }
        }
        return dp[start][via];
    }

    private static int bfs(int sx, int sy, int ex, int ey, char[][] board, int n, int m) {
        boolean[][] visited = new boolean[n][m];
        int[][] dist = new int[n][m];
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        while (!q.isEmpty()) {
            int x = q.peek().first;
            int y = q.peek().second;
            if (x == ex && y == ey) return dist[x][y];
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 'x') continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
        return (int) 1e9;
    }

    private static class p {
        int first, second;

        private p(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}
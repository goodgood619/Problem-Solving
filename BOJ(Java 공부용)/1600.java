import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};
    static int[] go2x = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int[] go2y = {-1, 1, -2, 2, -2, 2, -1, 1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int k = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(bfs(0, 0, k, n, m, board));
    }

    private static int bfs(int sx, int sy, int k, int n, int m, int[][] board) {
        boolean[][][] visited = new boolean[n][m][k + 1];
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, k, 0));
        visited[sx][sy][k] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int jump = q.peek().jump;
            int dist = q.peek().dist;
            q.poll();
            if (x == n - 1 && y == m - 1) return dist;
            if (jump > 0) {
                for (int i = 0; i < 8; i++) {
                    int nx = x + go2x[i], ny = y + go2y[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1 || visited[nx][ny][jump - 1])
                        continue;
                    visited[nx][ny][jump - 1] = true;
                    q.add(new p(nx, ny, jump - 1, dist + 1));
                }
            }
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 1 || visited[nx][ny][jump]) continue;
                visited[nx][ny][jump] = true;
                q.add(new p(nx, ny, jump, dist + 1));
            }
        }
        return -1;
    }

    private static class p {
        int x, y, jump, dist;

        private p(int x, int y, int jump, int dist) {
            this.x = x;
            this.y = y;
            this.jump = jump;
            this.dist = dist;
        }
    }
}
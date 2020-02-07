import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n + 2][m + 2];
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        bfs(board, n, m);
    }

    private static void bfs(int[][] board, int n, int m) {
        ArrayDeque<p> q = new ArrayDeque<>();
        int ti = 0;
        for (int t = 1; ; t++) {
            ArrayDeque<p> temp = new ArrayDeque<>();
            q.add(new p(0, 0));
            boolean[][] visited = new boolean[n + 2][m + 2];
            int[][] dist = new int[n + 2][m + 2];
            visited[0][0] = true;
            while (!q.isEmpty()) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx < 0 || nx > n + 1 || ny < 0 || ny > m + 1 || visited[nx][ny]) continue;
                    if (board[nx][ny] == 0) {
                        visited[nx][ny] = true;
                        q.add(new p(nx, ny));
                    }
                    if (board[nx][ny] == 1) {
                        dist[nx][ny]++;
                        if (dist[nx][ny] >= 2) {
                            visited[nx][ny] = true;
                            temp.add(new p(nx, ny));
                        }
                    }
                }
            }
            if (temp.size() == 0) break;
            ti = t;
            while (!temp.isEmpty()) {
                int x = temp.peek().x;
                int y = temp.peek().y;
                temp.poll();
                board[x][y] = 0;
            }
        }
        System.out.println(ti);
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        int[][] height = new int[n][m];
        int sx = -1, sy = -1, ex = 0, ey = 0;
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'L') {
                    if (sx == -1) {
                        sx = i;
                        sy = j;
                    } else {
                        ex = i;
                        ey = j;
                    }
                }
            }
        }

        int left = 0, right = remove(board, n, m, height), ans = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (bfs(sx, sy, ex, ey, mid, board, height, n, m)) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        bw.write(ans + " ");
        bw.flush();
        bw.close();
    }

    private static boolean bfs(int sx, int sy, int ex, int ey, int mid, char[][] board, int[][] height, int n, int m) {
        boolean[][] visited = new boolean[n][m];
        visited[sx][sy] = true;
        Deque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            if (x == ex && y == ey) return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || height[nx][ny] > mid) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
            }
        }


        return false;
    }

    private static int remove(char[][] board, int n, int m, int[][] height) {
        int cnt = 1;
        boolean[][] visited = new boolean[n][m];
        Deque<p> q = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.' || board[i][j] == 'L') {
                    visited[i][j] = true;
                    q.add(new p(i, j));
                }
            }
        }
        while (!q.isEmpty()) {
            int size = q.size();
            while (size-- > 0) {
                int x = q.peek().x;
                int y = q.peek().y;
                q.poll();
                for (int i = 0; i < 4; i++) {
                    int nx = x + gox[i], ny = y + goy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                    visited[nx][ny] = true;
                    q.add(new p(nx, ny));
                    height[nx][ny] = cnt;
                }
            }
            cnt++;
        }
        return cnt;
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
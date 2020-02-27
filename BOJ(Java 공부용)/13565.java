import java.io.*;
import java.util.ArrayDeque;
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
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j) - '0';
            }
        }

        for (int i = 0; i < m; i++) {
            if (!visited[0][i] && board[0][i] == 0) {
                bfs(0, i, n, m, board, visited);
            }
        }
        System.out.println("NO");
    }

    private static void bfs(int sx, int sy, int n, int m, int[][] board, boolean[][] visited) {
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            if (x == n - 1) {
                System.out.println("YES");
                System.exit(0);
            }
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || board[nx][ny] == 1) continue;
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
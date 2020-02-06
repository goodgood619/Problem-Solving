import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        char[][] board = new char[n][m];
        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                board[i][j] = s.charAt(j);
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'L') max = max(max, bfs(i, j, board, n, m));
            }
        }
        System.out.println(max);
    }

    private static int bfs(int sx, int sy, char[][] board, int n, int m) {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, 0));
        boolean[][] visited = new boolean[n][m];
        visited[sx][sy] = true;
        int sum = 0;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            q.poll();
            sum = max(sum, dist);
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == 'W' || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny, dist + 1));
            }
        }
        return sum;
    }

    private static class p {
        int x, y, dist;

        private p(int x, int y, int dist) {
            this.x = x;
            this.y = y;
            this.dist = dist;
        }
    }
}
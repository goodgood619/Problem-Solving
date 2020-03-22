import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) board[i][j] = Integer.parseInt(st.nextToken());
        }

        bfs(0, 0, n, m, board, visited);
    }

    private static void bfs(int sx, int sy, int n, int m, int[][] board, boolean[][] visited) {
        Deque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, 0));
        visited[sx][sy] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            if (x == n - 1 && y == m - 1) {
                System.out.println(dist);
                break;
            }
            q.poll();
            int go = board[x][y];
            for (int i = 0; i < 2; i++) {
                int temp = go;
                int tx = x, ty = y;
                while (tx + gox[i] < n && ty + goy[i] < m && temp > 0) {
                    temp--;
                    tx += gox[i];
                    ty += goy[i];
                    if (!visited[tx][ty]) {
                        visited[tx][ty] = true;
                        q.add(new p(tx, ty, dist + 1));
                    }
                }
            }
        }
    }
}

class p {
    int x, y, dist;

    p(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}

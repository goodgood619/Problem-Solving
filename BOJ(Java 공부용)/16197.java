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
        char[][] board = new char[n][m];
        int onex = -1, oney = -1, twox = -1, twoy = -1;

        for (int i = 0; i < n; i++) {
            String s = br.readLine();
            for (int j = 0; j < s.length(); j++) {
                if (s.charAt(j) == ' ') break;
                board[i][j] = s.charAt(j);
                if (board[i][j] == 'o') {
                    if (onex == -1) {
                        onex = i;
                        oney = j;
                    } else {
                        twox = i;
                        twoy = j;
                    }
                }
            }
        }

        bfs(onex, oney, twox, twoy, board, n, m);
    }

    private static boolean outcheck(int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) return true;
        return false;
    }

    private static void bfs(int ox, int oy, int tx, int ty, char[][] board, int n, int m) {
        boolean[][][][] visited = new boolean[n][m][n][m];
        visited[ox][oy][tx][ty] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(ox, oy, tx, ty, 0));
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int sx = q.peek().ox;
            int sy = q.peek().oy;
            int ex = q.peek().tx;
            int ey = q.peek().ty;
            int dist = q.peek().dist;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = sx + gox[i], ny = sy + goy[i], nex = ex + gox[i], ney = ey + goy[i];
                if (outcheck(nx, ny, n, m) && outcheck(nex, ney, n, m)) continue;
                if (outcheck(nx, ny, n, m) ^ outcheck(nex, ney, n, m)) {
                    ans = dist + 1;
                    break;
                }
                if (board[nx][ny] == '#' && board[nex][ney] == '#') continue;
                if (visited[nx][ny][nex][ney]) continue;
                if (board[nx][ny] == '#') {
                    if (!visited[sx][sy][nex][ney]) {
                        visited[sx][sy][nex][ney] = true;
                        q.add(new p(sx, sy, nex, ney, dist + 1));
                    }
                } else if (board[nex][ney] == '#') {
                    if (!visited[nx][ny][ex][ey]) {
                        visited[nx][ny][ex][ey] = true;
                        q.add(new p(nx, ny, ex, ey, dist + 1));
                    }
                } else {
                    if (!visited[nx][ny][nex][ney]) {
                        visited[nx][ny][nex][ney] = true;
                        q.add(new p(nx, ny, nex, ney, dist + 1));
                    }
                }
            }
            if (ans != 1e9) break;
        }
        System.out.println(ans > 10 ? -1 : ans);
    }

    private static class p {
        int ox, oy, tx, ty, dist;

        private p(int ox, int oy, int tx, int ty, int dist) {
            this.ox = ox;
            this.oy = oy;
            this.tx = tx;
            this.ty = ty;
            this.dist = dist;
        }
    }
}
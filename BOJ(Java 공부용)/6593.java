import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken()), z = Integer.parseInt(st.nextToken());
            if (x == 0 && y == 0 && z == 0) break;
            char[][][] board = new char[x][y][z];
            boolean[][][] visited = new boolean[x][y][z];
            int sx = 0, sy = 0, sz = 0, ex = 0, ey = 0, ez = 0;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    String s = br.readLine();
                    for (int k = 0; k < s.length(); k++) {
                        if (s.charAt(k) == ' ') break;
                        board[i][j][k] = s.charAt(k);
                        if (board[i][j][k] == 'S') {
                            sx = i;
                            sy = j;
                            sz = k;
                        }
                        if (board[i][j][k] == 'E') {
                            ex = i;
                            ey = j;
                            ez = k;
                        }
                    }
                }
                br.readLine();
            }

            bfs(sx, sy, sz, ex, ey, ez, board, visited, x, y, z);
        }
    }

    private static void bfs(int sx, int sy, int sz, int ex, int ey, int ez, char[][][] board, boolean[][][] visited, int n, int m, int k) {
        visited[sx][sy][sz] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, sz, 0));
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int z = q.peek().z;
            int dist = q.peek().dist;
            if (x == ex && y == ey && z == ez) {
                ans = dist;
                break;
            }
            q.poll();

            for (int i = 0; i < 4; i++) {
                int ny = y + gox[i], nz = z + goy[i];
                if (ny < 0 || ny >= m || nz < 0 || nz >= k || visited[x][ny][nz] || board[x][ny][nz] == '#') continue;
                visited[x][ny][nz] = true;
                q.add(new p(x, ny, nz, dist + 1));
            }
            for (int i = 4; i < 6; i++) {
                int nx = x + gox[i];
                if (nx < 0 || nx >= n || visited[nx][y][z] || board[nx][y][z] == '#') continue;
                visited[nx][y][z] = true;
                q.add(new p(nx, y, z, dist + 1));
            }
        }
        System.out.println(ans == 1e9 ? "Trapped!" : "Escaped in " + ans + " minute(s).");
    }

    private static class p {
        int x, y, z, dist;

        private p(int x, int y, int z, int dist) {
            this.x = x;
            this.y = y;
            this.z = z;
            this.dist = dist;
        }
    }

}
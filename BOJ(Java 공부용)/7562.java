import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {-1, -1, 1, 1, -2, -2, 2, 2};
    static int[] goy = {-2, 2, -2, 2, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            boolean[][] visited = new boolean[n][n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            int sx = Integer.parseInt(st.nextToken()), sy = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            int ex = Integer.parseInt(st.nextToken()), ey = Integer.parseInt(st.nextToken());
            bw.write(bfs(sx, sy, ex, ey, visited, n) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int bfs(int sx, int sy, int ex, int ey, boolean[][] visited, int n) {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy, 0));
        visited[sx][sy] = true;
        int temp = 0;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            q.poll();
            if (x == ex && y == ey) {
                temp = dist;
                break;
            }
            for (int i = 0; i < 8; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                q.add(new p(nx, ny, dist + 1));
                visited[nx][ny] = true;
            }
        }
        return temp;
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
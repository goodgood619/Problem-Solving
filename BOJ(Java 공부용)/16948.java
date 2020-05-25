import java.io.*;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {-2, -2, 0, 0, 2, 2};
    static int[] goy = {-1, 1, -2, 2, -1, 1};
    static long ans = (long) -1e18;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int r1 = Integer.parseInt(st.nextToken()), c1 = Integer.parseInt(st.nextToken()), r2 = Integer.parseInt(st.nextToken()), c2 = Integer.parseInt(st.nextToken());
        bw.write(bfs(r1, c1, r2, c2, n) + "");
        bw.flush();
        bw.close();
    }

    private static int bfs(int r1, int c1, int r2, int c2, int n) {
        Deque<P> q = new ArrayDeque<>();
        q.add(new P(r1, c1, 0));
        boolean[][] visited = new boolean[n][n];
        visited[r1][c1] = true;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            int dist = q.peek().dist;
            q.poll();
            if (x == r2 && y == c2) return dist;
            for (int i = 0; i < 6; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.add(new P(nx, ny, dist + 1));
            }
        }

        return -1;
    }
}

class P {
    int x, y, dist;

    P(int x, int y, int dist) {
        this.x = x;
        this.y = y;
        this.dist = dist;
    }
}
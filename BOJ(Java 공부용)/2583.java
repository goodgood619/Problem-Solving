import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        boolean[][] visited = new boolean[n][m];
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
            for (int j = a; j < c; j++) {
                for (int r = b; r < d; r++) {
                    visited[j][r] = true;
                }
            }
        }
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    v.add(bfs(i, j, visited, n, m));
                }
            }
        }
        Collections.sort(v);
        bw.write(v.size() + "\n");
        for (int i = 0; i < v.size(); i++) {
            bw.write(v.get(i) + " ");
        }
        bw.flush();
        bw.close();
    }

    private static int bfs(int sx, int sy, boolean[][] visited, int n, int m) {
        visited[sx][sy] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(sx, sy));
        int cnt = 1;
        while (!q.isEmpty()) {
            int x = q.peek().x;
            int y = q.peek().y;
            q.poll();
            for (int i = 0; i < 4; i++) {
                int nx = x + gox[i], ny = y + goy[i];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                visited[nx][ny] = true;
                q.add(new p(nx, ny));
                cnt++;
            }
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
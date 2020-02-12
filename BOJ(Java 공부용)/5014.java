import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int f = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken()), g = Integer.parseInt(st.nextToken()), u = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[f + 1];
        bfs(s, g, f, u, d, visited);
    }

    private static void bfs(int s, int g, int f, int u, int d, boolean[] visited) throws IOException {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(s, 0));
        visited[s] = true;
        int ans = (int) 1e9;
        while (!q.isEmpty()) {
            int here = q.peek().here;
            int dist = q.peek().dist;
            if (here == g) {
                ans = dist;
                break;
            }
            q.poll();
            int nx1 = here + u;
            int nx2 = here - d;
            if (nx1 <= f && !visited[nx1]) {
                visited[nx1] = true;
                q.add(new p(nx1, dist + 1));
            }
            if (nx2 >= 1 && !visited[nx2]) {
                visited[nx2] = true;
                q.add(new p(nx2, dist + 1));
            }
        }
        bw.write(ans == 1e9 ? "use the stairs" : ans + " ");
        bw.flush();
        bw.close();
    }

    private static class p {
        int here, dist;

        private p(int here, int dist) {
            this.here = here;
            this.dist = dist;
        }
    }
}
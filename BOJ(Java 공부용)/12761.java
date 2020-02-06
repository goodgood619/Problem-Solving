import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        bw.write(bfs(a, b, n, m) + " ");
        bw.flush();
        bw.close();
    }

    private static int bfs(int a, int b, int n, int m) {
        int ans = (int) 1e9;
        boolean[] visited = new boolean[100001];
        visited[n] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(n, 0));
        while (!q.isEmpty()) {
            int here = q.peek().here;
            int dist = q.peek().dist;
            if (here == m) {
                ans = min(ans, dist);
                break;
            }
            q.poll();
            int nx = here + 1, ny = here - 1, na = here + a, nb = here + b, mna = here - a, mnb = here - b, ga = here * a, gb = here * b;
            go(q, visited, nx, dist);
            go(q, visited, ny, dist);
            go(q, visited, na, dist);
            go(q, visited, nb, dist);
            go(q, visited, mna, dist);
            go(q, visited, mnb, dist);
            go(q, visited, ga, dist);
            go(q, visited, gb, dist);
        }
        return ans;
    }

    private static void go(ArrayDeque<p> q, boolean[] visited, int here, int dist) {
        if (here >= 0 && here <= 100000 && !visited[here]) {
            visited[here] = true;
            q.add(new p(here, dist + 1));
        }
    }

    private static class p {
        int here, dist;

        private p(int here, int dist) {
            this.here = here;
            this.dist = dist;
        }
    }
}
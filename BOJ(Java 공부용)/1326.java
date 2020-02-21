import java.io.*;
import java.util.ArrayDeque;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        boolean[] visited = new boolean[n+1];
        bw.write(bfs(start, end, visited, arr, n) + " ");
        bw.flush();
        bw.close();
    }

    private static int bfs(int start, int end, boolean[] visited, int[] arr, int n) {
        visited[start] = true;
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(start, 0));
        while (!q.isEmpty()) {
            int here = q.peek().here;
            int dist = q.peek().dist;
            q.poll();
            if (here == end) return dist;
            int jump = arr[here];
            for (int i = jump; here + i <= n; i += jump) {
                int next = here + i;
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(new p(next, dist + 1));
                }
            }
            for (int i = jump; here - i >= 1; i += jump) {
                int next = here - i;
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(new p(next, dist + 1));
                }
            }
        }

        return -1;
    }

    private static class p {
        int here, dist;

        private p(int here, int dist) {
            this.here = here;
            this.dist = dist;
        }
    }
}
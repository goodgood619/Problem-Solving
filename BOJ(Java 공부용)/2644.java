import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }
        System.out.println(bfs(start, end, graph, n));
    }

    private static int bfs(int start, int end, ArrayList<Integer>[] graph, int n) {
        ArrayDeque<p> q = new ArrayDeque<>();
        q.add(new p(start, 0));
        boolean[] visited = new boolean[n + 1];
        visited[start] = true;
        while (!q.isEmpty()) {
            int here = q.peek().here;
            int cnt = q.peek().cnt;
            q.poll();
            if (here == end) return cnt;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(new p(next, cnt + 1));
                }
            }
        }
        return -1;
    }

    private static class p {
        int here, cnt;

        private p(int here, int cnt) {
            this.here = here;
            this.cnt = cnt;
        }
    }
}
import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer>[] graph = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        boolean[] cycle = new boolean[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }
        go(1, -1, graph, visited, cycle);
        int[] dist = new int[n + 1];
        visited = new boolean[n + 1];
        Deque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            if (cycle[i]) {
                q.add(i);
                visited[i] = true;
            }
        }
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            for (Integer next : graph[here]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.add(next);
                    dist[next] = dist[here] + 1;
                }
            }
        }

        for (int i = 1; i <= n; i++) bw.write(dist[i] + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int here, int parent, List<Integer>[] graph, boolean[] visited, boolean[] cycle) {
        if (visited[here]) {
            return here;
        }
        visited[here] = true;
        for (Integer next : graph[here]) {
            if (next == parent) continue;
            int ret = go(next, here, graph, visited, cycle);
            if (ret == 1e9) return (int) 1e9;
            if (ret > 0) {
                cycle[here] = true;
                if (here == ret) return (int) 1e9;
                else return ret;
            }
        }
        return -1;
    }
}
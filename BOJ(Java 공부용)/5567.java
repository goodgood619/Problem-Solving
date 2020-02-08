import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int m = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }

        bfs(1, graph, visited, n);
    }

    private static void bfs(int start, ArrayList<Integer>[] graph, boolean[] visited, int n) throws IOException {
        int[] dist = new int[n + 1];
        ArrayDeque<Integer> q = new ArrayDeque<>();
        q.add(start);
        visited[start] = true;
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i);
                if (!visited[next]) {
                    visited[next] = true;
                    dist[next] = dist[here] + 1;
                    q.add(next);
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1 || dist[i] == 2) cnt++;
        }
        bw.write(cnt + "\n");
        bw.flush();
        bw.close();
    }
}
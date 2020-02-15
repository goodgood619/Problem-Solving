import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.StrictMath.abs;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static boolean ans = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());

        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            ArrayList<p> graph = new ArrayList<>();
            for (int i = 0; i < n + 2; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
                graph.add(new p(x, y));
            }
            ArrayList<Integer>[] real = new ArrayList[n + 2];
            boolean[] visited = new boolean[n + 2];
            for (int i = 0; i <= n + 1; i++) real[i] = new ArrayList<>();
            for (int i = 0; i < graph.size(); i++) {
                for (int j = i; j < graph.size(); j++) {
                    if (i == j) continue;
                    int dist = abs(graph.get(i).x - graph.get(j).x) + abs(graph.get(i).y - graph.get(j).y);
                    if (dist <= 1000) {
                        real[i].add(j);
                        real[j].add(i);
                    }
                }
            }
            ans = false;
            dfs(0, real, visited, n + 1);
            bw.write(ans ? "happy\n" : "sad\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<Integer>[] graph, boolean[] visited, int end) throws IOException {
        visited[here] = true;
        if (here == end) {
            ans = true;
            return;
        }
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) {
                dfs(next, graph, visited, end);
            }
        }
    }

    private static class p {
        int x, y;

        private p(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }
}
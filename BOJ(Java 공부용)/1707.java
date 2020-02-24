import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            int[] color = new int[n + 1];
            boolean[] visited = new boolean[n + 1];
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
                graph[here].add(next);
                graph[next].add(here);
            }

            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    dfs(i, 1, visited, graph, color);
                }
            }
            boolean no = false;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < graph[i].size(); j++) {
                    int next = graph[i].get(j);
                    if (color[next] == color[i]) {
                        no = true;
                        break;
                    }
                }
                if (no) break;
            }
            bw.write(no ? "NO\n" : "YES\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, int c, boolean[] visited, ArrayList<Integer>[] graph, int[] color) {
        visited[here] = true;
        color[here] = c;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) {
                dfs(next, 3 - c, visited, graph, color);
            }
        }
    }
}
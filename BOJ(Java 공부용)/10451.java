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
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            ArrayList<Integer>[] graph = new ArrayList[n + 1];
            boolean[] visited = new boolean[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
            for (int i = 1; i <= n; i++) {
                graph[i].add(Integer.parseInt(st.nextToken()));
            }
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                if (!visited[i]) {
                    dfs(i, graph, visited);
                    cnt++;
                }
            }
            bw.write(cnt + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<Integer>[] graph, boolean[] visited) {
        visited[here] = true;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) dfs(next, graph, visited);
        }
    }
}
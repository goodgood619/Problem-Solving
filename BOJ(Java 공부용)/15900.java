import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int total = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            graph[first].add(second);
            graph[second].add(first);
        }
        boolean[] visited = new boolean[n + 1];
        dfs(1, 0, graph, visited);
        if (total % 2 == 1) bw.write("Yes");
        else bw.write("No");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, int depth, List<Integer>[] graph, boolean[] visited) {
        int cnt = 0;
        visited[here] = true;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) {
                dfs(next, depth + 1, graph, visited);
                cnt++;
            }
        }
        if (cnt == 0) total += depth;
    }
}
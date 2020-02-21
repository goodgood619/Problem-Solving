import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            graph[second].add(first);
        }
        int[] arr = new int[n + 1];
        int max = 0;
        for (int i = 1; i <= n; i++) {
            boolean[] visited = new boolean[n + 1];
            if (!visited[i]) {
                int res = dfs(i, visited, graph);
                arr[i] = res;
                max = max(max, res);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (max == arr[i]) {
                bw.write(i + " ");
            }
        }
        bw.flush();
        bw.close();
    }

    private static int dfs(int here, boolean[] visited, ArrayList<Integer>[] graph) {
        visited[here] = true;
        int ret = 1;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) ret += dfs(next, visited, graph);
        }
        return ret;
    }
}
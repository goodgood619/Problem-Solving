import java.io.*;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        ArrayDeque<Integer> q = new ArrayDeque<>();
        int[] indegree = new int[n + 1];
        int[][] make = new int[n + 1][n + 1];
        int[][] dp = new int[n + 1][n + 1];
        boolean[] visited = new boolean[n + 1];
        int max = 0;
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int v = Integer.parseInt(st.nextToken()), u = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
            indegree[v]++;
            graph[u].add(v);
            make[v][u] = k;
        }
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                visited[i] = true;
                q.add(i);
                max = max(max, i);
            }
        }
        bfs(indegree, visited, max, dp, make, graph, q);
        for (int i = 1; i <= n; i++) {
            if (visited[i]) bw.write(i + " " + dp[n][i] + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void bfs(int[] indegree, boolean[] visited, int max, int[][] dp, int[][] make, ArrayList<Integer>[] graph, ArrayDeque<Integer> q) {
        while (!q.isEmpty()) {
            int here = q.peek();
            q.pop();
            for (int i = 0; i < graph[here].size(); i++) {
                int nhere = graph[here].get(i);
                indegree[nhere]--;
                if (indegree[nhere] == 0) {
                    q.add(nhere);
                }
                if (visited[here]) {
                    dp[nhere][here] += make[nhere][here];
                } else {
                    for (int j = 0; j < make[nhere][here]; j++) {
                        for (int k = 1; k <= max; k++) {
                            if (dp[here][k] == 0) continue;
                            else dp[nhere][k] += dp[here][k];
                        }
                    }
                }
            }
        }
    }
}
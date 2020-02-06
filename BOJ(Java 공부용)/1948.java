import java.io.*;
import java.util.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int cnt = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph1 = new ArrayList[n + 1];
        ArrayList<p>[] graph2 = new ArrayList[n + 1];
        int[] indegree = new int[n + 1];
        int[] backdegree = new int[n + 1];
        int[] dp = new int[n + 1];
        boolean[] visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) {
            graph1[i] = new ArrayList<>();
            graph2[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph1[here].add(new p(next, cost));
            graph2[next].add(new p(here, cost));
            indegree[next]++;
            backdegree[here]++;
        }
        st = new StringTokenizer(br.readLine());
        int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        ArrayDeque<Integer> q = new ArrayDeque<>();
        for (int i = 1; i <= n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        bfs(dp, indegree, graph1, q);
        bw.write(dp[end] + "\n");
        for (int i = 1; i <= n; i++) {
            if (backdegree[i] == 0) {
                q.add(i);
            }
        }
        dfs(end, graph2, dp, visited);
        bw.write(cnt + "\n");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<p>[] graph, int[] dp, boolean[] visited) {
        if(visited[here]) return;
        visited[here] = true;
        for (int i = 0; i < graph[here].size(); i++) {
            int back = graph[here].get(i).next;
            int backcost = graph[here].get(i).cost;
            if (dp[here] - backcost == dp[back]) {
                cnt++;
                dfs(back, graph, dp, visited);
            }
        }
    }

    private static void bfs(int[] dp, int[] indegree, ArrayList<p>[] graph, ArrayDeque<Integer> q) {
        while (!q.isEmpty()) {
            int here = q.peek();
            q.poll();
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                indegree[next]--;
                dp[next] = max(dp[next], dp[here] + nextcost);
                if (indegree[next] == 0) q.add(next);
            }
        }
    }

    private static class p {
        int next, cost;

        private p(int next, int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}
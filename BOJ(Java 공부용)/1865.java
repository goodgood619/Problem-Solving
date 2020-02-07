import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), w = Integer.parseInt(st.nextToken());
            ArrayList<p>[] graph = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
                graph[here].add(new p(next, cost));
                graph[next].add(new p(here, cost));
            }
            for (int i = 0; i < w; i++) {
                st = new StringTokenizer(br.readLine());
                int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
                graph[here].add(new p(next, -cost));
            }
            int[] dist = new int[n + 1];
            Arrays.fill(dist, (int) 1e9);
            dist[1] = 0;
            boolean cycle = false;
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 0; j < graph[i].size(); j++) {
                        int next = graph[i].get(j).next;
                        int nextcost = graph[i].get(j).cost;
                        if (dist[next] > dist[i] + nextcost && dist[i] != 1e9) {
                            dist[next] = dist[i] + nextcost;
                            if (k == n) cycle = true;
                        }
                    }
                }
            }
            bw.write(cycle ? "YES\n" : "NO\n");
        }
        bw.flush();
        bw.close();
    }

    private static class p {
        int next, cost;

        private p(int next, int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}
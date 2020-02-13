import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
            if (n == 0 && m == 0) break;
            ArrayList<p>[] graph = new ArrayList[n + 1];
            ArrayList<p>[] back = new ArrayList[n + 1];
            int[] dist = new int[n + 1];
            for (int i = 0; i <= n; i++) {
                graph[i] = new ArrayList<>();
                back[i] = new ArrayList<>();
            }
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(br.readLine());
                int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
                graph[here].add(new p(next, cost));
                back[next].add(new p(here, cost));
            }
            dijk(start, end, graph, dist);
            dfs(end, back, graph, dist);
            dijk(start, end, graph, dist);
            if (dist[end] == 1e9) bw.write("-1\n");
            else bw.write(dist[end] + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<p>[] back, ArrayList<p>[] graph, int[] dist) {
        for (int i = 0; i < back[here].size(); i++) {
            int b = back[here].get(i).next;
            int backcost = back[here].get(i).cost;
            if (dist[b] + backcost == dist[here]) {
                for (int j = 0; j < graph[b].size(); j++) {
                    int next = graph[b].get(j).next;
                    if (next == here) {
                        graph[b].set(j, new p(here, -1));
                        dfs(b, back, graph, dist);
                    }
                }
            }
        }
    }

    private static void dijk(int start, int end, ArrayList<p>[] graph, int[] dist) {
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.next < b.next) return -1;
                else if (a.next > b.next) return 1;
                else return 0;
            }
        });
        pq.add(new p(start, 0));
        Arrays.fill(dist, (int) 1e9);
        dist[start] = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (nextcost == -1) continue;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new p(next, dist[next]));
                }
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
import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, cost));
            graph[next].add(new p(here, cost));
        }
        st = new StringTokenizer(br.readLine());
        int via1 = Integer.parseInt(st.nextToken()), via2 = Integer.parseInt(st.nextToken());
        int ans = min(dijk(1, graph, n, via1) + dijk(via1, graph, n, via2) + dijk(via2, graph, n, n),
                dijk(1, graph, n, via2) + dijk(via2, graph, n, via1) + dijk(via1, graph, n, n));
        System.out.println(ans >= (int) 5e8 ? -1 : ans);
    }

    private static int dijk(int start, ArrayList<p>[] graph, int n, int end) {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, (int) 5e8);
        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else return 0;
            }
        });
        pq.add(new pp(start, 0));
        dist[start] = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new pp(next, dist[next]));
                }
            }
        }
        return dist[end];
    }

    private static class pp {
        int here, cost;

        private pp(int here, int cost) {
            this.here = here;
            this.cost = cost;
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
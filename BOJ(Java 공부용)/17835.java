import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        ArrayList<pp>[] graph = new ArrayList[n + 1];
        long[] dist = new long[n + 1];
        Arrays.fill(dist, Long.MAX_VALUE);
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[next].add(new pp(here, cost));
        }
        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else return 0;
            }
        });
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            int start = Integer.parseInt(st.nextToken());
            pq.add(new pp(start, 0));
            dist[start] = 0;
        }
        dijk(dist, pq, graph);
        long max = 0, idx = 0;
        for (int i = 1; i <= n; i++) {
            if (max < dist[i] && dist[i] != Long.MAX_VALUE) {
                max = dist[i];
                idx = i;
            }
        }
        System.out.println(idx + "\n" + max);
    }

    private static void dijk(long[] dist, PriorityQueue<pp> pq, ArrayList<pp>[] graph) {
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            long cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).here;
                long nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new pp(next, dist[next]));
                }
            }
        }
    }

    private static class pp {
        int here;
        long cost;

        private pp(int here, long cost) {
            this.here = here;
            this.cost = cost;
        }
    }

    private static class p {
        int here, next;

        private p(int here, int next) {
            this.here = here;
            this.next = next;
        }
    }
}
import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine()), m = Integer.parseInt(br.readLine());
        List<p>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        int[] route = new int[n + 1];
        int[] dist = new int[n + 1];
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, cost));
        }
        dijk(1, graph, route, dist);
        bw.write(dist[1] + "\n");
        List<Integer> v = new ArrayList<>();
        v.add(1);
        int p = route[1];
        while (p != 1) {
            v.add(p);
            p = route[p];
        }
        v.add(1);
        Collections.reverse(v);
        for (int i = 0; i < v.size(); i++) bw.write(v.get(i) + " ");
        bw.flush();
        bw.close();
    }

    private static void dijk(int st, List<p>[] graph, int[] route, int[] dist) {
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.next < b.next) return -1;
                else if (a.next > b.next) return 1;
                else return 0;
            }
        });
        pq.add(new p(st, 0));
        while (!pq.isEmpty()) {
            int here = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (dist[next] < dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    route[next] = here;
                    if (next != 1) pq.add(new p(next, dist[next]));
                }
            }
        }
    }

    static class p {
        int next, cost;

        private p(int next, int cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}
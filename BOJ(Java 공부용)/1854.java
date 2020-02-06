import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph = new ArrayList[n + 1];
        PriorityQueue<Integer>[] dist = new PriorityQueue[1001];
        for (int i = 0; i <= 1000; i++) dist[i] = new PriorityQueue<>(Collections.reverseOrder());
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, cost));
        }
        dijk(1, dist, graph, k);
        for (int i = 1; i <= n; i++) {
            if (dist[i].size() < k) bw.write("-1\n");
            else bw.write(dist[i].peek() + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static void dijk(int start, PriorityQueue<Integer>[] dist, ArrayList<p>[] graph, int k) {
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
        dist[start].add(0);
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here].peek()) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (dist[next].size() < k) {
                    dist[next].add(cost + nextcost);
                    pq.add(new pp(next, cost + nextcost));
                } else {
                    if (dist[next].peek() > cost + nextcost) {
                        dist[next].poll();
                        dist[next].add(cost + nextcost);
                        pq.add(new pp(next, cost + nextcost));
                    }
                }
            }
        }
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
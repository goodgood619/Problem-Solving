import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, 1));
            graph[next].add(new p(here, 1));
        }
        dijk(1, graph, n);
    }

    private static void dijk(int start, ArrayList<p>[] graph, int n) throws IOException {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, (int) 1e9);
        dist[start] = 0;
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else return 0;
            }
        });
        pq.add(new p(start, 0));
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).here, nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new p(next, dist[next]));
                }
            }
        }

        int max = 0, cnt = 0, min = (int) 1e9;
        for (int i = 1; i <= n; i++) {
            max = max(dist[i], max);
        }
        for (int i = 1; i <= n; i++) {
            if (max == dist[i]) {
                cnt++;
                min = min(min, i);
            }
        }
        bw.write(min + " " + max + " " + cnt + "\n");
        bw.flush();
        bw.close();
    }

    private static class p {
        int here, cost;

        private p(int here, int cost) {
            this.here = here;
            this.cost = cost;
        }
    }
}
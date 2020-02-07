import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken());
        int[] go = new int[n + 1];
        int[] back = new int[n + 1];
        ArrayList<p>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, cost));
        }
        for (int i = 1; i <= n; i++) {
            dijk(i, go, graph, n, end);
        }
        dijk2(end, back, graph, n);
        int max = 0;
        for (int i = 1; i <= n; i++) {
            max = max(max, go[i] + back[i]);
        }
        bw.write(max + " ");
        bw.flush();
        bw.close();
    }

    private static void dijk2(int start, int[] dist, ArrayList<p>[] graph, int n) {
        Arrays.fill(dist, (int) 1e9);
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
    }

    private static void dijk(int start, int[] dist, ArrayList<p>[] graph, int n, int end) {
        int[] temp = new int[n + 1];
        Arrays.fill(temp, (int) 1e9);
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
        temp[start] = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > temp[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (temp[next] > temp[here] + nextcost) {
                    temp[next] = temp[here] + nextcost;
                    pq.add(new pp(next, temp[next]));
                }
            }
        }
        dist[start] = temp[end];
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
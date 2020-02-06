import java.io.*;
import java.util.*;

import static java.lang.Long.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        ArrayList<p>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        long[] gas = new long[n + 1];
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= n; i++) {
            gas[i] = Long.parseLong(st.nextToken());
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            long cost = Long.parseLong(st.nextToken());
            graph[here].add(new p(next, cost));
            graph[next].add(new p(here, cost));
        }
        bw.write(dijk(1, graph, gas, n) + " ");
        bw.flush();
        bw.close();
    }

    private static long dijk(int h, ArrayList<p>[] graph, long[] gas, int n) {
        long[][] dist = new long[2501][2501];
        for (int i = 1; i <= 2500; i++) {
            for (int j = 1; j <= 2500; j++) {
                dist[i][j] = (long) 1e11;
            }
        }
        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    if (a.mingas < b.mingas) return -1;
                    else if (a.mingas > b.mingas) return 1;
                    else return 0;
                }
            }
        });

        pq.add(new pp(h, gas[h], 0));
        dist[h][(int) gas[h]]=0;
        long temp =0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            long mingas = pq.peek().mingas;
            long cost = pq.peek().cost;
            if (here == n) {
                temp = cost;
                break;
            }
            pq.poll();
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                long nextcost = graph[here].get(i).cost;
                if (dist[next][(int) min(mingas, gas[next])] > cost + mingas * nextcost) {
                    dist[next][(int) min(mingas, gas[next])] = cost + mingas * nextcost;
                    pq.add(new pp(next, min(mingas, gas[next]), cost + mingas * nextcost));
                }
            }
        }
        return temp;
    }

    private static class pp {
        int here;
        long mingas, cost;

        private pp(int here, long mingas, long cost) {
            this.here = here;
            this.mingas = mingas;
            this.cost = cost;
        }
    }

    private static class p {
        int next;
        long cost;

        private p(int next, long cost) {
            this.next = next;
            this.cost = cost;
        }
    }
}
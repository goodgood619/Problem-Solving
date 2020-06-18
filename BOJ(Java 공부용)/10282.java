import java.io.*;
import java.util.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int total = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), d = Integer.parseInt(st.nextToken()), c = Integer.parseInt(st.nextToken());
            List<P>[] graph = new ArrayList[n + 1];
            for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
            for (int i = 1; i <= d; i++) {
                st = new StringTokenizer(br.readLine());
                int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
                graph[second].add(new P(first, cost));
            }
            int[] dist = new int[n + 1];
            Arrays.fill(dist, (int) 1e9);
            int ret = dijk(c, graph, dist, n);
            int Max = 0;
            for (int i = 1; i <= n; i++) {
                if (dist[i] == 1e9) continue;
                Max = Math.max(Max, dist[i]);
            }
            bw.write(ret + " " + Max + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int dijk(int c, List<P>[] graph, int[] dist, int n) {
        dist[c] = 0;
        int cnt = 1;
        PriorityQueue<P> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                return Integer.compare(a.next, b.next);
            }
        });
        boolean[] visited = new boolean[n + 1];
        visited[c] = true;
        pq.add(new P(c, 0));
        while (!pq.isEmpty()) {
            int cost = pq.peek().cost;
            int here = pq.peek().next;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next, nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new P(next, dist[next]));
                }
                if (!visited[next]) {
                    visited[next] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
}

class P {
    int next, cost;

    P(int next, int cost) {
        this.next = next;
        this.cost = cost;
    }
}
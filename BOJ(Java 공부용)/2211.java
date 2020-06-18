import java.io.*;
import java.util.*;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int total = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        List<P>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[left].add(new P(right, cost));
            graph[right].add(new P(left, cost));
        }
        dijk(1, graph, n);

    }

    private static void dijk(int st, List<P>[] graph, int n) throws IOException {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, (int) 1e9);
        dist[st] = 0;
        PriorityQueue<PP> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    return Integer.compare(a.pre, b.pre);
                }
            }
        });
        List<P> ans = new ArrayList<>();
        pq.add(new PP(st, -1, 0));
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int pre = pq.peek().pre;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            if (pre != -1) ans.add(new P(here, pre));
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next, nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new PP(next, here, dist[next]));
                }
            }
        }
        bw.write(ans.size() + "\n");
        for (P e : ans) {
            bw.write(e.next + " " + e.cost + "\n");
        }
        bw.flush();
        bw.close();
    }
}

class P {
    int next, cost;

    P(int next, int cost) {
        this.next = next;
        this.cost = cost;
    }
}

class PP {
    int here, pre, cost;

    PP(int here, int pre, int cost) {
        this.here = here;
        this.pre = pre;
        this.cost = cost;
    }
}
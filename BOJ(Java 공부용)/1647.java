import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[] parent = new int[n + 1];
        PriorityQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    if (a.next < b.next) return -1;
                    else if (a.next > b.next) return 1;
                    else return 0;
                }
            }
        });
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            pq.add(new p(here, next, cost));
        }
        int ans = 0, max = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if (find(here, parent) != find(next, parent)) {
                union(here, next, parent);
                max = max(max, cost);
                ans += cost;
            }
        }
        bw.write((ans - max) + "\n");
        bw.flush();
        bw.close();
    }

    private static int find(int u, int[] parent) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }

    private static void union(int u, int v, int[] parent) {
        u = find(u, parent);
        v = find(v, parent);
        if (u == v) return;
        parent[u] = v;
    }

    private static class p {
        int here, next, cost;

        private p(int here, int next, int cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }
}
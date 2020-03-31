import java.io.*;
import java.util.AbstractQueue;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        AbstractQueue<P> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost > b.cost) return -1;
            else if (a.cost < b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    return Integer.compare(a.next, b.next);
                }
            }
        });

        int[] parent = new int[n + 1];
        int[] size = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        long total = 0, ans = 0;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            pq.add(new P(cost, here, next));
            total += cost;
        }

        while (!pq.isEmpty()) {
            int cost = pq.peek().cost;
            int here = pq.peek().here;
            int next = pq.peek().next;
            pq.poll();
            int first = find(here, parent);
            int second = find(next, parent);
            if (first != second) {
                ans += (((total * (long) size[first]) % 1e9) * (long) size[second]) % 1e9;
                union(here, next, parent, size);
            }
            if (ans >= 1e9) ans %= 1e9;
            total -= cost;
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static int find(int u, int[] parent) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }

    private static void union(int u, int v, int[] parent, int[] size) {
        int su = find(u, parent);
        int sv = find(v, parent);
        if (su == sv) return;
        parent[su] = sv;
        size[sv] += size[su];
        size[su] = 1;
    }
}

class P {
    int cost, here, next;

    P(int cost, int here, int next) {
        this.cost = cost;
        this.here = here;
        this.next = next;
    }
}
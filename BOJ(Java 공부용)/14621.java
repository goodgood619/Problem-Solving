import java.io.*;
import java.util.AbstractQueue;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] university = new int[n + 1];
        int[] parent = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            String s = st.nextToken();
            if (s.equals("W")) university[i] = 1;
            parent[i] = i;
        }
        AbstractQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else {
                    return Integer.compare(a.next, b.next);
                }
            }
        });
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            if (university[here] + university[next] == 1) {
                pq.add(new p(here, next, cost));
            }
        }

        int cnt = 0, ans = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().cost;
            pq.poll();
            if (find(here, parent) != find(next, parent)) {
                union(here, next, parent);
                cnt++;
                ans += cost;
            }
        }
        if (cnt != n - 1) bw.write("-1");
        else bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static int find(int u, int[] parent) {
        if (u == parent[u]) return u;
        return parent[u] = find(parent[u], parent);
    }

    private static void union(int u, int v, int[] parent) {
        u = parent[u];
        v = parent[v];
        if (u == v) return;
        parent[u] = v;
    }
}

class p {
    int here, next, cost;

    p(int here, int next, int cost) {
        this.here = here;
        this.next = next;
        this.cost = cost;
    }
}
import java.io.*;
import java.util.AbstractQueue;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), t = Integer.parseInt(st.nextToken()), cnt = 0;
        AbstractQueue<p> pq = new PriorityQueue<>((a, b) -> {
            if (a.dist < b.dist) return -1;
            else if (a.dist > b.dist) return 1;
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
        int[] parent = new int[n + 1];
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            pq.add(new p(here, next, cost));
        }
        int ans = 0;
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int next = pq.peek().next;
            int cost = pq.peek().dist;
            pq.poll();
            if (find(here, parent) != find(next, parent)) {
                union(here, next, parent);
                ans = ans + cost + t * cnt;
                cnt++;
            }
        }
        bw.write(ans + "");
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
}

class p {
    int here, next, dist;

    p(int here, int next, int dist) {
        this.here = here;
        this.next = next;
        this.dist = dist;
    }
}
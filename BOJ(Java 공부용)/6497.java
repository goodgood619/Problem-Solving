import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        while (true) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int m = Integer.parseInt(st.nextToken()), n = Integer.parseInt(st.nextToken()), sum = 0;
            if (n == 0 && m == 0) break;
            PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
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
            for (int i = 0; i < n; i++) {
                st = new StringTokenizer(br.readLine());
                int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
                pq.add(new pp(here, next, cost));
                sum += cost;
            }
            int[] parent = new int[m + 1];
            for (int i = 0; i <= m; i++) parent[i] = i;
            int ans = 0;
            while (!pq.isEmpty()) {
                int here = pq.peek().here;
                int next = pq.peek().next;
                double cost = pq.peek().cost;
                pq.poll();
                if (find(here, parent) != find(next, parent)) {
                    union(here, next, parent);
                    ans += cost;
                }
            }
            System.out.println(sum - ans);
        }
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

    private static class pp {
        int here, next, cost;

        private pp(int here, int next, int cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }
}
import java.io.*;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {1, -1, 0, 0};
    static int[] goy = {0, 0, -1, 1};
    static int ans = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        PriorityQueue<P> pq = new PriorityQueue<>((a, b) -> {
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
        st = new StringTokenizer(br.readLine());
        int[] parent = new int[n + 1];
        Arrays.fill(parent, 0);
        for (int i = 0; i < parent.length; i++) parent[i] = i;
        for (int i = 0; i < k; i++) {
            int start = Integer.parseInt(st.nextToken());
            parent[start] = -1;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            pq.add(new P(here, next, cost));
        }
        while (!pq.isEmpty()) {
            int here = pq.peek().here, next = pq.peek().next, cost = pq.peek().cost;
            int hereTop = find(here, parent);
            int nextTop = find(next, parent);
            pq.poll();
            if (hereTop != nextTop) {
                merge(parent, hereTop, nextTop);
                ans += cost;
            }
        }
        bw.write(ans + "");
        bw.flush();
        bw.close();
    }

    private static void merge(int[] parent, int hereTop, int nextTop) {
        if (hereTop == -1) parent[nextTop] = hereTop;
        else if (nextTop == -1) parent[hereTop] = nextTop;
        else {
            parent[nextTop] = hereTop;
        }
    }

    private static int find(int u, int[] parent) {
        if (parent[u] == -1) return -1;
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u], parent);
    }
}

class P {
    int here;
    int next;
    int cost;

    P(int here, int next, int cost) {
        this.cost = cost;
        this.here = here;
        this.next = next;
    }
}
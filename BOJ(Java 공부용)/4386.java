import java.io.*;
import java.util.*;

import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken()), y = Double.parseDouble(st.nextToken());
            arr[i].x = x;
            arr[i].y = y;
        }
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
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                double dist = sqrt((arr[i].x - arr[j].x) * (arr[i].x - arr[j].x) + (arr[i].y - arr[j].y) * (arr[i].y - arr[j].y));
                pq.add(new pp(i, j, dist));
            }
        }
        int[] parent = new int[arr.length];
        for (int i = 0; i < arr.length; i++) parent[i] = i;
        double ans = 0;
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
        System.out.print(String.format("%.2f", ans));
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
        int here, next;
        double cost;

        private pp(int here, int next, double cost) {
            this.here = here;
            this.next = next;
            this.cost = cost;
        }
    }

    private static class p {
        double x, y;

        private p(double x, double y) {
            this.x = x;
            this.y = y;
        }
    }
}
import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        HashMap<p, Integer> mindist = new HashMap<>();
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        long[] dist = new long[n + 1];
        Arrays.fill(dist, (long) 1e18);
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            p key = new p(next, here);
            if (mindist.get(key) == null) {
                mindist.put(key, cost);
            } else {
                if (mindist.get(key) >= cost) {
                    mindist.remove(key);
                    mindist.put(key, cost);
                }
            }
        }
        for (p p : mindist.keySet()) {
            int next = p.here, here = p.next;
            graph[next].add(here);
        }

        PriorityQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else return 0;
            }
        });
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < k; i++) {
            int start = Integer.parseInt(st.nextToken());
            pq.add(new pp(start, 0));
            dist[start] = 0;
        }
        dijk(dist, pq, graph, mindist);
        long max = 0, idx = 0;
        for (int i = 1; i <= n; i++) {
            if (max < dist[i]) {
                max = dist[i];
                idx = i;
            }
        }
        System.out.println(idx + "\n" + max);
    }

    private static void dijk(long[] dist, PriorityQueue<pp> pq, ArrayList<Integer>[] graph, HashMap<p, Integer> mindist) {
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            long cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i);
                p temp = new p(here, next);
                int nextcost = mindist.get(temp);
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new pp(next, dist[next]));
                }
            }
        }
    }

    private static class pp {
        int here;
        long cost;

        private pp(int here,long cost) {
            this.here = here;
            this.cost = cost;
        }
    }

    private static class p {
        int here, next;

        private p(int here, int next) {
            this.here = here;
            this.next = next;
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (o == null || getClass() != o.getClass()) return false;
            p p = (p) o;
            return here == p.here &&
                    next == p.next;
        }

        @Override
        public int hashCode() {
            return Objects.hash(here, next);
        }
    }
}
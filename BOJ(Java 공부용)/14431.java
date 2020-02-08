import java.io.*;
import java.util.*;
import static java.lang.StrictMath.sqrt;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int sx = Integer.parseInt(st.nextToken()), sy = Integer.parseInt(st.nextToken()), ex = Integer.parseInt(st.nextToken()), ey = Integer.parseInt(st.nextToken());
        boolean[] notprime = new boolean[8501];
        for (int i = 2; i <= sqrt(8500); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 8500; j += i) {
                notprime[j] = true;
            }
        }
        int n = Integer.parseInt(br.readLine());
        ArrayList<p>[] graph = new ArrayList[n + 3];
        for (int i = 0; i <= n + 2; i++) graph[i] = new ArrayList<>();
        ArrayList<pp> v = new ArrayList<>();
        v.add(new pp(sx, sy));
        v.add(new pp(ex, ey));
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(st.nextToken()), y = Integer.parseInt(st.nextToken());
            v.add(new pp(x, y));
        }
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                int dist = (int) sqrt((v.get(i).x - v.get(j).x) * (v.get(i).x - v.get(j).x) + (v.get(i).y - v.get(j).y) * (v.get(i).y - v.get(j).y));
                if (!notprime[dist]) {
                    graph[i].add(new p(j, dist));
                    graph[j].add(new p(i, dist));
                }
            }
        }

        dijk(0, 1, graph, n);
    }

    private static void dijk(int start, int end, ArrayList<p>[] graph, int n) {
        int[] dist = new int[n + 3];
        Arrays.fill(dist, (int) 1e9);
        dist[start] = 0;
        PriorityQueue<ppp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else {
                if (a.here < b.here) return -1;
                else if (a.here > b.here) return 1;
                else return 0;
            }
        });
        pq.add(new ppp(start, 0));
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (cost > dist[here]) continue;
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).next;
                int nextcost = graph[here].get(i).cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new ppp(next, dist[next]));
                }
            }
        }
        System.out.println(dist[end] == 1e9 ? "-1" : dist[end]);
    }

    private static class pp {
        int x, y;

        private pp(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    private static class ppp {
        int here, cost;

        private ppp(int here, int cost) {
            this.here = here;
            this.cost = cost;
        }
    }

    private static class p {
        int next, cost;

        private p(int next, int cost) {
            this.next = next;
            this.cost = cost;
        }
    }

}
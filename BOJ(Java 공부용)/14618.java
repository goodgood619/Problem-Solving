import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        List<p>[] graph = new ArrayList[n + 1];
        for (int i = 1; i <= n; i++) graph[i] = new ArrayList<>();
        int start = Integer.parseInt(br.readLine()), k = Integer.parseInt(br.readLine());
        st = new StringTokenizer(br.readLine());
        int[] check = new int[n + 1];
        for (int i = 1; i <= k; i++) {
            check[Integer.parseInt(st.nextToken())] = 1;
        }
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= k; i++) {
            check[Integer.parseInt(st.nextToken())] = 2;
        }
        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken()), cost = Integer.parseInt(st.nextToken());
            graph[here].add(new p(next, cost));
            graph[next].add(new p(here, cost));
        }
        dijk(start, graph, check, n);
    }

    private static void dijk(int start, List<p>[] graph, int[] check, int n) throws IOException {
        int[] dist = new int[n + 1];
        Arrays.fill(dist, (int) 1e9);
        dist[start] = 0;
        AbstractQueue<pp> pq = new PriorityQueue<>((a, b) -> {
            if (a.cost < b.cost) return -1;
            else if (a.cost > b.cost) return 1;
            else return Integer.compare(a.here, b.here);
        });
        pq.add(new pp(start, 0));
        while (!pq.isEmpty()) {
            int here = pq.peek().here;
            int cost = pq.peek().cost;
            pq.poll();
            if (dist[here] < cost) continue;
            for (p ele : graph[here]) {
                int next = ele.next;
                int nextcost = ele.cost;
                if (dist[next] > dist[here] + nextcost) {
                    dist[next] = dist[here] + nextcost;
                    pq.add(new pp(next, dist[next]));
                }
            }
        }

        int min = (int) 1e9;
        char c = '\n';
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9 || start == i || check[i] == 0) continue;
            else {
                if (min > dist[i]) {
                    min = dist[i];
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (min == 1e9 || check[i] == 0) continue;
            if (min == dist[i]) {
                if (c == 'A') continue;
                if (check[i] == 1) {
                    c = 'A';
                } else if (check[i] == 2) c = 'B';
            }
        }
        if (min == 1e9) {
            bw.write("-1");
        } else bw.write(c + "\n" + min + "");
        bw.flush();
        bw.close();
    }
}

class pp {
    int here, cost;

    pp(int here, int cost) {
        this.here = here;
        this.cost = cost;
    }
}

class p {
    int next, cost;

    p(int next, int cost) {
        this.next = next;
        this.cost = cost;
    }
}
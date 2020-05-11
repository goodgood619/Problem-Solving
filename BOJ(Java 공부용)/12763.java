import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int l = Integer.parseInt(br.readLine());
        List<P>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < l; i++) {
            st = new StringTokenizer(br.readLine());
            int start = Integer.parseInt(st.nextToken()), end = Integer.parseInt(st.nextToken()), time = Integer.parseInt(st.nextToken()), money = Integer.parseInt(st.nextToken());
            graph[start].add(new P(end, time, money));
            graph[end].add(new P(start, time, money));
        }
        bw.write(dijk(graph, t, m, n) + "");
        bw.flush();
        bw.close();
    }

    private static int dijk(List<P>[] graph, int t, int m, int n) {
        PriorityQueue<P> pq = new PriorityQueue<>((a, b) -> {
            if (a.money < b.money) return -1;
            else if (a.money > b.money) return 1;
            else {
                if (a.time < b.time) return -1;
                else if (a.time > b.time) return 1;
                else {
                    return Integer.compare(a.place, b.place);
                }
            }
        });
        pq.add(new P(1, t, 0));
        int[][] dist = new int[n + 1][t + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                dist[i][j] = (int) 1e9;
            }
        }
        dist[1][t] = 0;
        int ans = (int) 1e9;
        while (!pq.isEmpty()) {
            int here = pq.peek().place;
            int time = pq.peek().time;
            int curmoney = pq.peek().money;
            pq.poll();
            if (dist[here][time] < curmoney) continue;
            if (here == n) {
                if (curmoney <= m) {
                    ans = Math.min(ans, curmoney);
                    break;
                }
            }
            for (int i = 0; i < graph[here].size(); i++) {
                int next = graph[here].get(i).place;
                int nexttime = graph[here].get(i).time;
                int money = graph[here].get(i).money;
                if (time >= nexttime && dist[next][time - nexttime] > dist[here][time] + money) {
                    dist[next][time - nexttime] = dist[here][time] + money;
                    pq.add(new P(next, time - nexttime, dist[next][time - nexttime]));
                }
            }
        }
        if (ans == 1e9) return -1;
        return ans;
    }
}


class P {
    int place, time, money;

    P(int place, int time, int money) {
        this.place = place;
        this.time = time;
        this.money = money;
    }
}
import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int t = 0;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        List<Integer>[] graph = new ArrayList[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new ArrayList<>();
        }
        int[] dis = new int[n + 1];
        boolean[] cut = new boolean[n + 1];
        ArrayList<Integer> v = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }
        for (int i = 1; i <= n; i++) {
            if (dis[i] == 0) dfs(i, true, cut, dis, graph);
        }
        for (int i = 1; i <= n; i++) {
            if (cut[i]) v.add(i);
        }
        bw.write(v.size() + "\n");
        for (Integer e : v) {
            bw.write(e + " ");
        }
        bw.flush();
        bw.close();
    }

    private static int dfs(int here, boolean ok, boolean[] cut, int[] dis, List<Integer>[] graph) {
        dis[here] = ++t;
        int child = 0;
        int ret = dis[here];
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (dis[next] == 0) {
                child++;
                int r = dfs(next, false, cut, dis, graph);
                if (!ok && r >= dis[here]) {
                    cut[here] = true;
                }
                ret = min(ret, r);
            } else ret = min(ret, dis[next]);
        }
        if (ok && child >= 2) cut[here] = true;
        return ret;
    }
}
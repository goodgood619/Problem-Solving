import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        int[] depth = new int[n + 1];
        int[][] par = new int[n + 1][20];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), next = Integer.parseInt(st.nextToken());
            graph[here].add(next);
            graph[next].add(here);
        }
        dfs(1, 1, graph, depth, par);
        make(par, n);
        int m = Integer.parseInt(br.readLine());
        for (int i = 0; i < m; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
            bw.write(lca(a, b, depth, par) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int lca(int a, int b, int[] depth, int[][] par) {
        if (depth[a] < depth[b]) {
            int temp = a;
            a = b;
            b = temp;
        }
        int diff = depth[a] - depth[b];
        for (int i = 0; i <= 17; i++) {
            if ((diff & (1 << i)) != 0) {
                a = par[a][i];
            }
        }
        if (a == b) return a;
        for (int i = 17; i >= 0; i--) {
            if (par[a][i] != par[b][i]) {
                a = par[a][i];
                b = par[b][i];
            }
        }
        a = par[a][0];
        return a;
    }

    private static void make(int[][] par, int n) {
        for (int i = 1; i <= 17; i++) {
            for (int j = 1; j <= n; j++) {
                par[j][i] = par[par[j][i - 1]][i - 1];
            }
        }
    }

    private static void dfs(int here, int level, ArrayList<Integer>[] graph, int[] depth, int[][] par) {
        depth[here] = level;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (depth[next] != 0) continue;
            dfs(next, level + 1, graph, depth, par);
            par[next][0] = here;
        }
    }
}
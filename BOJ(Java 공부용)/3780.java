import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Math.abs;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int t = Integer.parseInt(st.nextToken());
        while (t-- > 0) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int[] parent = new int[n + 1];
            int[] cost = new int[n + 1];
            for (int i = 1; i <= n; i++) parent[i] = i;
            while (true) {
                st = new StringTokenizer(br.readLine());
                char c = st.nextToken().charAt(0);
                if (c == 'O') break;
                else if (c == 'I') {
                    int a = Integer.parseInt(st.nextToken()), b = Integer.parseInt(st.nextToken());
                    union(a, b, cost, parent);
                } else if (c == 'E') {
                    int here = Integer.parseInt(st.nextToken());
                    find(here, parent, cost);
                    bw.write(cost[here] + "\n");
                }
            }
        }
        bw.flush();
        bw.close();
    }

    private static void union(int u, int v, int[] cost, int[] parent) {
        cost[u] = abs(u - v) % 1000;
        parent[u] = v;
    }

    private static int find(int u, int[] parent, int[] cost) {
        if (u == parent[u]) return u;
        else {
            int temp = find(parent[u], parent, cost);
            cost[u] += cost[parent[u]];
            parent[u] = temp;
            return parent[u];
        }
    }
}
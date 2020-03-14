import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        p[] graph = new p[n + 1];
        List<Integer>[] pos = new ArrayList[n + 1];
        int[] cnt = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            graph[i] = new p(0, 0);
            pos[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int here = Integer.parseInt(st.nextToken()), left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
            graph[here].left = left;
            graph[here].right = right;
            if (left != -1) cnt[left]++;
            if (right != -1) cnt[right]++;
        }
        int root = -1;
        for (int i = 1; i <= n; i++) {
            if (cnt[i] == 0) {
                root = i;
                break;
            }
        }
        dfs(root, graph, 1, pos);
        int max = -1, maxdepth = 0;
        for (int i = 1; i <= n; i++) {
            if (pos[i].size() == 0) break;
            if (max < pos[i].get(pos[i].size() - 1) - pos[i].get(0) + 1) {
                max = pos[i].get(pos[i].size() - 1) - pos[i].get(0) + 1;
                maxdepth = i;
            }
        }
        bw.write(maxdepth + " " + max);
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, p[] graph, int depth, List<Integer>[] pos) {
        if (graph[here].left != -1) dfs(graph[here].left, graph, depth + 1, pos);
        pos[depth].add(counter++);
        if (graph[here].right != -1) dfs(graph[here].right, graph, depth + 1, pos);
    }

    static class p {
        int left, right;

        p(int left, int right) {
            this.left = left;
            this.right = right;
        }
    }
}
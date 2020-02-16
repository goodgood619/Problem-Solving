import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        HashMap<Integer, Integer> map = new HashMap<>();
        ArrayList<Integer> ans = new ArrayList<>();
        boolean[] visited = new boolean[n + 1];
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            int num = Integer.parseInt(br.readLine());
            graph[i].add(num);
        }

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, graph, visited, ans, map);
            }
        }
        Collections.sort(ans);
        bw.write(ans.size() + "\n");
        for (int i = 0; i < ans.size(); i++) bw.write(ans.get(i) + "\n");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<Integer>[] graph, boolean[] visited, ArrayList<Integer> ans, HashMap<Integer, Integer> map) {
        if (visited[here]) {
            if (map.get(here) == null) {
                map.put(here, 1);
                ans.add(here);
            }
            return;
        }
        visited[here] = true;
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            dfs(next, graph, visited, ans, map);
        }
        visited[here] = false;
    }
}
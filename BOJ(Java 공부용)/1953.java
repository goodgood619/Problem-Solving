import java.io.*;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer>[] graph = new ArrayList[n + 1];
        boolean[] visited = new boolean[n + 1];
        ArrayList<Integer> blue = new ArrayList<>();
        ArrayList<Integer> white = new ArrayList<>();
        for (int i = 0; i <= n; i++) graph[i] = new ArrayList<>();
        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int cnt = Integer.parseInt(st.nextToken());
            for (int j = 0; j < cnt; j++) {
                int next = Integer.parseInt(st.nextToken());
                graph[i].add(next);
            }
        }

        for (int i = 1; i <= n; i++) {
            boolean check = false;
            if (!visited[i]) {
                dfs(i, graph, visited, blue, white, check);
            }
        }
        Collections.sort(blue);
        Collections.sort(white);
        bw.write(blue.size() + "\n");
        for (int i = 0; i < blue.size(); i++) bw.write(blue.get(i) + " ");
        bw.write("\n");
        bw.write(white.size() + "\n");
        for (int i = 0; i < white.size(); i++) bw.write(white.get(i) + " ");
        bw.flush();
        bw.close();
    }

    private static void dfs(int here, ArrayList<Integer>[] graph, boolean[] visited, ArrayList<Integer> blue, ArrayList<Integer> white, boolean check) {
        visited[here] = true;
        if (!check) blue.add(here);
        else white.add(here);
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here].get(i);
            if (!visited[next]) {
                dfs(next, graph, visited, blue, white, !check);
            }
        }
    }

}